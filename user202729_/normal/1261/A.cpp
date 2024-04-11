/*
I feel that contests recently are (on average) easier than contests from a few years ago.
(Of course, there are some hard ones), with favor users with fast implementation speed
and not necessary those with good problem solving skill, while problem solving skill is more
important in IOI. However, despite that, (my implementation speed is not very fast, but
it's still better than my problem-solving skill, or at least I think so) I still cannot get a
good place in recent Codeforces contest...
*/
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int ntest;std::cin>>ntest;

	std::string s;s.reserve(2000);
	std::vector<std::pair<int,int>> ops;

	while(ntest--){
		int n,k;std::cin>>n>>k;
		std::cin>>s;
		ops.clear();
		for(int i=0;i<n;i+=2){
			if(s[i]==')'){
				auto j=int(std::find(begin(s)+i,end(s),'(')-begin(s));
				ops.push_back({i,j});
				std::swap(s[i],s[j]);
			}else if(s[i+1]!=')'){
				auto j=int(std::find(begin(s)+i+2,end(s),')')-begin(s));
				ops.push_back({i+1,j});
				std::swap(s[i+1],s[j]);
			}
			assert(s[i]=='(');
			assert(s[i+1]==')');
		}
		assert((int)ops.size()<=n/2);
		assert((int)ops.size()<n);
		
		if(k<n/2)
			ops.push_back({1,2*(n/2-k)});

		std::cout<<ops.size()<<'\n';
		for(auto [x,y]:ops)
			std::cout<<x+1<<' '<<y+1<<'\n';
	}
}