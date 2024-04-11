#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 1e5 + 5, K = 20 + 5;

int n, k;
int a[N];

int cnt[N], lrange, rrange; ll valrange;

ll cal(int l, int r){
    while (lrange > l){
        valrange += cnt[a[--lrange]];
        cnt[a[lrange]]++;
    }
    while (rrange < r){
        valrange += cnt[a[++rrange]];
        cnt[a[rrange]]++;
    }
    while (lrange < l){
        cnt[a[lrange]]--;
        valrange -= cnt[a[lrange++]];
    }
    while (rrange > r){
        cnt[a[rrange]]--;
        valrange -= cnt[a[rrange--]];
    }
    return valrange;
}

ll dp[K][N];

void dncdp(int layer, int l, int r, int optl, int optr){
    int mid = (l + r) >> 1, optmid = -1;
    ForE(toptmid, optl, min(optr, mid)){
        ll tdp = dp[layer - 1][toptmid - 1] + cal(toptmid, mid);
        if (dp[layer][mid] > tdp){
            dp[layer][mid] = tdp;
            optmid = toptmid;
        }
    }
    if (l < mid){
        dncdp(layer, l, mid - 1, optl, optmid);
    }
    if (mid < r){
        dncdp(layer, mid + 1, r, optmid, optr);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> k;
    ForE(i, 1, n){
        cin >> a[i];
    }

    memset(dp, 0x3f, sizeof(dp));
    cnt[a[1]]++; lrange = rrange = 1;
    ForE(i, 1, n){
        dp[1][i] = cal(1, i);
    }
    ForE(j, 2, k){
        dncdp(j, 1, n, 1, n);
    }
    cout << dp[k][n] << endl;
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/