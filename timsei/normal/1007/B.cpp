#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

#define int long long

int gcd(int x, int y) {
	return (!y) ? x : gcd(y, x % y);
}

int n, m, x, y, A, B, C, pr[N], cnt;
bool isp[N];

vector <int> G[N];

void prework(int n) {
	for(int i = 1; i <= n; ++ i) {
		for(int j = i; j <= n; j += i) G[j].push_back(i);
	}
}

int K(int x) {
	return (x * (x - 1)) / 2;
}

int solve(int A, int B, int C) {
	int gab = gcd(A, B), gbc = gcd(B, C), gac = gcd(A, C);
	int g = gcd(gab, gbc);
	int ans = (int)G[A].size() * (int)G[B].size() * (int)G[C].size();
	//cerr << ans << endl;
	ans -= (int)G[g].size() * (G[g].size() - 1) * 2LL;
	//cerr << ans << endl;
	ans -= (int)G[g].size() * (G[g].size() - 1) * (G[g].size() - 2) / 6LL * 5LL;
	//cerr << ans << endl;
	ans -= (int)G[g].size() * (G[g].size() - 1) / 2LL * 
	(int)(G[A].size() + G[B].size() + G[C].size() - 3 * G[g].size());
	//cerr << ans << endl;
	ans -= (int)(K(G[gab].size()) - K(G[g].size())) * (int)G[C].size()
	     + (int)(K(G[gbc].size()) - K(G[g].size()))* (int)G[A].size()
	     + (int)(K(G[gac].size()) - K(G[g].size())) * (int)G[B].size();
	//cerr << ans << endl;
	ans += (int)(G[gbc].size() + G[gac].size() +G[gab].size() - 3 * G[g].size()) * K(G[g].size());
	ans -= (int)(G[gbc].size() - G[g].size()) * (G[gab].size() - G[g].size()) * (G[gac].size() - G[g].size());
	return ans;
}

map < pair < int, pair < int, int> > , int> Map;

#define Mk(A, B, C) make_pair(A, make_pair(B, C))

int vio(int A, int B, int C) {
	int ans = 0;
	Map.clear();
	for(int a = 0; a < (int) G[A].size(); ++ a) {
		for(int b = 0; b < (int) G[B].size(); ++ b) {
			for(int c = 0; c < (int) G[C].size(); ++ c) {
				int K[3];
				K[0] = G[A][a];
				K[1] = G[B][b];
				K[2] = G[C][c];
				sort(K, K + 3);
				if(!Map.count(Mk(K[0], K[1], K[2]))) ++ ans;
				Map[Mk(K[0], K[1], K[2])] = 1;
			}
		}
	}
	return ans;
}

main(void) {
	prework(1e5);
	int t;
	for(cin >> t; t --;) {
		scanf("%lld%lld%lld", &A, &B, &C);
		//A = rand() % 100 + 1, B = rand() % 100 + 1, C = rand() % 100 + 1;
		int V, J;
		printf("%lld\n", V = solve(A, B, C));
		//cout << (J = vio(A, B, C)) << endl;
	}
}