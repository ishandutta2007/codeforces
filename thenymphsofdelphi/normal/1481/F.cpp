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

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;
typedef vector <vi> vvi;

const int N = 1e5 + 5, S = 450 + 5;

int n, k;
vi adj[N];
int mxh, h[N], cnt[N];

void dfs(int u){
    Fora(&v, adj[u]){
        h[v] = h[u] + 1;
        dfs(v);
    }
}

unordered_map <int, int> mpp, mpp2;
vpii a(1);

bool dp[S][N]; int trace[S][N];
int near[N];

bool chosen[N];
char ans[N];

vi verh[N]; int suffcnt[N], cntnleaf[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> n >> k;
    ForE(i, 2, n){
        int j; cin >> j;
        adj[j].push_back(i);
    }
    h[1] = 1;
    dfs(1);
    ForE(i, 1, n){
        mxh = max(mxh, h[i]);
        cnt[h[i]]++;
    }
    ForE(i, 1, n){
        if (cnt[i]){
            mpp[cnt[i]]++;
        }
    }
    Fora(&v, mpp){
        a.push_back(v);
    }
    dp[0][0] = 1;
    For(i, 1, isz(a)){
        ForE(j, 0, k){
            if (dp[i - 1][j]){
                near[j] = 0;
            }
            else{
                near[j] = (j < a[i].fi ? N : near[j - a[i].fi] + 1);
            }
            if (near[j] <= a[i].se){
                trace[i][j] = near[j];
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    if (dp[isz(a) - 1][k]){
        int tk = k;
        FordE(i, isz(a) - 1, 1){
            mpp2[a[i].fi] = trace[i][tk];
            tk -= trace[i][tk] * a[i].fi;
        }
        ForE(i, 1, n){
            if (mpp2[cnt[i]]){
                chosen[i] = 1; mpp2[cnt[i]]--;
            }
        }
        ForE(i, 1, n){
            if (chosen[h[i]]){
                ans[i] = 'a';
            }
            else{
                ans[i] = 'b';
            }
        }
        cout << mxh << endl;
        ForE(i, 1, n){
            cout << ans[i];
        } cout << endl;
        return 0;
    }
    ForE(i, 1, n){
        verh[h[i]].push_back(i);
        if (isz(adj[i])){
            cntnleaf[h[i]]++;
        }
    }
    FordE(i, n, 1){
        suffcnt[i] = suffcnt[i + 1] + cnt[i];
    }
    ForE(i, 1, n){
        if (cnt[i] <= k){
            Fora(&u, verh[i]){
                ans[u] = 'a';
            }
            k -= cnt[i];
            continue;
        }
        if (cnt[i] <= suffcnt[i] - k){
            Fora(&u, verh[i]){
                ans[u] = 'b';
            }
            continue;
        }
        if (cntnleaf[i] <= k){
            Fora(&u, verh[i]){
                if (isz(adj[u])){
                    ans[u] = 'a';
                    k--;
                }
            }
            Fora(&u, verh[i]){
                if (isz(adj[u])){
                    continue;
                }
                if (k){
                    ans[u] = 'a';
                    k--;
                }
                else{
                    ans[u] = 'b';
                }
            }
        }
        else{
            Fora(&u, verh[i]){
                if (isz(adj[u])){
                    ans[u] = 'b';
                }
            }
            int cac = (suffcnt[i] - k) - cntnleaf[i];
            Fora(&u, verh[i]){
                if (isz(adj[u])){
                    continue;
                }
                if (cac){
                    ans[u] = 'b';
                    cac--;
                }
                else{
                    ans[u] = 'a';
                    k--;
                }
            }
        }
    }
    cout << mxh + 1 << endl;
    ForE(i, 1, n){
        cout << ans[i];
    } cout << endl;
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