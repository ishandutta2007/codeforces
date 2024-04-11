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

const int N = 50 + 5;

int n, m;
char a[N][N];

char b[N][N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    cin >> n >> m;
    ForE(i, 1, n){
        ForE(j, 1, m){
            cin >> a[i][j];
        }
    }

    ForE(i, 1, n){
        ForE(j, 1, m){
            if (a[i][j] == 'o'){
                b[i][j] = 'o';
            }
            else{
                b[i][j] = '.';
            }
        }
    }
    FordE(i, n, 1){
        ForE(j, 1, m){
            if (a[i][j] == '*'){
                int ti = i;
                while (ti + 1 <= n and b[ti + 1][j] == '.'){
                    ti++;
                }
                b[ti][j] = '*';
            }
        }
    }
    ForE(i, 1, n){
        ForE(j, 1, m){
            cout << b[i][j];
        } cout << endl;
    }
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