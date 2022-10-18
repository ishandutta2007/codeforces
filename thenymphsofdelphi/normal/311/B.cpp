#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 1e5 + 5, K = 1e2 + 5;

struct ConvexHullTrick{
    int n, idx;
    vector <ll> a, b;
 
    ConvexHullTrick(): n(0), idx(0){
 
    }
 
    bool redundant(int i, int j, int k){
        if (a[j] == a[k]){
            return b[j] < b[k];
        }
        ld xj = (ld)(b[j] - b[i]) / (a[i] - a[j]);
        ld xk = (ld)(b[k] - b[i]) / (a[i] - a[k]);
        return xj > xk;
    }
 
    void add(ll ta, ll tb){
        n++;
        a.push_back(ta);
        b.push_back(tb);
        while (n >= 2 && a[n - 2] == a[n - 1] && b[n - 2] <= b[n - 1]){
            a.erase(a.begin() + n - 2);
            b.erase(b.begin() + n - 2);
            n--;
        }
        while (n >= 3 && redundant(n - 3, n - 2, n - 1)){
            a.erase(a.begin() + n - 2);
            b.erase(b.begin() + n - 2);
            n--;
        }
    }
 
    ll query(ll x){
        idx = min(idx, n - 1);
        while (idx + 1 < n && a[idx] * x + b[idx] < a[idx + 1] * x + b[idx + 1]){
            idx++;
        }
        return a[idx] * x + b[idx];
    }
};

int n, m, k;
ll a[N], b[N];

ConvexHullTrick cac[K];
ll dp[N][K];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m >> k;
    ForE(i, 2, n){
        cin >> a[i];
        a[i] += a[i - 1];
    }
    ForE(i, 1, m){
        int x, y; cin >> x >> y; b[i] = y - a[x];
    }
    sort(b + 1, b + 1 + m);
    ForE(i, 1, m){
        a[i] = b[i];
    }
    ForE(i, 1, m){
        b[i] = b[i - 1] + a[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    ForE(j, 1, k){
        cac[j].add(0, -dp[0][j - 1] - b[0]);
    }
    ForE(i, 1, m){
        ForE(j, 1, k){
            dp[i][j] = i * a[i] - b[i] - cac[j].query(a[i]);
        }
        ForE(j, 1, k){
            cac[j].add(i, -dp[i][j - 1] - b[i]);
        }
    }
    cout << dp[m][k] << endl;
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|
-35 -26 -4 1 10 19
--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/