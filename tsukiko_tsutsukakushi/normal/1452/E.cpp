/**
 *    author:  otera    
**/
#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(int i = 0; i < n; ++ i)
#define per(i,n) for(int i=n-1;i>=0;i--)
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int f(int l1, int r1, int l2, int r2) {
    return max(0LL, min(r1, r2) - max(l1, l2));
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> l(m), r(m);
    vector<ll> a(n + 1, 0);
    rep(i, m) {
        cin >> l[i] >> r[i];
        -- l[i];
        a[l[i]] ++, a[r[i]] --;
    }
    rep(i, n) {
        a[i + 1] += a[i];
    }
    vector<ll> asum(n + 2, 0);
    rep(i, n + 1) {
        asum[i + 1] = asum[i] + a[i];
        // cerr << asum[i + 1] << " \n"[i == n];
    }
    vector<vector<ll>> p(n, vector<ll>(n, 0));
    rep(i, n) {
        rep(j, n) {
            // [i, i + k), [j, j + k)
            int ima = min(i + k, n + 1), jma = min(j + k, n + 1);
            p[i][j] = asum[ima] - asum[i] + asum[jma] - asum[j];
        }
    }
    vector<vector<ll>> ms(n, vector<ll>(n, 0));
    vector<vector<ll>> c(n + 2, vector<ll>(n + 2, 0));
    rep(i, m) {
        rep(y, n) {
            int yma = min(n + 1, y + k);
            int len = f(l[i], r[i], y, yma);
            if(len == r[i] - l[i] or len == 0 or len == k) continue;
            // cerr << l[i] << " " << r[i] << " " << x << " " << xma << " " << len << "\n";
            // [l[i] + len - k, r[i] - len]
            int xmi = max(0LL, l[i] + (len + 1) - k), xma = min(n + 1, r[i] - (len + 1) + 1);
            // cerr << i << " " << y << " " << len << " " << xmi << " " << xma << "\n";
            if(xmi < xma) c[xmi][y] += len, c[xma][y] -= len;
        }
    }
    rep(i, n) {
        for(int j = 1; j < n; ++ j) {
            c[j][i] += c[j - 1][i];
        }
    }
    rep(i, n) {
        rep(j, n) {
            ms[i][j] += c[i][j];
        }
    }
    c.assign(n + 2, vector<ll>(n + 2, 0));
    rep(i, m) {
        rep(x, n) {
            int xma = min(n + 1, x + k);
            int len = f(l[i], r[i], x, xma);
            if(len == 0) continue;
            // cerr << l[i] << " " << r[i] << " " << x << " " << xma << " " << len << "\n";
            // [l[i] + len - k, r[i] - len]
            int ymi = max(0LL, l[i] + len - k), yma = min(n + 1, r[i] - len + 1);
            if(ymi < yma)  c[x][ymi] += len, c[x][yma] -= len;
        }
    }
    rep(i, n) {
        for(int j = 1; j < n; ++ j) {
            c[i][j] += c[i][j - 1];
        }
    }
    rep(i, n) {
        rep(j, n) {
            ms[i][j] += c[i][j];
        }
    }
    ll ans = 0;
    rep(i, n - k + 1) {
        for(int j = 0; j < n - k + 1; ++ j) {
            // cerr << i << " " << j << " " << p[i][j] << " " << p[i][j] - ms[i][j] << " ";
            // int res = 0;
            // rep(x, m) {
            //     res += max(f(l[x], r[x], i, i + k), f(l[x], r[x], j, j + k));
            // }
            // cerr << res << "\n";
            if(i == j) continue;
            chmax(ans, p[i][j] - ms[i][j]);
        }
    }
    rep(i, n - k + 1) {
        chmax(ans, p[i][i] / 2);
    }
    cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}