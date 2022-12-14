// https://codeforces.com/problemset/problem/1140/F
#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif

#include<iostream>
#include<vector>
#include<cassert>
#include<unordered_map>

int constexpr NXVAL=300000,NYVAL=300000;

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nquery;std::cin>>nquery;
	struct edge{
		int x,y;
		bool operator==(edge e)const{
			return x==e.x&&y==e.y;
		}
	};
	struct edge_hash{
		std::size_t operator()(edge e)const{
			return e.x*(std::size_t)1000000007+e.y;
		}
	};
	/*
	struct query{
		edge e;
		bool add;
	};
	*/

	// std::vector<query> queries(nquery);

	struct DSU{ // union by rank without path compression
		struct item{
			int d;
			bool isroot()const{return d<0;}
			int parent()const{
				assert(!isroot());
				return d;
			}
			int rank()const{
				assert(isroot());
				return -d;
			}

			int ls,rs;
			int64_t val()const{
				assert(isroot());
				return (int64_t)ls*rs;
			}
		};
		std::vector<item> d;
		int64_t val; // sum val of items in d

		private:
		struct backupitem{
			int index;
			item x;
		};
		std::vector<backupitem> backup;
		void setitem(int i,item x){
			backup.push_back({i,d[i]});
			d[i]=x;
		}

		public:
		struct state{
			unsigned backup_size;
			int64_t val;
		};
		state getstate()const{
			return {(unsigned)backup.size(),val};
		}

		void reset(){
			d.assign(NXVAL,{-1,1,0});
			d.resize(NXVAL+NYVAL,{-1,0,1});
			val=0;
		}

		void restore(state s){
			while(backup.size()>s.backup_size){
				auto z=backup.back();
				backup.pop_back();
				d[z.index]=z.x;
			}
			assert(backup.size()==s.backup_size);
			val=s.val;
		}

		int root(int u){
			return d[u].isroot()?u:root(d[u].parent());
		}

		void join(int u,int v){
			u=root(u);v=root(v);
			if(u==v)return;
			if(d[u].rank()<d[v].rank())
				std::swap(u,v);
			item new_du{d[u].d, d[u].ls+d[v].ls,d[u].rs+d[v].rs};
			if(d[u].rank()==d[v].rank())
				--new_du.d; // increase new rank
			val+=new_du.val()-d[u].val()-d[v].val();

			setitem(u,new_du);
			setitem(v,{u,0,0});

			/*
			{ // consistency check
				int x=val;
				for(item i:d)
					if(i.isroot())
						x-=i.val();
				assert(x==0);
			}
			*/
		}
	};

	struct ST{
		std::vector<std::vector<edge>> t; // node -> list of edge cover the node
		ST(int n):t(2*n){}
		void add(int l,int r,edge e){
			l+=int(t.size()/2);r+=int(t.size()/2);
			while(l!=r){
				if(l&1)t[l++].push_back(e);
				if(r&1)t[--r].push_back(e);
				l>>=1;r>>=1;
			}
		}

		std::vector<int64_t> ans;
		DSU d;
		void solve(int i){
			DSU::state oldstate=d.getstate();
			for(edge e:t[i])
				d.join(e.x,e.y);
			if((unsigned)i>=t.size()/2){
				ans[i-t.size()/2]=d.val;
			}else{
				solve(i<<1);
				solve(i<<1|1);
			}
			d.restore(oldstate);
		}

		void solveall(){
			d.reset();
			ans.resize(t.size()/2);
			solve(1);
		}
	};

	ST tree(nquery);
	{
		std::unordered_map<edge,int,edge_hash> es;
		for(int i=0;i<nquery;++i){
			edge e;
			std::cin>>e.x>>e.y;
			--e.x;--e.y;
			e.y+=NXVAL;
			auto iter=es.find(e);
			if(iter!=es.end()){
				tree.add(iter->second,i,e);
				es.erase(iter);
			}else{
				es.insert({e,i});
			}
		}
		for(auto edge_starti:es)
			tree.add(edge_starti.second,nquery,edge_starti.first);
	}

	tree.solveall();
	for(auto x:tree.ans)
		std::cout<<x<<' ';
	std::cout<<'\n';
}