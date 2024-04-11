// Being very fast at implementing easy problems doesn't help at the IOI.
// Even the easy problems at IOI are hard.
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<algorithm>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::vector<int64_t> s(n);for(auto& si:s)std::cin>>si;
	std::sort(begin(s),end(s));
#define n _

	std::vector<int64_t> gaps;
	gaps.reserve(s.size()-1);
	for(auto i=s.size();--i;)
		gaps.push_back(s[i]-s[i-1]);
	assert(gaps.size()==s.size()-1);
	std::sort(begin(gaps),end(gaps));

	std::vector<int64_t> vals(s.size()); // vals[i] = function value at slope change gaps[i-1]
	vals[0]=0;
	for(unsigned i=0;i<gaps.size();++i)
		vals[i+1]=vals[i]+(s.size()-i)*(gaps[i]-(i ? gaps[i-1] : 0));

	int nq;std::cin>>nq;
	while(nq--){
		int64_t l,r;std::cin>>l>>r;
		int64_t nval=r-l+1;
		auto i=int(std::lower_bound(begin(gaps),end(gaps),nval)-begin(gaps));
		assert(i==0 or gaps[i-1]<=nval);
		assert(i==(int)gaps.size() or nval<=gaps[i]);

		std::cout<<vals[i]+(s.size()-i)*(nval-(i ? gaps[i-1] : 0))<<' ';
	}
	std::cout<<'\n';

}