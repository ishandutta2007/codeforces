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

int n, gold;
VI A, left, right;


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	FOR(i, n){
		char ch;
		std::cin >> ch;
		if(ch == 'G') A.push_back(1), gold++;
		else A.push_back(0);
	}
	left.resize(n);
	right.resize(n);
	left[0] = 0;
	REP(i, 1, n){
		if(A[i-1] == 1) left[i] = left[i-1]+1;
		else left[i] = 0;
	}
	right[n-1] = 0;
	for(int i = n-2; i >= 0; --i){
		if(A[i+1] == 1) right[i] = right[i+1]+1;
		else right[i] = 0;
	}
	int max = 0;
	if(gold == n){
		std::cout << n << "\n";
		return 0;
	}
	FOR(i, n){
		int cur = left[i] + right[i];
		if(A[i] == 0 && left[i] + right[i] < gold) cur++;
		max = std::max(max, cur);
	}
	std::cout << max << "\n";
	return 0;
}