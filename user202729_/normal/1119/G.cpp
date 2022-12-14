// Nice problem. The key idea is that (if you really want to know the solution, it's better to just read the editorial.
// The note it s just for myself. >.<)
// it's better to "group" the division (so there are more choices) than to try to "balance" it.
// Also, this problem took me a few days to solve (not to implement!), but that's just because I'm not
// completely focused and solve multiple problems at once. It's closer to IOI format to spend 2-3 consecutive hours.
// [I didn't read the editorial or see any failed test cases]
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,ngroup;std::cin>>n>>ngroup;
	std::vector<int> hpunit;
	for(int groupi=1;groupi<=ngroup;++groupi){
		int hp;std::cin>>hp;
		hpunit.insert(end(hpunit),hp,groupi);
	}

	std::cout<<(hpunit.size()+n-1)/n<<'\n';

	std::vector<int> splitp;splitp.reserve(ngroup);
	{
		std::vector<char> split(n);
		for(unsigned i=1;i<hpunit.size();++i)
			if(hpunit[i-1]!=hpunit[i])
				split[i%n]=true;
		split[0]=true;

		for(unsigned i=0;i<split.size();++i)
			if(split[i])
				splitp.push_back(i);

		// add some empty groups
		splitp.insert(begin(splitp),ngroup-splitp.size(),0);
	}

	for(int i=1;i<ngroup;++i)
		std::cout<<splitp[i]-splitp[i-1]<<' ';
	std::cout<<n-splitp.back()<<'\n';

	for(unsigned i=0;i<hpunit.size();i+=n){
		for(int p:splitp)
			std::cout<<(i+p>=hpunit.size() ? 1 : hpunit[i+p])<<' ';
		std::cout<<'\n';
	}
}