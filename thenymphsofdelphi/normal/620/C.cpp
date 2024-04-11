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

const int N = 3e5 + 5, M = 19;

int n;
int a[N];

int m;
int cnt[N], cntdif;

void insert(int x){
    if (cnt[x] == 0){
        cntdif++;
    }
    cnt[x]++;
}

void erase(int x){
    cnt[x]--;
    if (cnt[x] == 0){
        cntdif--;
    }
}

pii dp[M][N]; int trace[N];

pii cal(int l, int r){
    int z = __lg(r - l + 1);
    return max(dp[z][l + (1 << z) - 1], dp[z][r]);
}

vpii vans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }

    {
        vi b(a + 1, a + n + 1);
        sort(bend(b)); b.erase(unique(bend(b)), b.end());
        m = isz(b);
        ForE(i, 1, n){
            a[i] = lower_bound(bend(b), a[i]) - b.begin() + 1;
        }
    }
    int l = 1;
    ForE(r, 1, n){
        insert(a[r]);
        while (cntdif != r - l + 1){
            erase(a[l]);
            l++;
        }
        if (l != 1){
            pii cac = cal(0, l - 2);
            dp[0][r] = make_pair(cac.fi + 1, r); trace[r] = cac.se;
        }
        else{
            dp[0][r] = make_pair(-1, r);
        }
        for (int i = 1; r - (1 << i) + 1 >= 0; i++){
            dp[i][r] = max(dp[i - 1][r], dp[i - 1][r - (1 << (i - 1))]);
        }
    }
    if (dp[0][n].fi == -1){
        cout << dp[0][n].fi << endl;
        return 0;
    }
    int r = n;
    while (r != 0){
        int l = trace[r];
        vans.emplace_back(l + 1, r);
        r = l;
    }
    reverse(bend(vans));
    cout << dp[0][n].fi << endl;
    Fora(range, vans){
        cout << range.fi << ' ' << range.se << endl;
    }
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