// time-limit: 1000
// problem-url: https://codeforces.com/contest/1616/problem/A
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
	std::unordered_map<int, int> count;
	for(int _=0; _<number; ++_){
		int value; std::cin>>value;
		count[std::abs(value)]++;
	}
	std::cout<<std::accumulate(begin(count), end(count), 0, [&](int first, std::pair<int, int> sec){
		return first+std::min(sec.second, sec.first==0 ? 1: 2);
	})<<'\n';

}