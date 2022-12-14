#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	struct rectset{ int64_t w,h,c; };
	std::vector<rectset> rs(n);
	std::vector<int64_t> wvals,hvals;
	wvals.reserve(n); hvals.reserve(n);

	for(auto& [w,h,c]:rs){
		std::cin>>w>>h>>c;
		wvals.push_back(w);
		hvals.push_back(h);
	}
	for(auto xp:{&wvals,&hvals}){
		auto& x=*xp;
		std::sort(begin(x),end(x));
		x.erase(std::unique(begin(x),end(x)),end(x));
	}

	if(wvals.size()*(int64_t)hvals.size()!=n){ // forgetting int64_t here is only wrong on 32 bit machines
no_solution:
		std::cout<<"0\n";
		return 0;
	}
	std::vector<std::vector<int64_t>> mat(hvals.size(),std::vector<int64_t>(wvals.size()));
	auto const ind =[](auto const& a,auto b){
		auto iter=std::lower_bound(begin(a),end(a),b);
		assert(b==*iter);
		return int(iter-begin(a));
	};
	for(auto [w,h,c]:rs){
		mat[ind(hvals,h)][ind(wvals,w)]=c;
		assert(c>0);
	}

	for(auto const& row:mat) assert(std::none_of(begin(row),end(row),[](auto x){return x==0;}));

	std::vector<int64_t> wub(wvals.size()); // upper bound of w-count (inthe divisibility lattice)
	std::vector<int64_t> hub(hvals.size());

	// hcnt[i] * wcnt[j] = mat[i][j]

	for(int i=0;i<hvals.size();++i)
	for(int j=0;j<wvals.size();++j){
		wub[j]=std::gcd(wub[j],mat[i][j]);
		hub[i]=std::gcd(hub[i],mat[i][j]);
	}

	std::vector<int64_t> wlb(wvals.size(),1),hlb(hvals.size(),1);
	for(int i=0;i<hvals.size();++i)
	for(int j=0;j<wvals.size();++j){
		assert(0==mat[i][j]%hub[i]);
		assert(0==mat[i][j]%wub[j]);
		wlb[j]=std::lcm(wlb[j],mat[i][j]/hub[i]);
		hlb[i]=std::lcm(hlb[i],mat[i][j]/wub[j]);
	}

	for(int i=0;i<hvals.size();++i)
		if(hub[i]%hlb[i]!=0) goto no_solution;
	for(int j=0;j<wvals.size();++j)
		if(wub[j]%wlb[j]!=0) goto no_solution;

	int64_t mat_val=-1;

	for(int i=0;i<hvals.size();++i)
	for(int j=0;j<wvals.size();++j){
		if(mat[i][j]%hlb[i]!=0) goto no_solution;
		mat[i][j]/=hlb[i];
		if(mat[i][j]%wlb[j]!=0) goto no_solution;
		mat[i][j]/=wlb[j];
	}

	for(int i=0;i<hvals.size();++i)
	for(int j=0;j<wvals.size();++j){ // NOTE merge loops is probably more efficient
		if(mat_val<0) mat_val=mat[i][j];
		else assert(mat_val==mat[i][j]);
	}

	assert(mat_val>=0);
	int out=0;
	for(int x=1;x*(int64_t)x<=mat_val;++x){
		if(x*(int64_t)x==mat_val) ++out;
		else if(mat_val%x==0) out+=2;
	}
	std::cout<<out<<'\n';
	// complex implementation, bug prone...
}