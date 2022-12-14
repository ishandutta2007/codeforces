/*
 * {Some deleted comments}
 *
 * 107 is a main (or challenge) test case...
 */
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

auto minfactor=[]{
	std::vector<int> minfactor(5001);
	//std::vector<int> primes;
	//std::vector<int> primeindex(minfactor.size());
	for(unsigned i=2;i<minfactor.size();++i)if(0==minfactor[i]){
		minfactor[i]=i;
		//primeindex[i]=(int)primes.size();
		//primes.push_back(i);
		for(unsigned j=i*i;j<minfactor.size();j+=i)
			if(minfactor[j]==0)
				minfactor[j]=i;
	}
	return minfactor;
	//return std::make_tuple(std::move(minfactor),std::move(primes));
	//return std::make_tuple(std::move(minfactor),std::move(primes),std::move(primeindex));
}();

/*
auto [minfactorindex,primes]=[]{
	std::vector<int> minfactorindex(5001,-1);
	std::vector<int> primes;
	for(unsigned i=2;i<minfactorindex.size();++i)if(minfactorindex[i]<0){
		minfactorindex[i]=(int)primes.size();
		for(unsigned j=i*i;j<minfactorindex.size();j+=i)
			if(minfactorindex[j]<0)
				minfactorindex[j]=(int)primes.size();
		primes.push_back(i);
	}
	return std::make_tuple(std::move(minfactorindex),std::move(primes));
}();
*/

/*
struct InfInt:std::vector<int>{
	using super=std::vector<int>; // exp
	using super::super;

	InfInt():super(primes.size()){}
	auto& operator*=(int a){
		assert(a!=0);
		while(a>1){
			++(*this)[minfactorindex[a]];
			a/=primes[minfactorindex[a]];
		}
		return *this;
	}
	InfInt(int a):super(primes.size()){ *this*=a; }
};
*/

struct edge{ int x,len; };
std::vector<std::vector<edge>> ad;


auto addedge(int a,int b,int len){
	assert(len>0);
	ad[a].push_back({b,len});
	ad[b].push_back({a,len});
}

std::vector<int64_t> cost;

void dd(int node,int weight,int par=-1,int64_t disttoroot=0){
	cost[node]+=weight*disttoroot;
	for(auto [child,len]:ad[node]) if(child!=par)
		dd(child,weight,node,disttoroot+len);
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);

	std::vector<int> cnt(5000); // node x: (x+1)!
	int n;std::cin>>n;
	for(int z=n;z--;){
		int k;std::cin>>k;
		++cnt[std::max(0,k-1)];
	}

	while(cnt.back()==0) cnt.pop_back();
	// TODO benchmark how slow it is without this
	if(n==cnt.back()){ std::cout<<"0\n"; return 0; }

	struct item{ int node; std::vector<int> facts; };
	std::vector<item> nodes;

	std::vector<int> a; // list of prime factors of (i+1)! in decreasing order
	int i=0;
	while(1){
		nodes.push_back({i,a});

		++i;
		if(i==(int)cnt.size()) break;
		auto old_a_size=a.size();
		for(int x=i+1;x>1;x/=minfactor[x]){
			a.push_back(minfactor[x]);
		}
		std::reverse(begin(a)+old_a_size,end(a));
		std::inplace_merge(begin(a),begin(a)+old_a_size,end(a),std::greater{});
	}
	std::sort(begin(nodes),end(nodes),[](auto const& x,auto const& y){ return x.facts<y.facts; });

	auto const commonprefix=[](auto const& a,auto const& b){
		unsigned i=0;
		for(auto maxi=std::min(a.size(),b.size());i<maxi;++i)
			if(a[i]!=b[i]) break;
		return i;
	};
	auto const isprefix=[](auto const& a,auto const& b){
		return a.size()<=b.size() and std::equal(begin(a),end(a),begin(b));
	};

	for(auto x=nodes.size();--x;){
		auto const& facts1=nodes[x-1].facts;
		auto const& facts2=nodes[x].facts;
		assert(facts1<facts2);

		auto i=commonprefix(facts1,facts2);
		if(i==facts1.size()) continue;
		nodes.push_back({-1,std::vector<int>(begin(facts1),begin(facts1)+i)});
	}

	std::sort(begin(nodes),end(nodes),[](auto const& x,auto const& y){
		return x.facts!=y.facts ? x.facts>y.facts : x.node>y.node /* node >= 0 before -1 */;
	});
	nodes.erase(
			std::unique(begin(nodes),end(nodes),[](auto const& x,auto const& y){ return x.facts==y.facts; }),
			end(nodes));

	ad.resize(cnt.size());
	for(auto& [n,_]:nodes)
		if(n<0){
			n=(int)ad.size();
			ad.emplace_back();
		}

	std::vector stack{std::move(nodes.back())};
	nodes.pop_back();
	while(not nodes.empty()){
		auto i=std::move(nodes.back());
		nodes.pop_back();
		while(not isprefix(stack.back().facts,i.facts))
			stack.pop_back();
		addedge(stack.back().node, i.node, int(i.facts.size()-stack.back().facts.size()));
		stack.push_back(std::move(i));
	}

	cost.resize(ad.size());
	for(unsigned i=0;i<cnt.size();++i)
		if(cnt[i])
			dd(i,cnt[i]);

	std::cout<<*std::min_element(begin(cost),end(cost))<<'\n';
}