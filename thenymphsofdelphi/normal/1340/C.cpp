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

const int M = 1e4 + 5, GR = 1e3 + 5;
const ll infll = (ld)1e18 + 7;

int n, m;
int a[M];
int g, r;

int dp[M][GR];
deque <tuple <int, int, int>> dq;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m;
    ForE(i, 1, m){
        cin >> a[i];
    }
    cin >> g >> r;

    sort(a + 1, a + 1 + m);
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    dq.push_back(make_tuple(0, 0, 0));
    while (!dq.empty()){
        int d, u1, u2; tie(d, u1, u2) = dq.front(); dq.pop_front();
        if (d != dp[u1][u2]){
            continue;
        }
        if (u1 > 1 and u2 + a[u1] - a[u1 - 1] <= g){
            int td = d, tu1 = u1 - 1, tu2 = u2 + a[u1] - a[u1 - 1];
            if (tu2 == g){
                td++; tu2 = 0;
            }
            if (dp[tu1][tu2] > td){
                dp[tu1][tu2] = td;
                if (td == d){
                    dq.push_front(make_tuple(td, tu1, tu2));
                }
                else{
                    dq.push_back(make_tuple(td, tu1, tu2));
                }
            }
        }
        if (u1 < m and u2 + a[u1 + 1] - a[u1] <= g){
            int td = d, tu1 = u1 + 1, tu2 = u2 + a[u1 + 1] - a[u1];
            if (tu2 == g){
                td++; tu2 = 0;
            }
            if (dp[tu1][tu2] > td){
                dp[tu1][tu2] = td;
                if (td == d){
                    dq.push_front(make_tuple(td, tu1, tu2));
                }
                else{
                    dq.push_back(make_tuple(td, tu1, tu2));
                }
            }
        }
    }
    ll ans = infll;
    For(i, 0, g){
        if (dp[m][i] != dp[m + 1][0]){
            ans = min(ans, (ll)dp[m][i] * (g + r) + i - (i == 0 ? r : 0));
        }
    }
    cout << (ans == infll ? -1 : ans) << endl;
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