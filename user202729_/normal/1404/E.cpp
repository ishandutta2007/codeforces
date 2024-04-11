// not sure if this is fast enough.
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

struct Flow{
	private:
	struct edge{
		int x,residual;
	};
	std::vector<edge> edges;

	std::vector<std::vector<int /* index into edges */ >> add;

	std::vector<int> work;
	std::vector<int> layer;

	int sink;

	bool bfs(int s){
		layer.assign(add.size(),-1);
		layer[s]=0;
		std::queue<int> q;
		q.push(s);
		while(!q.empty()){
			int x=q.front();q.pop();
			if(x==sink)
				return true;
			int const nextlay=layer[x]+1;
			for(int id:add[x]){
				int y=edges[id].x;
				int residual=edges[id].residual;
				assert(residual>=0);
				if(residual!=0&&layer[y]<0){
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
		for(int& workx=work[x];workx<(int)add[x].size();++workx){
			int id=add[x][workx];
			int y=edges[id].x;
			int& residual=edges[id].residual;
			if(layer[y]==layer[x]+1&&residual){
				int f=dfs(y,std::min(maxf,residual));
				if(f!=0){
					residual-=f;
					assert(residual>=0);
					edges[id^1].residual+=f;
					return f;
				}
			}
		}
		return 0;
	}

	public:
	Flow(int n):edges(),add(n){}

	void addEdge(int a,int b, int capacity=1){
		add[a].push_back((int)edges.size());
		edges.push_back({b,capacity});
		add[b].push_back((int)edges.size());
		edges.push_back({a,0});
	}

	int flow(int source,int sink_){
		sink=sink_;
		assert(source!=sink);
		int ans=0;
		while(bfs(source)){
			work.clear();work.resize(add.size());
			int f;
			while((f=dfs(source,INT_MAX)))
				ans+=f;
		}
		return ans;
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	unsigned numRow, numCol; std::cin>>numRow>>numCol;
	std::vector<std::string> table(numRow);
	for(auto& row: table){
		row.reserve(numCol);
		std::cin>>row;
		assert(row.size()==numCol);
	}

	auto const source=numRow*numCol, sink=numRow*numCol+1;
	Flow flow(sink+1);
	auto const valid=[&](unsigned row, unsigned col)->bool{
		return row<numRow and col<numCol;
	};
	auto const black=[&](unsigned row, unsigned col)->bool{
		return table[row][col]=='#';
	};
	auto const encodeUnchecked=[&](unsigned row, unsigned col)->int{
		return row*numCol+col;
	};
	auto const encodeBlack=[&](unsigned row, unsigned col, int ifNotBlack)->int{
		return valid(row, col) and black(row, col) ? encodeUnchecked(row, col): ifNotBlack;
	};

	for(unsigned row=0; row<numRow; ++row)
	for(unsigned col=0; col<numCol; ++col) if(black(row, col)){
		// (horizontal: source half, vertical: sink half)
		// addEdge(A, B) -> if A horizontal and B vertical, add cost 1
		auto const cur=encodeUnchecked(row, col);
		flow.addEdge(cur, encodeBlack(row, col-1, sink));
		flow.addEdge(cur, encodeBlack(row, col+1, sink));
		flow.addEdge(encodeBlack(row+1, col, source), cur);
		flow.addEdge(encodeBlack(row-1, col, source), cur);
	}

	auto const tmp=flow.flow(source, sink);
	assert(tmp%2==0);
	std::cout<<tmp/2u<<'\n';
}