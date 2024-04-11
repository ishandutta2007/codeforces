// time-limit: 3000
// problem-url: https://codeforces.com/contest/1586/problem/E



#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>
#include<variant>
// { ==== Begin library Dsu.h ====
template<class Data, class F, bool path_compression, bool union_by_rank, class ActualClass> struct Dsu__{

	void beforeChange(int /*node*/){}  // CRTP-virtual function, called before data[node] is changed



	struct Node{
		Data data;
		int par; //  0: have par, -1: is root, < -1: is root and have large rank and UNION_BY_RANK
	};
	std::vector<Node> data;
	F merge_function;

	Dsu__(F merge_function): data(), merge_function(merge_function) {}

	void reset(int n, auto starting_data /* (index)  Data */){
		data.clear(); data.reserve(n);
		for(int i=0; i<n; ++i){
			if(data.size()>=data.capacity()) __builtin_unreachable();
			data.push_back({i, starting_data(i)});
		}
	}

	void reset(int n){
		data.assign(n, Node{Data {}, -1});
	}

	bool isRoot(int node) const{return data[node].par<0;}

	int root(int node)
//#if not PATH_COMPRESSION
//		const
//#endif
	{
		if(isRoot(node)
				) return node;
		if constexpr(path_compression){
			((ActualClass*) this)->beforeChange(node);
			return 
				data[node].par= root(data[node].par);
		}else{
			return 
				root(data[node].par);
		}
	}

	auto join(int a, int b){
		struct Result{
			bool joined;
			int newRoot;
			Data* data;
		};

		a=root(a); b=root(b);

		if(a==b) return Result{false, b, &data[b].data};

		if(union_by_rank){
			if(data[a].par<data[b].par) std::swap(a, b);
			else if(data[a].par==data[b].par) --data[b].par;
		}

		beforeChange(a);
		data[a].par=b;
		if(not std::is_same_v<std::monostate, Data>){
			((ActualClass*) this)->beforeChange(b);
			data[b].data=merge_function(
					data[b].data,
					data[a].data,
					b,
					a);
		}

		return Result{true, b, &data[b].data};
	}
};

template<class Data, class F, bool path_compression, bool union_by_rank> struct Dsu_:
	Dsu__<Data, F, path_compression, union_by_rank, Dsu_<Data, F, path_compression, union_by_rank>> {
	using Base=Dsu__<Data, F, path_compression, union_by_rank, Dsu_<Data, F, path_compression, union_by_rank>>;
	using Base::Base;
};

// public interface ========

// merge_function: used to merge data. On merge, called with
// (Data data_b, Data data_a, int b, int a)  Data
// where b is the new root

// create a Dsu. Call with specified signature and template parameters.
template<
		class Data, // must be provided
		bool path_compression=true, bool union_by_rank=true, // optional

		class _F // auto deduced
		>
	Dsu_<Data, _F, path_compression, union_by_rank>
	Dsu(_F merge_function){ return {merge_function}; }

// create a "normal" Dsu.
template<bool path_compression=true, bool union_by_rank=true>
auto Dsu(){
	return Dsu<std::monostate, path_compression, union_by_rank>(
			[](std::monostate, std::monostate, int, int){return std::monostate {};}
			);
}

// } ==== End library Dsu.h ====
std::vector<std::vector<int>> add;

struct Info{int height, par;};
std::vector<Info> info;

// does not remove par edge and does fill info
void work(int node, int par, int height){
	info[node]={height, par};
	for(auto child: add[node]) if(child!=par){
		work(child, node, height+1);
	}
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numNode; std::cin>>numNode;
	int numEdge; std::cin>>numEdge;
	add.resize(numNode);
	auto d=Dsu();
	d.reset(numNode);
	for(int _=0; _<numEdge; ++_){
		int x; std::cin>>x; --x;
		int y; std::cin>>y; --y;
		if(d.join(x, y).joined){
			add[x].push_back(y);
			add[y].push_back(x);
		}
	}

	int numQuery; std::cin>>numQuery;
	std::vector<std::array<int, 2>> queries(numQuery);
	std::vector<char> degree(numNode);
	for(auto& [x, y]: queries){
		std::cin>>x; --x;
		std::cin>>y; --y;
		degree[x]^=1; degree[y]^=1;
	}

	auto sum=std::accumulate(begin(degree), end(degree), 0);
	if(sum){
		assert(sum%2==0);
		std::cout<<"NO\n"<<sum/2u<<'\n';
	}else{
		info.resize(numNode);
		work(0, -1, 0);

		std::cout<<"YES\n";
		for(auto[x, y]: queries){
			std::vector<int> path{x}, back{y};
			if(info[x].height>info[y].height) for(int _=info[x].height-info[y].height; _--;) path.push_back(info[path.back()].par);
			if(info[y].height>info[x].height) for(int _=info[y].height-info[x].height; _--;) back.push_back(info[back.back()].par);
			while(path.back()!=back.back()){
				path.push_back(info[path.back()].par);
				back.push_back(info[back.back()].par);
			}
			back.pop_back();

			std::cout<<path.size()+back.size()<<'\n';
			for(auto x: path) std::cout<<x+1<<' ';
			for(int i=(int)back.size(); i--;) std::cout<<back[i]+1<<' ';
			std::cout<<'\n';
		}
	}
}