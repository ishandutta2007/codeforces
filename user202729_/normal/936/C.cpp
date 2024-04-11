#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif
#include<cassert>

#include<iostream>
#include<vector>
#include<array>
#include<algorithm>
#include<cstdlib>

#ifdef Sublime
#include <iostream>
#include <sstream>
#define cin cin__
namespace std{std::stringstream cin(R"(
10
abcdefghij
jabcdefghi
)");}
#endif // Sublime

std::string s,t;
std::vector<int> ops;
void shift(int len){
	ops.push_back(len);
	std::reverse(s.end()-len,s.end());
	std::rotate(s.begin(),s.end()-len,s.end());
}

int main(){
	std::ios_base::sync_with_stdio(false);std::cin.tie(nullptr);
	int n;std::cin>>n;
	s.reserve(n);t.reserve(n);
	std::cin>>s>>t;

	std::array<int,'z'+1>cnt{};
	for(char c:s)++cnt[c];
	for(char c:t)--cnt[c];
	if(std::any_of(cnt.begin(),cnt.end(),[](int x){return x!=0;})){
		std::cout<<"-1\n";
		return 0;
	}

	int plen=0; // done prefix length
	while(plen<n){
		if(s[plen]==t[plen]){
			++plen;
			continue;
		}

		char cx=t[plen],cy=t[plen+1];
		int px=s.find(cx,plen);
		int py=s.find(cy,cx==cy?px+1:plen);

		assert(px>=plen);assert(py>=plen);
		assert(px!=py);

		int constexpr x=1,y=1;
		int const
			l=std::min(px,py)-plen,
			m=std::abs(px-py)-1,
			h=n-std::max(px,py)-1;

		assert(plen+l+x+m+y+h==n);

		if(px<py){
			shift(x+m+y+h);
			shift(m+x+plen+l);
			shift(m+h+y);
			shift(x);
			shift(plen);
		}else{
			shift(x+h);
			shift(l+y+m);
			shift(l+h+x+plen);
			shift(x+h+l+m+y);
			shift(x+plen);
		}

		assert(s[plen]==t[plen]);++plen;
		assert(s[plen]==t[plen]);++plen;
	}

	std::cout<<ops.size()<<'\n';
	for(int x:ops)std::cout<<x<<' ';
	std::cout<<'\n';
}