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

const int N = 4e2 + 5;

int n, m, r, c;
char a[N][N], b[N][N];

bitset <N> ans[N], tmp[26][N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m;
    For(i, 0, n){
        For(j, 0, m){
            cin >> a[i][j];
        }
    }
    cin >> r >> c;
    For(i, 0, r){
        For(j, 0, c){
            cin >> b[i][j];
        }
    }
    For(i, 0, n){
        For(j, 0, m){
            ans[i].set(j);
            tmp[a[i][j] - 'a'][i].set(j);
        }
    }
    For(i, 0, r){
        For(j, 0, c){
            if (b[i][j] == '?'){
                continue;
            }
            int chr = b[i][j] - 'a', ti = i % n, tj = j % m;
            For(k, 0, n){
                ans[k] &= (tmp[chr][ti] >> tj) | (tmp[chr][ti] << (m - tj));
                ti++; if (ti == n) ti = 0;
            }
        }
    }
    For(i, 0, n){
        For(j, 0, m){
            cout << ans[i][j];
        } cout << endl;
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