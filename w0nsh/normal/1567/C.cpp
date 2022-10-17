#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int ways[10][2];

int on(int n, int x){
	FOR(i, x) n /= 10;
	return n % 10;
}

int dod(int n, int x, int co){
	int heh = 1;
	FOR(i, x) heh *= 10;
	return n + heh * co;
}

int get(int n){
	int pos = 2;
	while(pos < 10){
		if (on(n, pos)) {
			return dod(n, pos, -1);
		}
		n = dod(n, pos, 9);
		pos += 2;
	}
	return -1;
}

ll rec(int n){
	if(n == 0) return 1;
	ll ans = 0;
	int hehe = get(n);
	if(hehe != -1){
		ans += rec(hehe / 10) * ways[n % 10][1];
	}
	ans += rec(n / 10) * ways[n % 10][0];
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	FOR(i, 10) FOR(j, 2) ways[i][j] = 0;
	FOR(i, 10){
		FOR(j, 10){
			int sm = (i + j) % 10;
			int carry = (i + j) / 10;
			ways[sm][carry]++;
		}
	}

	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		std::cout << rec(n)-2 << "\n";
	}

	return 0;
}