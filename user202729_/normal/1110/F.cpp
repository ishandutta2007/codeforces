#define NDEBUG

#include<iostream>
#include<vector>
#include<array>
#include<limits>
#include<algorithm>
#include<cassert>

template<class T>
struct dynamic_rmq{
	struct node{
		T lazy,min_nolazy;
		T get_min(){
			return min_nolazy+lazy;
		}
	};
	std::vector<node> data;

	dynamic_rmq(){}
	void reset(int n){data.clear();data.resize(2*n);}

	void add_range(int l,int r,T delta){
		if(l==r||delta==0)
			return;

		l+=data.size()/2;
		r+=data.size()/2;
		assert(l<data.size());
		assert(r<=data.size());

		int l0=l,r0=r;
		while(l<r){
			if(l&1) data[l++].lazy+=delta;
			if(r&1) data[--r].lazy+=delta;
			l>>=1;r>>=1;
		}
		for(int z:std::array<int,2>{{l0,r0-1}}){
			while(z!=1){
				z>>=1;
				data[z].min_nolazy=std::min(
						data[z<<1].get_min(),data[z<<1|1].get_min());
			}
		}
	}
	T min_range(int l,int r){
		l+=data.size()/2;
		r+=data.size()/2;
		for(int z:std::array<int,2>{{l,r-1}}){
			for(int i=31^__builtin_clz(z);i;--i){
				int n=z>>i;
				T l=data[n].lazy;
				data[n].min_nolazy+=l;
				data[n<<1].lazy+=l;
				data[n<<1|1].lazy+=l;
				data[n].lazy=0;
			}
		}
		T ans=std::numeric_limits<T>::max();
		while(l<r){
			if(l&1) ans=std::min(ans,data[l++].get_min());
			if(r&1) ans=std::min(ans,data[--r].get_min());
			l>>=1;r>>=1;
		}
		return ans;
	}
};

struct edge{
	int child;
	int64_t weight;
};
std::vector<std::vector<edge>> adjl;
std::vector<int64_t> answer;

struct node_query{
	int index;
	int l,r; // [l..r[
};
std::vector<std::vector<node_query>> node_queries;
dynamic_rmq<int64_t> dist_to;

int nnode;
std::vector<int> dfs_first,dfs_last;

void solve(int node){
	for(node_query nq:node_queries[node]){
		assert(nq.l<nnode);
		assert(nq.r<=nnode);
		answer[nq.index]=dist_to.min_range(nq.l,nq.r);
	}

	for(edge e:adjl[node]){
		dist_to.add_range(0,dfs_first[e.child],+e.weight);
		dist_to.add_range(dfs_first[e.child],dfs_last[e.child],-e.weight);
		dist_to.add_range(dfs_last[e.child],nnode,+e.weight);
		solve(e.child);
		dist_to.add_range(0,dfs_first[e.child],-e.weight);
		dist_to.add_range(dfs_first[e.child],dfs_last[e.child],+e.weight);
		dist_to.add_range(dfs_last[e.child],nnode,-e.weight);
	}
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nquery;std::cin>>nnode>>nquery;
	dist_to.reset(nnode);
	adjl.resize(nnode);
	for(int i=1;i<nnode;++i){
		int p,weight;std::cin>>p>>weight;
		adjl[--p].push_back({i,weight});
		dist_to.add_range(i,i+1,weight+dist_to.min_range(p,p+1));
	}

	node_queries.resize(nnode);
	for(int i=0;i<nquery;++i){
		int v,l,r;std::cin>>v>>l>>r;
		--v;--l;
		node_queries[v].push_back({i,l,r});
	}

	dfs_first.resize(nnode);
	dfs_last.resize(nnode);
	for(int i=nnode;i-->0;){
		if(adjl[i].empty()){
			dfs_first[i]=i;
			dfs_last[i]=i+1;
		}else{
			dfs_first[i]=dfs_first[adjl[i][0].child];
			dfs_last[i]=dfs_last[adjl[i].back().child];
			dist_to.add_range(i,i+1,(int64_t)1e16); // not a leaf, ignore this
		}
	}

	answer.assign(nquery,-1);
	solve(0);
	for(auto x:answer)
		std::cout<<x<<'\n';
}