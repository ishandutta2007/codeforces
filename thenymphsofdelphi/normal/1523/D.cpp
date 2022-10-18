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

mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());
int randt(int l, int r){ return rando() % (r - l + 1) + l; }

const int N = 2e5 + 5, P = 15;

int n, m, p;
ll a[N];

int dp[1 << P];
ll ans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m >> p;
    ForE(i, 1, n){
        string s; cin >> s;
        For(j, 0, m){
            if (s[j] == '1'){
                a[i] |= (1ll << j);
            }
        }
    }
    ForE(turn, 1, 20){
        memset(dp, 0, sizeof(dp));
        int idx = randt(1, n);
        vi vpos;
        For(j, 0, m){
            if (a[idx] & (1ll << j)){
                vpos.emplace_back(j);
            }
        }
        ForE(i, 1, n){
            int t = 0;
            For(j, 0, isz(vpos)){
                if (a[i] & (1ll << vpos[j])){
                    t |= (1 << j);
                }
            }
            dp[(1 << isz(vpos)) - 1 - t]++;
        }
        For(i, 0, isz(vpos)){
            For(msk, 0, (1 << isz(vpos))){
                if (msk & (1 << i)){
                    dp[msk] += dp[msk ^ (1 << i)];
                }
            }
        }
        For(msk, 0, (1 << isz(vpos))){
            if (dp[msk] >= (n + 1) / 2){
                if (isz(vpos) - __builtin_popcount(msk) > __builtin_popcountll(ans)){
                    ans = 0;
                    For(i, 0, isz(vpos)){
                        if (!(msk & (1 << i))){
                            ans |= (1ll << vpos[i]);
                        }
                    }
                }
            }
        }
    }
    For(i, 0, m){
        cout << (ans & (1ll << i) ? 1 : 0);
    } cout << endl;
}

/* pichim
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