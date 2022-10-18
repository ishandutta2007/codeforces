#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

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

const int N = 5e2 + 5;

int n, m;
int a[N], b[N];
gp_hash_table <int, int> mppb[N];
vpii adj[N][N], radj[N][N];
int dp[N][N];

void readTest(){
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }
    cin >> m;
    ForE(i, 1, m){
        cin >> b[i];
    }
}

void solveTest(){
    ForE(i, 1, m){
        ForE(j, i, m){
            if (mppb[i].find(b[j]) == mppb[i].end()){
                mppb[i][b[j]] = j;
            }
        }
    }
    ForE(i, 1, n){
        ForE(j, 1, m){
            if (a[i] != b[j]){
                continue;
            }
            ForE(k, i + 1, n){
                if (a[k] > a[i] && mppb[j].find(a[k]) != mppb[j].end()){
                    adj[i][j].emplace_back(k, mppb[j][a[k]]);
                }
            }
        }
    }
    ForE(i, 1, n){
        ForE(j, 1, m){
            if (a[i] != b[j]){
                continue;
            }
            dp[i][j]++;
            Fora(&v, adj[i][j]){
                radj[v.fi][v.se].emplace_back(i, j);
                dp[v.fi][v.se] = max(dp[v.fi][v.se], dp[i][j]);
            }
        }
    }
    int ans = 0, tx = 0, ty = 0;
    ForE(i, 1, n){
        ForE(j, 1, m){
            if (ans < dp[i][j]){
                ans = dp[i][j];
                tx = i; ty = j;
            }
        }
    }
    cout << ans << endl;
    if (!ans){
        return;
    }
    vi vans;
    while (1){
        vans.push_back(a[tx]);
        if (!isz(radj[tx][ty])){
            break;
        }
        Fora(&v, radj[tx][ty]){
            if (dp[v.fi][v.se] == dp[tx][ty] - 1){
                tx = v.fi; ty = v.se; break;
            }
        }
    }
    reverse(bend(vans));
    Fora(&v, vans) cout << v << ' '; cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    readTest();
    solveTest();
}