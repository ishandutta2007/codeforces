#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll c[maxn], ty[maxn], x, tk, rm, nt, ns, sm;
vector<ll> adj[4], ps[4];

struct op_queue {
	ll cn, tt;
	priority_queue<ll> mx, mn;

	op_queue() {
		cn = 0; tt = 0;
	}

	void ins(ll x) {
        ll y;
		mx.push(-x); tt += x;
        y = mx.top(); tt += y; mx.pop(); mn.push(-y);
	}

	ll rsq(ll p) {
		ll i, x;

		if (p < 0 || p > (mx.size() + mn.size())) return -INF;

		for (i = 1; i <= cn - p; i++) {
			x = mx.top(); mx.pop();
			mn.push(-x); tt += x;
		}

		for (i = 1; i <= p - cn; i++) {
			x = mn.top(); mn.pop();
			mx.push(-x); tt += x;
		}

		cn = p; return tt;
	}

    void dbg() {
        ll x;
        vector<ll> v;

        while (!mx.empty()) {
            x = mx.top(); mx.pop(); v.pb(x); cout << x << ' ';
        }
        cout << nl;
        for (auto u : v) mx.push(u);

        v.clear();
        while (!mn.empty()) {
            x = mn.top(); mn.pop(); v.pb(x); cout << x << ' ';
        }
        cout << nl << "---" << nl;
        for (auto u : v) mn.push(u);
    }
};

op_queue pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	#if !ONLINE_JUDGE && !EVAL
		ifstream cin("input.txt");
		ofstream cout("output.txt");
	#endif

	cin >> n >> m >> k;
	for (i = 1; i <= n; i++) {
		cin >> c[i]; c[i] = -c[i];
	}

	cin >> x;
	for (i = 1; i <= x; i++) {
		cin >> a; ty[a]++;
	}

	cin >> x;
	for (i = 1; i <= x; i++) {
		cin >> a; ty[a] += 2;
	}

	for (i = 1; i <= n; i++) adj[ty[i]].pb(c[i]);

	for (i = 0; i <= 3; i++) {
		sort(adj[i].begin(), adj[i].end());
		reverse(adj[i].begin(), adj[i].end());
		ps[i] = adj[i];
		for (j = 1; j < ps[i].size(); j++) ps[i][j] += ps[i][j - 1];
	}

	for (auto u : adj[0]) pq.ins(u);

	nt = INF; res = -INF;
	for (i = 0; i <= adj[3].size(); i++) {
		tk = max((ll)0, k - i);
		for (j = tk; j < min(nt, (ll)adj[1].size()); j++) pq.ins(adj[1][j]);
		for (j = tk; j < min(nt, (ll)adj[2].size()); j++) pq.ins(adj[2][j]);
		nt = tk;

		ns = m - (i + 2 * tk);
		if (ns < 0) continue;
		if (tk > adj[1].size()) continue;
		if (tk > adj[2].size()) continue;

		sm = 0;
		if (i >= 1) sm += ps[3][i - 1];
		if (tk >= 1) sm += (ps[1][tk - 1] + ps[2][tk - 1]);
		sm += pq.rsq(ns);
		res = max(res, sm);
        // cout << "i, sm =" _ i _ sm << nl;
        // pq.dbg();
	}

	res = -res;
    if (res > (ll)1e17) res = -1;
	cout << res << nl;

	return 0;
}