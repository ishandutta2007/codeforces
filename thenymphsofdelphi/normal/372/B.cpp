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

const int N = 40 + 5;

int n, m, q;
char a[N][N];

int b[N][N];
int c[N][N][N][N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m >> q;
    ForE(i, 1, n){
        ForE(j, 1, m){
            cin >> a[i][j];
        }
    }

    ForE(i, 1, n){
        ForE(j, 1, m){
            b[i][j] = b[i][j - 1] + b[i - 1][j] - b[i - 1][j - 1] + a[i][j] - '0';
        }
    }
    ForE(i, 1, n){
        ForE(j, 1, m){
            ForE(k, 1, i){
                ForE(l, 1, j){
                    if (b[i][j] - b[i][l - 1] - b[k - 1][j] + b[k - 1][l - 1] == 0){
                        c[i][j][k][l]++;
                    }
                }
            }
            FordE(k, i, 1){
                FordE(l, j, 1){
                    c[i][j][k][l] += c[i][j][k][l + 1] + c[i][j][k + 1][l] - c[i][j][k + 1][l + 1];
                }
            }
        }
    }
    ForE(i, 1, n){
        ForE(j, 1, m){
            ForE(k, 1, i){
                ForE(l, 1, j){
                    c[i][j][k][l] += c[i][j - 1][k][l] + c[i - 1][j][k][l] - c[i - 1][j - 1][k][l];
                }
            }
        }
    }
    while (q--){
        int i, j, k, l; cin >> i >> j >> k >> l;
        cout << c[k][l][i][j] << endl;
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