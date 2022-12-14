// I had to lookup some information online... (which is not possible during some on-site contest)
// :(
//
// # of spanning tree: (sum(d))**(ncomp-2) * product d
// (NOTE: ncomp==1 ==> d**-1 * d = 1)
// PIE: res[i] = sum l>=i ((l choose i )*(-1)**(l-i) * total[l])
// l: ncomp=n-l, total[l] = sum {mask} ( sum(d)**(n-l-2) * product(d) ) = n**(n-l-2) * sum {mask} product(d)
//
// ==> (unfortunately I could not fig this out during the virt contest) DP knapsack.
//
// Debug:
// I had to write a test generator. Instead of writing a brute force program I shuffle the vertices order
// (change the root vertex) and assert that the output is the same.
// Adding assert(newmemnode[child_nsubcomp+old_nsubcomp+1].empty()); reveals the bug.
// Lesson:
// <s>Don't trade ease of implementation for performance when necessary</s>
// Add assertions when there is any assumptions in the code.

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

std::vector<std::vector<int>> ad;
std::vector<int> postorder;

void dd(int node){
	for(int child:ad[node]){
		ad[child].erase(
				std::find(begin(ad[child]),end(ad[child]),node)
				);
		dd(child);
	}
	postorder.push_back(node);
}


#define MODULAR_LESS_EFFICIENT_BUT_EASIER_TO_CODE 1
int const MOD=1000000007;
struct modular {
	int val;
	explicit constexpr operator int() const { return val; }
	constexpr modular():val(){}
#if MODULAR_LESS_EFFICIENT_BUT_EASIER_TO_CODE
	constexpr modular(int64_t v):val(int(v%MOD)){
		if(val<0)val+=MOD;
	}
#else
	constexpr modular(int v):val(v){
		assert(0<=v and v<MOD);
	}
#endif

#define COMPAREOP(OP) bool constexpr operator OP(modular b) const { return val OP b.val; }
	COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>) COMPAREOP(<=) COMPAREOP(>=)
#undef COMPAREOP

	modular operator-() const { return modular(val ? MOD-val : 0); }
	modular constexpr& operator+=(modular m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
	modular constexpr& operator-=(modular m) { if ((val -= m.val) < 0) val += MOD; return *this; }
	modular constexpr& operator*=(modular m) { val = int((int64_t)val*m.val%MOD); return *this; }
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

std::vector<std::vector<std::vector<modular>>> mem;
// [node][nsubcomp][cursize] = sum of product (excluding cursize)

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nnode;std::cin>>nnode;
	ad.resize(nnode);
	for(int z=nnode,u,v;--z;){
		std::cin>>u>>v;
		ad[--u].push_back(--v);
		ad[v].push_back(u);
	}

	postorder.reserve(nnode);
	dd(0);
	assert((int)postorder.size()==nnode);

	mem.resize(nnode);
	for(auto node:postorder){
		auto& memnode=mem[node]; // [nsubcomp][cursize] = sum of product (excluding cursize)
		memnode.resize(1);
		memnode[0].resize(2);
		memnode[0][1]=1;

		for(auto child:ad[node]){
			auto newmemnode=std::vector<std::vector<modular>>(memnode.size()+mem[child].size());

			for(int child_nsubcomp=0;child_nsubcomp<(int)mem[child].size();++child_nsubcomp)
			for(int old_nsubcomp=0;old_nsubcomp<(int)memnode.size();++old_nsubcomp){

				newmemnode[child_nsubcomp+old_nsubcomp].resize(
						std::max(
							newmemnode[child_nsubcomp+old_nsubcomp].size(),
							mem[child][child_nsubcomp].size()+memnode[old_nsubcomp].size()
						));
				newmemnode[child_nsubcomp+old_nsubcomp+1].resize(
						std::max(
							newmemnode[child_nsubcomp+old_nsubcomp+1].size(),
							memnode[old_nsubcomp].size()
						));

				for(int child_cursize=0;child_cursize<(int)mem[child][child_nsubcomp].size();++child_cursize)
				for(int old_cursize=0;old_cursize<(int)memnode[old_nsubcomp].size();++old_cursize){
					auto cur_value=memnode[old_nsubcomp][old_cursize]*
						mem[child][child_nsubcomp][child_cursize];
					if(cur_value!=0){
						newmemnode[child_nsubcomp+old_nsubcomp][child_cursize+old_cursize]+=cur_value;
						newmemnode[child_nsubcomp+old_nsubcomp+1][old_cursize]+=cur_value*child_cursize;
					}
				}
			}

			memnode=std::move(newmemnode);
		}
	}
	// TODO consider move the mem calculation into DFS function
	// NOTE mem[x] has size = sts[x]**2
	// therefore total complexity = (I think it's n^3 or n^4? n^5 will definitely fail)

	std::vector<modular> total(nnode);
	for(int nsubcomp=0;nsubcomp<(int)mem[0].size();++nsubcomp){
		int const ncomp=nsubcomp+1;
		int const l=nnode-ncomp;

		for(int cursize=0;cursize<(int)mem[0][nsubcomp].size();++cursize){
			total[l]+=mem[0][nsubcomp][cursize]*cursize;
		}

		if(nnode-l-2<0){
			assert(nnode-l-2==-1);
			assert(total[l]==nnode);
			total[l]=1;
		}else{
			total[l]*=modular(nnode).pow(nnode-l-2);
		}
	}

	std::vector<modular> fact(nnode+1);
	fact[0]=1; for(unsigned i=1;i<fact.size();++i) fact[i]=fact[i-1]*i;
	auto const binom=[&](int n,int k){ return fact[n]/(fact[k]*fact[n-k]); };

	std::vector<modular> res(nnode);
	for(int i=0;i<nnode;++i)
		for(int l=i;l<nnode;++l){
			if((l-i)&1)
				res[i]-=binom(l,i)*total[l];
			else
				res[i]+=binom(l,i)*total[l];
		}

	for(auto x:res) std::cout<<(int)x<<' ';
	std::cout<<'\n';
}