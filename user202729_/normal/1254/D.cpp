#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<algorithm>
#include<iostream>
#include<vector>

int const nlazyquery=200; // WHAT A SILLY BUG >.< NOTE: DO #error WHEN DEBUG
int const root=0;

int const MOD=998244353;
void add(int& a,int b){
	a+=b;if(a>=MOD)a-=MOD;
}
int constexpr mul(int a,int b){
	return a*(int64_t)b%MOD;
}
int powmod(int base,int exp){
	int result=1;
	while(true){
		if(exp&1)result=mul(result,base);
		if(0==(exp>>=1))return result;
		base=mul(base,base);
	}
}

int nnode;
int inv_nnode;

std::vector<std::vector<int>> ad;
std::vector<int> order;
std::vector<int> first,last; // pre-order
std::vector<std::vector<int>> child_first;
void dd(int x){
	first[x]=(int)order.size();
	order.push_back(x);
	child_first[x].reserve(ad[x].size());
	for(int y:ad[x]){
		ad[y].erase(std::find(begin(ad[y]),end(ad[y]),x));
		dd(y);
		child_first[x].push_back(first[y]);
	}
	last[x]=(int)order.size();
}

int branch(int x,int y){
	if(first[y]<first[x] or first[y]>=last[x])
		return -1;
	auto iter=--std::upper_bound(begin(child_first[x]),end(child_first[x]),first[y]);
	assert(iter!=end(child_first[x]));
	return int(iter-begin(child_first[x]));
}

struct query{int v,d;};
std::vector<query> pendquery;

std::vector<int> val;

std::vector<int> totalq,ps;
void process_pend_queries(){ // O(n + nlazyquery)
	totalq.assign(nnode,0);
	ps.assign(nnode,0); // ps[x] += 1  <->  val[y] += 1 for all y int subtree of x
	for(auto [v,d]:pendquery){
		add(totalq[v],d);
	}
	pendquery.clear();

	for(int x=0;x<nnode;++x)if(totalq[x]){
		int const d=totalq[x];

		int fac=int((int64_t)d*inv_nnode%MOD);

		for(auto br=ad[x].size();br--;){
			int y=ad[x][br];
			int stsize=last[y]-first[y];
			ps[y]=(ps[y]+int64_t(nnode-stsize)*fac)%MOD;
		}

		int stsize=nnode-(last[x]-first[x]);
		auto delta=int64_t(nnode-stsize)*fac;
		ps[root]=(ps[root]+delta)%MOD;
		ps[x]=(ps[x]+MOD*(int64_t)MOD-delta)%MOD;

		add(val[x],d);
	}

	assert(order.size()==(unsigned)nnode);
	for(auto x:order){
		add(val[x],ps[x]);
		for(auto y:ad[x]){
			add(ps[y],ps[x]);
		}
		// ps[x]=0;
	}
}

int get(int getnode){
	int ans =val[getnode];
	for(auto [v,d]:pendquery){
		if(v==getnode){
			add(ans,d);
		}else{
			int br=branch(v,getnode);
			int stsize;
			if(br<0)
				stsize=nnode-(last[v]-first[v]);
			else{
				int y=ad[v][br];
				stsize=last[y]-first[y];
			}
			ans=(ans+int64_t(nnode-stsize)*d%MOD*inv_nnode)%MOD;
		}
	}
	return ans;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nquery;std::cin>>nnode>>nquery;
	inv_nnode=powmod(nnode,MOD-2);

	ad.resize(nnode);
	for(int z=nnode,u,v;--z;){
		std::cin>>u>>v;
		ad[--u].push_back(--v);
		ad[v].push_back(u);
	}

	first.resize(nnode);
	last.resize(nnode);
	order.reserve(nnode);
	child_first.resize(nnode);
	dd(root);

	val.resize(nnode);

	while(nquery--){
		char type;std::cin>>type;
		if(type=='1'){ // sum complexity: nquery/nlazyquery * nnode
			int v,d;std::cin>>v>>d;
			pendquery.push_back({--v,d});
			if(pendquery.size()>=nlazyquery){
				process_pend_queries();
			}
		}else{ // sum complexity: nquery * nlazyquery * log(nnode)
			int v;std::cin>>v;
			std::cout<<get(--v)<<'\n';
		}
	}
}