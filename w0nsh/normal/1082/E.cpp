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

int n, c;
VI A, next, first, last, pref, left, right;

int on_seg(int a, int b){
	return pref[b+1] - pref[a];
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> c;
	first.resize(500000, -1);
	last.resize(500000, -1);
	pref.resize(n+1);
	next.resize(n, -1);
	FOR(i, n){
		int a;
		std::cin >> a;
		if(a == c) A.push_back(-1);
		else{
			a--;
			A.push_back(a);
			if(first[a] == -1) first[a] = i;
		}
	}
	for(int i = n-1; i >= 0; --i){
		if(A[i] == -1) continue;
		next[i] = last[A[i]];
		last[A[i]] = i;
	}
	FOR(i, n) pref[i+1] = pref[i] + (A[i] == -1 ? 1 : 0);
	int max = std::count(A.begin(), A.end(), -1);
	FOR(i, 500000){
		if(first[i] == -1) continue;
		max = std::max(max, on_seg(0, n-1));
		int pos = first[i];
		int start = pos;
		int cur = 1;
		int cnt = 1;
		while(next[pos] != -1){
			max = std::max(max, on_seg(0, start) + cnt + on_seg(pos, n-1));
			int cs = on_seg(pos, next[pos]);
			if(cur - cs < 0){
				start = next[pos];
				cur = 1;
				cnt = 1;
			}else{
				cur -= cs;
				cnt++;
				cur++;
			}
			pos = next[pos];
		}
		max = std::max(max, on_seg(0, start) + cnt + on_seg(pos, n-1));
	}
	std::cout << max << "\n";
	return 0;
}