// <s>boring problem. Nothing to see here.</s>
// still WA (at least) once. :(
// weak sample test cases.
//
// ======
//
// will flow work correctly with negative edge values?

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>


struct Flow{
	struct edge{
		int x,res;
	};
	std::vector<edge> edges;

	std::vector<std::vector<int /* index into edges */ >> ad;
	Flow(int n):edges(),ad(n){}

	void addedge(int a,int b, int value){
		ad[a].push_back((int)edges.size());
		edges.push_back({b,value});
		ad[b].push_back((int)edges.size());
		edges.push_back({a,0});
	}

	std::vector<int> work;
	std::vector<int> layer;

	int sink;

	bool bfs(int s){
		layer.assign(ad.size(),-1);
		layer[s]=0;
		std::queue<int> q;
		q.push(s);
		while(!q.empty()){
			int x=q.front();q.pop();
			if(x==sink)
				return true;
			int const nextlay=layer[x]+1;
			for(int id:ad[x]){
				int y=edges[id].x;
				int res=edges[id].res;
				assert(res>=0);
				if(res!=0&&layer[y]<0){
					layer[y]=nextlay;
					q.push(y);
				}
			}
		}
		return false;
	}

	int dfs(int x,int maxf){
		if(x==sink)
			return maxf;
		for(int& workx=work[x];workx<(int)ad[x].size();++workx){
			int id=ad[x][workx];
			int y=edges[id].x;
			int& res=edges[id].res;
			if(layer[y]==layer[x]+1&&res){
				int f=dfs(y,std::min(maxf,res));
				if(f!=0){
					res-=f;
					assert(res>=0);
					edges[id^1].res+=f;
					return f;
				}
			}
		}
		return 0;
	}

	int flow(int source,int sink_){
		sink=sink_;
		assert(source!=sink);
		int ans=0;
		while(bfs(source)){
			work.clear();work.resize(ad.size());
			int f;
			while((f=dfs(source,INT_MAX)))
				ans+=f;
		}
		return ans;
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);

	struct item{
		int limit, count;
	}; // there are (count) numbers int range [1 .. limit]
	std::vector<item> items;

	int setSize, upperLimit, numHints;
	std::cin>>setSize>>upperLimit>>numHints;
	items.resize(numHints+1);
	items.back()={upperLimit,setSize};
	std::for_each(begin(items),end(items)-1,[&](auto& item){
		std::cin>>item.limit>>item.count;
	});

	std::sort(begin(items),end(items),[&](auto first, auto sec){return first.limit<sec.limit;});
	item last{0, 0};

	int const source=5, sink=6;
	Flow flow(7+(int)items.size());

	int node=7;
	for(auto const [right, count]: items){
		auto left=last.limit;
		auto segmentCount=count-last.count;
		// there are segmentCount numbers inthe range ]left .. right]
		assert(left<=right);
		if(segmentCount>right-left or segmentCount<0){
			std::cout<<"unfair\n";
			return 0;
		}

		flow.addedge(source, node, segmentCount);
		for(int index=0;index<5;++index)
			flow.addedge(node, index, (right+index)/5-(left+index)/5);
		
		last={right, count};
		++node;
	}

	assert(setSize%5==0);
	for(int index=0;index<5;++index)
		flow.addedge(index, sink, setSize/5);

	auto const value=flow.flow(source,sink);
	assert(value<=setSize);
	std::cout<<(value==setSize ? "fair\n": "unfair\n");
}