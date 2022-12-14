// [I didn't read the editorial or see any failed test cases]
// NOTE spoiler below.
// initially I misread the problem statement and thought that the "min" is actually "max"
// so I try to optimize the O(n^5) solution to O(n^4) or lower, but failed.
// With the problem like this, it can be solved with my initial approach (flow).
//
// This implementation is suboptimal (a n/log(n) factor can be optimized away)

#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<vector>
#include<algorithm>
#include<iostream>
#include<queue>
#include<climits>

struct Flow{
	struct edge{
		int x,res;
	};
	std::vector<edge> edges;

	std::vector<std::vector<int /* index into edges */ >> ad;
	Flow(int n):edges(),ad(n){}

	void addedge(int a,int b,int cap){
		ad[a].push_back((int)edges.size());
		edges.push_back({b,cap});
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
	int n,nrect;std::cin>>n>>nrect;
	if(nrect==0){
		std::cout<<"0\n";
		return 0;
	}
	struct rect{
		int x1,y1,x2,y2;
	};

	std::vector<rect> rs(nrect);
	std::vector<int> xs,ys;
	xs.reserve(2*nrect);
	ys.reserve(2*nrect);
	for(auto& [x1,y1,x2,y2]:rs){
		std::cin>>x1>>y1>>x2>>y2;
		--x1;--y1;
		xs.push_back(x1);xs.push_back(x2);
		ys.push_back(y1);ys.push_back(y2);
	}

	std::sort(begin(xs),end(xs)); xs.erase(std::unique(begin(xs),end(xs)),end(xs));
	std::sort(begin(ys),end(ys)); ys.erase(std::unique(begin(ys),end(ys)),end(ys));

	int const source=0,sink=1;
	int const xbase=sink+1;
	int const ybase=xbase+int(xs.size()-1);
	int const rbase=ybase+int(ys.size()-1);
	Flow f(rbase+nrect);

	for(int ri=nrect;ri--;){
		auto [x1,y1,x2,y2]=rs[ri];
		x1=std::lower_bound(begin(xs),end(xs),x1)-begin(xs);
		x2=std::lower_bound(begin(xs),end(xs),x2)-begin(xs);
		y1=std::lower_bound(begin(ys),end(ys),y1)-begin(ys);
		y2=std::lower_bound(begin(ys),end(ys),y2)-begin(ys);
		for(int x=x1;x<x2;++x)
			f.addedge(xbase+x,rbase+ri,n);
		for(int y=y1;y<y2;++y)
			f.addedge(rbase+ri,ybase+y,n);
	}
	for(int x=0;x<int(xs.size()-1);++x) f.addedge(source,xbase+x,xs[x+1]-xs[x]);
	for(int y=0;y<int(ys.size()-1);++y) f.addedge(ybase+y,sink,ys[y+1]-ys[y]);

	std::cout<<f.flow(source,sink)<<'\n';
}