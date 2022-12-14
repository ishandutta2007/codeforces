// time-limit: 2000
// problem-url: https://codeforces.com/contest/1586/problem/C

#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numRow; std::cin>>numRow;
	int numCol; std::cin>>numCol;
	std::string last; std::cin>>last;
	std::string cur;

	std::vector<int> mark(numCol-1); // mark[col]: any subtable contains both col and col+1 returns false

	for(int _=0; _<numRow-1; ++_){
		std::cin>>cur;
		for(int col=1; col<numCol; ++col)
			if(cur[col-1]=='X' and last[col]=='X')
				mark[col-1]=true;
		std::swap(last, cur);
	}

	// change mark to prev (previous index, inclusive such that mark is set)
	{
		int prev=-1;
		for(int i=0; i<(int)mark.size(); ++i){
			if(mark[i]) prev=i;
			mark[i]=prev;
		}
	}
	
	auto prev=std::move(mark); // <-- like this
	int numQuery; std::cin>>numQuery;
	for(int _=0; _<numQuery; ++_){
		int left; std::cin>>left; --left;
		int right; std::cin>>right;
		std::cout<<(right-left>1 and prev[right-2]>=left ? "NO\n": "YES\n");
	}

}