#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Vi = vector<int>;
using Pii = pair<int, int>;
#define pb push_back
#define x first
#define y second
#define rep(i,b,e) for(int i = (b); i < (e); i++)
#define each(a,x) for(auto& a : (x))
#define all(x) (x).begin(),(x).end()
#define sz(x) int((x).size())
#define tem template<class t,class u, class...w>
#define pri(x,y)tem auto operator<<(t& o, u a)->decltype(x,o) { o << y; return o; }
pri(a.print(), "{";a.print();o<<"}");
pri(a.y,"("<<a.x<<", "<<a.y<<")");
pri(all(a), "["; auto d=""; for (auto i : a) (o << d << i, d = ", "); o << "]");
void DD(...) {}
tem void DD(t s, u a, w... k) {
	int b = 44;
	while (*s && *s != b) {
		b += (*s == 40 ? 50 : *s == 41 ? -50 : 0);
		cerr << *s++;
	}
	cerr << ": " << a << *s++; DD(s, k...);
}
tem vector<t> span(const t* a, u n) { return {a, a+n}; }
#ifdef LOC
#define deb(...) (DD("#, "#__VA_ARGS__, __LINE__,__VA_ARGS__), cerr << endl)
#else
#define deb(...)
#endif
#define DBP(...) void print() { DD(#__VA_ARGS__, __VA_ARGS__); }

vector<Vi> G;
Vi dp;
int ans;

void dfs(int v, int p) {
	int m1 = -1, m2 = -1;
	int k = sz(G[v]) - (p != -1);
	dp[v] = 1;

	each(e, G[v]) if (e != p) {
		dfs(e, v);
		dp[v] = max(dp[v], dp[e]+k);

		if (dp[e] >= m1) {
			m2 = m1;
			m1 = dp[e];
		} else {
			m2 = max(m2, dp[e]);
		}
	}

	ans = max(ans, dp[v] + (p != -1));

	if (m1 != -1 && m2 != -1) {
		ans = max(ans, m1+m2+k-1 + (p != -1));
	}
}

void run() {
	int n; cin >> n;
	G.assign(n, {});
	dp.resize(n);

	rep(i, 1, n) {
		int a, b; cin >> a >> b;
		a--; b--;
		G[a].pb(b);
		G[b].pb(a);
	}

	ans = 0;
	dfs(0, -1);
	cout << ans << '\n';

	rep(i, 0, n) {
		deb(i+1, dp[i]);
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(18);
	int q; cin >> q;
	while (q--) run();
	return 0;
}