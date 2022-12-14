#include<iostream>
#include<vector>
#include<iterator>
#include<string>
#include<algorithm>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::string s;s.reserve(*std::istream_iterator<int>(std::cin));
	std::cin>>s;
	// possible values of the remaining character
	std::vector<char> prechs={s[0],s.back()};
	prechs.erase(std::unique(prechs.begin(),prechs.end()),prechs.end());
	int64_t ans=0;
	for(char c:prechs){
		auto c1=std::find_if(s.begin(),s.end(),[c](char d){return c!=d;})-s.begin();
		auto c2=std::find_if(s.rbegin(),s.rend(),[c](char d){return c!=d;})-s.rbegin();
		ans+=(c1+1)*(c2+1LL)-1;
	}
	std::cout<<(++ans)%998244353<<'\n';
}