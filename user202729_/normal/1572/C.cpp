// time-limit: 1000
// problem-url: https://codeforces.com/contest/1572/problem/C

// ~~intuition~~ guess, not proven

#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

void up(){
	int number; std::cin>>number;
	std::vector<int> a(number);
	for(auto& it: a) {
		std::cin>>it;
		//--it;
	}
	a.erase(std::unique(begin(a), end(a)), end(a));
	number=-1;
	
	std::vector<std::vector<int>> indices(
			*std::max_element(begin(a), end(a))+1
			);
	for(int i=0; i<(int)a.size(); ++i)
		indices[a[i]].push_back(i);

	std::vector<std::vector<int>> f(a.size()+1, std::vector<int>(a.size()+1));
	for(int right=0; right<=(int)a.size(); ++right){
		f[right][right]=0;
		for(int left=right; left--;){
			int cur=f[right][left+1];
			for(auto mid: indices[a[left]])
				if(left<mid and mid<right){
					cur=std::max(cur, f[mid][left+1]+f[right][mid]+1);
				}
			f[right][left]=cur;
		}
	}
	std::cout<<
		a.size()-1-f[a.size()][0]
		<<'\n';
}