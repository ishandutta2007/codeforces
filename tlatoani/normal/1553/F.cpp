// chrono::system_clock::now().time_since_epoch().count()
#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int M = (int)3e5;

namespace A {
    ll t[M * 4];

    void update(int l, int r, ll x, int v = 1, int tl = 1, int tr = M) {
        if (l > r || tl > r || tr < l) {
            return;
        }

        if (l <= tl && tr <= r) {
            t[v] += x;
            return;
        }

        int mid = (tl + tr) >> 1;
        int c1 = (v << 1), c2 = (c1 | 1);

        update(l, r, x, c1, tl, mid);
        update(l, r, x, c2, mid + 1, tr);
    }

    ll get(int p, int v = 1, int tl = 1, int tr = M) {
        if (tl == tr) {
            return t[v];
        }

        int mid = (tl + tr) >> 1;
        int c1 = (v << 1), c2 = (c1 | 1);

        if (p <= mid) {
            return t[v] + get(p, c1, tl, mid);
        }
        else {
            return t[v] + get(p, c2, mid + 1, tr);
        }
    }
}

namespace B {
    ll t[M * 4];

    void update(int p, ll x, int v = 1, int tl = 1, int tr = M) {
        if (tl == tr) {
            t[v] += x;
            return;
        }

        int mid = (tl + tr) >> 1;
        int c1 = (v << 1), c2 = (c1 | 1);

        if (p <= mid) {
            update(p, x, c1, tl, mid);
        }
        else {
            update(p, x, c2, mid + 1, tr);
        }

        t[v] = t[c1] + t[c2];
    }

    ll get(int l, int r, int v = 1, int tl = 1, int tr = M) {
        if (l > r || tl > r || tr < l) {
            return 0ll;
        }

        if (l <= tl && tr <= r) {
            return t[v];
        }

        int mid = (tl + tr) >> 1;
        int c1 = (v << 1), c2 = (c1 | 1);

        return get(l, r, c1, tl, mid) + get(l, r, c2, mid + 1, tr);
    }
}

int n;

void solve() {
    cin >> n;
    ll pref = 0, ans = 0;

    rep (i, 1, n + 1) {
        int x;
        cin >> x;
        ans += x * (i - 1ll);
        ans += A::get(x);
        ans += pref;
        pref += x;
        
        for (int j = x; j <= M; j += x) {
            int l = j, r = min(M, j + x - 1);
            ans -= x * B::get(l, r) * (j / x);
            A::update(l, r, -x * (j / x));
        }

        B::update(x, 1);
        cout << ans << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;

    for (int i = 1; i <= tt; ++i) {
        solve();
    }
    
    cout << endl;
    
    return 0;
}