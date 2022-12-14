// is this fast & not-memory-consuming enough?
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

struct Edge{
	int node, index;
};
std::vector<std::vector<Edge>> add;


#define MODULAR_LESS_EFFICIENT_BUT_EASIER_TO_CODE 1
int const MOD=1000000007;

struct modular {
	int val;
	explicit constexpr operator int() const { return val; }
	constexpr modular():val(){}
#if MODULAR_LESS_EFFICIENT_BUT_EASIER_TO_CODE
	constexpr modular(auto v):val(int(v%MOD)){ if(val<0)val+=MOD; }
#else
	constexpr modular(int v):val(v){
		assert(0<=v and v<MOD);
	}
#endif

#define COMPAREOP(OP) bool constexpr operator OP(modular b) const { return val OP b.val; }
	COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>) COMPAREOP(<=) COMPAREOP(>=)
#undef COMPAREOP

	friend modular constexpr operator-(modular x) { x.val=x.val?MOD-x.val:0; return x; }
	modular constexpr& operator+=(modular m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
	modular constexpr& operator-=(modular m) { if ((val -= m.val) < 0) val += MOD; return *this; }
	modular constexpr& operator*=(modular m) {
		val = int((int64_t)val*m.val%MOD);
		return *this;
	}
	modular constexpr pow(int p) const {
		modular a=*this;
		modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	modular constexpr inv() const {
		int a=val,b=MOD, ax=1,bx=0;
		while(b){
			int q=a/b, t=a%b;
			a=b; b=t;
			t=ax-bx*q; ax=bx; bx=t;
		}
		assert(a==1);
		if(ax<0)ax+=MOD;
		return ax;
	}
	modular constexpr& operator/=(modular m) { return (*this) *= m.inv(); }

#define ARITHBINARYOP(OP) friend modular constexpr operator OP(modular a, modular b) { return a OP##= b; }
	ARITHBINARYOP(+) ARITHBINARYOP(-) ARITHBINARYOP(*) ARITHBINARYOP(/)
#undef ARITHBINARYOP
};

struct Trie{
	std::vector<std::array<int, 10>> child; // -1: none
	std::vector<std::array<int, 20>> jump; // -1: none
	std::vector<int> depth;

	Trie(): child(1), jump(1), depth(1){
		std::fill(begin(child[0]),end(child[0]), -1);
		std::fill(begin(jump[0]),end(jump[0]), -1);
	}

	int newChild(int node, int direction){
		if(node==0) assert(direction!=0);

		auto& it=child[node][direction];
		if(it>=0) return it;
		auto const result=it=(int)child.size();
		assert(it==(int)jump.size());
		assert(it==(int)depth.size());

		depth.push_back(depth[node]+1);

		child.emplace_back();
		std::fill(begin(child.back()),end(child.back()), -1);
		jump.emplace_back();
		auto last=jump.back()[0]=node;
		for(int layer=1;layer<(int)jump.back().size();++layer){
			if(last==-1){
				std::fill(layer+begin(jump.back()), end(jump.back()), -1);
				break;
			}
			last=jump.back()[layer]=jump[last][layer-1];
		}
		return result;
	}

	struct lca_result {
		int u1,v1,lca; // u1,v1: child of lca int the direction of u/v resp.
	};

	lca_result lca(int u,int v)const{
		assert(u!=v);

		bool swapped;
		if((swapped=(depth[u]<depth[v])))std::swap(u,v);

		int ddepth=depth[u]-depth[v];
		if(ddepth){
			--ddepth;
			for(;ddepth;ddepth^=ddepth&-ddepth){
				u=jump[u][__builtin_ctz(ddepth)];
			}
			assert(depth[u]-1==depth[v]);
			if(jump[u][0]==v)return {u,u,v};
			assert(u!=-1 and v!=-1 and jump[u][0]!=-1);
			u=jump[u][0];
			assert(u!=-1 and v!=-1);
		}
		assert(u!=v);
		assert(u!=-1 and v!=-1);
		for(auto layer=jump[u].size();layer--;){
			if(jump[u][layer]!=jump[v][layer])
				std::tie(u,v)=std::make_pair(jump[u][layer],jump[v][layer]);
		}
		assert(jump[u][0]==jump[v][0]);
		if(swapped)std::swap(u,v);
		assert(u!=v);
		return {u,v,jump[u][0]};
	}

	bool less(int first, int sec)const{
		if(first==sec) return false;
		if(depth[first]!=depth[sec]) return depth[first]<depth[sec];

		auto [firstDirection, secDirection, lca_]=lca(first, sec);
		assert(firstDirection!=secDirection);
		for(auto it: child[lca_]){
			if(it==firstDirection) return true;
			if(it==secDirection) return false;
		}
		assert(false); __builtin_unreachable();
	}

	/*
	std::string stringOf(int node)const{
		if(node==0) return {};
		auto par=jump[node][0];
		auto const direction=std::find(begin(child[par]),end(child[par]), node)-begin(child[par]);
		assert(direction<=9);
		return stringOf(par)+=char(direction+'0');
	}

	static bool assertLessStringEqual(std::string first, std::string sec, bool result){
		assert(result==(
					std::pair{first.length(), first}<std::pair{sec.length(), sec}
					));
		return true;
	}

	bool less(int first, int sec)const{
		auto result=less_(first, sec);
		assert(assertLessStringEqual(stringOf(first), stringOf(sec), result));
		if(first!=sec){
			assert(std::cerr<<first<<' '<<sec<<' '<<result<<'\n');
		}
		return result;
	}
	*/


	std::vector<modular> computeNodeValue() const{
		std::vector<modular> result((int)child.size());
		assert(result[0]==0);
		for(int node=0;node<(int)child.size();++node) 
			for(int direction=0;direction<(int)child[node].size();++direction) 
				if(auto it=child[node][direction]; it>=0){
					assert(result[it]==0);
					result[it]=result[node]*10+direction;
				}
		return result;
	}

};

Trie trie;
/*
struct TrieCompare{ bool operator()(int first, int sec)const{
	return trie.less(first, sec);
} };
*/

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numNode, numEdge; std::cin>>numNode>>numEdge;
	add.resize(numNode);
	for(int edgeIndex=1;edgeIndex<=numEdge;++edgeIndex) {
		int first, sec; std::cin>>first>>sec;
		--first;--sec;
		add[first].push_back({sec, edgeIndex});
		add[sec].push_back({first, edgeIndex});
	}


	struct Item{
		int node;
		int value; // node in trie
		bool operator<(Item other) const{
			return trie.less(other.value, value);
		}
	};
	std::vector<int> distance(numNode, -1);
	std::priority_queue<Item> queue;
	queue.push({0, distance[0]=0});
	while(not queue.empty()){
		auto [node, value]=queue.top(); queue.pop();
		if(value!=distance[node]){
			assert(trie.less(distance[node], value));
			continue;
		}
		for(auto [other, edgeIndex]: add[node]){
			auto edge=std::to_string(edgeIndex);
			auto newValue=std::accumulate(begin(edge),end(edge), value,[&](auto value, char digit){
				return trie.newChild(value, digit-'0');
			});
			if(distance[other]<0 or trie.less(newValue, distance[other]))
				queue.push({other, distance[other]=newValue});
		}
	}

	auto nodeValue=trie.computeNodeValue();
	std::for_each(1+begin(distance),end(distance),[&](int trieNode){
		std::cout<<(int)nodeValue[trieNode]<<'\n';
	});
}