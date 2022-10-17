#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

#define int long long
inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

#define ll long long
const int mod = 998244353, MAXN = 2002000, LIM = 2e6;
ll n, a[MAXN], top, p[MAXN]; bool np[MAXN];
vector <ll> rem, qwq;

void genp () {
	int i, j;
	for (i = 2; i <= LIM; i++) {
		if (!np[i]) p[++top] = i;
		for (j = 1; j <= top; j++) {
			if (p[j] * i > LIM) break;
			np[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}
}

ll findsq (ll x) {
	ll L = 1, R = min(x, (ll)(2e9));
	while (L <= R) {
		ll mid = (L + R) >> 1;
		if (mid * mid == x) return mid;
		else if (mid * mid < x) L = mid + 1;
		else R = mid -1;
	}
	return -1;
}

map <ll, int> vis; bool vvis[MAXN];

bool solve () {
	if (rem.empty()) return 0;
	for (int i = 0; i < rem.size(); i++) {
		bool suc = 0; vvis[i] = 0;
		for (auto j: vis) if (rem[i] % j.first == 0) { suc = 1; ++vis[j.first]; ++vis[rem[i] / j.first]; vvis[i] = 1; break; }
		if (suc) {
			// printf("!!! i = %lld\n", i);
			// cout << rem[i] << endl;
			// for (auto j: vis) printf("%lld: %lld\n", j.first, j.second);
			continue;
		}
		for (int j = 0; j < i; j++) if (!vvis[j]) {
			ll tmp = __gcd(rem[j], rem[i]);
			if (tmp != 1 && tmp != rem[i]) {
				vvis[i] = vvis[j] = 1;
				vis[tmp] += 2; ++vis[rem[i] / tmp]; ++vis[rem[j] / tmp];
				break;
			}
		}
		// printf("!!! i = %lld\n", i);
		// for (auto j: vis) printf("%lld: %lld\n", j.first, j.second);
	}
	for (int i = 0; i < rem.size(); i++) if (!vvis[i]) qwq.push_back(rem[i]);
	bool tmp = !qwq.empty() && qwq.size() != rem.size(); rem = qwq; qwq.clear(); return tmp;
}

map <ll, int> buc;

signed main () {
	n = read(); int i, j;
	genp();
	for (i = 1; i <= n; i++) a[i] = read();
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= top && 1ll * p[j] * p[j] <= a[i]; j++) if (a[i] % p[j] == 0) {
			a[i] /= p[j]; ++vis[p[j]];
			if (a[i] % p[j]) ++vis[a[i]];
			else {
				do { a[i] /= p[j]; ++vis[p[j]]; } while (a[i] % p[j] == 0);
			}
			a[i] = -1;
			break;
		}
		if (a[i] != -1) {
			ll tmp = findsq(a[i]);
			if (tmp != -1) { vis[tmp] += 2; continue; }
			rem.push_back(a[i]);
		}
	}
	while (solve());
	int ans = 1;
	for (auto i: vis) ans = 1ll * ans * (i.second + 1) % mod; //, printf("%lld: %lld\n", i.first, i.second);
	for (i = 0; i < rem.size(); i++) if (!vvis[i]) ++buc[rem[i]];
	for (auto i: buc) ans = 1ll * ans * (i.second + 1) % mod, ans = 1ll * ans * (i.second + 1) % mod;
	printf("%lld\n",ans);
	return 0;
}