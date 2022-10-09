#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 1000010

ll i, i1, j, k, k1, t, n, m, flag[10], a, b, q, ty, basis[70], sz, mx, x, y;
vector<ll> v, ir, l, r;
vector<array<ll, 3>> res;
ll d = 60;

bool ins(ll mask, ll ty) {
    ll i; ir.clear();
	for (i = 0; i < d; i++) {
		if (((mask >> i) & 1) == 0) continue;

		if (!basis[i]) {
			if (ty == 1) {
                basis[i] = mask; sz++;
            }
            return true;
		}

		mask ^= basis[i]; ir.pb(i);
        if (mask == 0) return false;
	}

    return false;
}

void ask(ll a, ll b, ll ty) {
    res.pb({a, b, ty});
}

int main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> x; ins(x, 1); sz = 1;
    mx = 1000000000000;

    while (true) {
        if (q == 99990) {
            while (true) {}
        }

        a = uniform_int_distribution<ll>(1, ((ll)1 << d) - 1)(rng);
        b = uniform_int_distribution<ll>(1, ((ll)1 << d) - 1)(rng);

        x = 0; y = 0; l.clear(); r.clear();
        for (i = 0; i < sz; i++) {
            if ((a >> i) & 1) {
                x ^= basis[i]; l.pb(i);
            }
            if ((b >> i) & 1) {
                y ^= basis[i]; r.pb(i);
            }
        }

        // cout << "a, b, x, y = " << a << ' ' << b << ' ' << x << ' ' << y << nf;

        if (x + y >= mx) continue;
        if (!ins(x + y, 0)) continue;

        // cout << "good a, b, x, y = " << a << ' ' << b << ' ' << x << ' ' << y << nf;

        a = 0; b = 0;
        for (auto u : l) {
            if (a != 0 && basis[u] != 0) ask(a, basis[u], 1);
            a ^= basis[u];
        }
        for (auto u : r) {
            if (b != 0 && basis[u] != 0) ask(b, basis[u], 1);
            b ^= basis[u];
        }

        ins(x + y, 1);

        ask(x, y, 0);

        a = x + y;
        for (auto u : ir) {
            if (a != 0) ask(a, basis[u], 1);
            a ^= basis[u];
        }

        if (!ins(1, 0)) {
            a = 0;
            for (auto u : ir) {
                if (a != 0) ask(a, basis[u], 1);
                a ^= basis[u];
            }

            cout << res.size() << nl;
            for (auto u : res) {
                if (u[2] == 0) {
                    cout << u[0] << " + " << u[1] << nl;
                } else {
                    cout << u[0] << " ^ " << u[1] << nl;
                }
            }

            return 0;
        }

        /* ask(-1, -1, 1);
        cout << "basis" << nl;
        for (i = 0; i < d; i++) cout << basis[i] << ' ';
        cout << nl; */

        q++;
    }

    return 0;
}