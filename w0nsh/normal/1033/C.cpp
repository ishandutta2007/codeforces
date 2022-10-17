#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define SZ(i) ((int)(i).size())
#define X first
#define Y second
#define PR std::pair
#define PII std::pair<int, int>
#define MP std::make_pair
#define ll long long
#define VI std::vector<int>

int n, board[100005], where[100005];
bool win[100005];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	FOR(i, n){
		std::cin >> board[i];
		where[board[i]] = i;
	}
	win[where[n]] = false;
	for(int i = n-1; i >= 1; --i){
		int pos = where[i];
		bool good = false;
		bool any = false;
		while(pos >= 0){
			if(board[pos] > i){
				any = true;
				if(!win[pos]){
					good = true;
					break;
				}
			}
			pos -= i;
		}
		pos = where[i];
		while(pos < n){
			if(board[pos] > i){
				any = true;
				if(!win[pos]){
					good = true;
					break;
				}
			}
			pos += i;
		}
		if(any && good) win[where[i]] = true;
	}
	FOR(i, n) std::cout << (win[i] ? "A" : "B");
	return 0;
}