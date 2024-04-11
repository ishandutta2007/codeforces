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

VI nim;

void solve(){
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;

	int a = 0;
	int b = 0;
	FOR(i, SZ(s)){
		if(s[i] == 'R') a++;
		else if(s[i] == 'B') b++;
	}

	if(a > b) std::cout << "Alice\n";
	else if(a < b) std::cout << "Bob\n";

	if(a != b) return;

	int cnt = 0;
	int cur = 1;
	int nimber = 0;
	VI have;
	REP(i, 1, SZ(s)){
		if(s[i] == s[i-1]){
			nimber ^= nim[cur-1];
			cur = 1;
		}else{
			cur++;
		}
	}
	nimber ^= nim[cur-1];
	std::cout << (nimber != 0 ? "Alice\n" : "Bob\n");
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	constexpr int N = 5000;
	constexpr int B = 500005;
	nim.resize(B);
	nim[0] = 0;
	nim[1] = 1;
	int cnt = 0;
	int mx = 0;
	REP(i, 2, N){
		// if(i % 100 == 0) std::cerr << (double) i / N * 100 << " | cnt = " << cnt << " | mx = " << mx << std::endl;
		std::vector<bool> block(N+5);
		FOR(j, i - 2){
			block[nim[j] ^ nim[i - 3 - j]] = true;
		}
		block[nim[i - 2]] = true;

		FOR(j, N+5) if(!block[j]){
			nim[i] = j;
			break;
		}

		if(nim[i] == 0) cnt++;
		mx = std::max(mx, nim[i]);
	}

	FOR(x, 10){
		VI xd;
		FOR(i, N){
			if(nim[i] == x) xd.push_back(i);
		}

		assert(SZ(xd) > 100 || SZ(xd) == 0);
		if(SZ(xd) == 0) continue;

		int start = xd[50];
		int cyc = 0;

		VI roz;
		REP(i, 50, SZ(xd)-1) roz.push_back(xd[i+1] - xd[i]);

		while(true){
			cyc++;
			assert(cyc <= 10);
			bool good = true;
			FOR(a, SZ(roz)-cyc){
				if(roz[a] != roz[a + cyc]){
					good = false;
					break;
				}
			}
			if(good) break;
		}

		TRAV(i, xd) nim[i] = x;
		int kt = 0;
		while(start < B){
			nim[start] = x;
			start += roz[kt++ % cyc];
		}
	}

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}