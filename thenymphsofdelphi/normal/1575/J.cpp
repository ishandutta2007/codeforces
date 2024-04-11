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

const int N = 1e3 + 5;

int n, m, q;
int a[N][N];

set <int> stt[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m >> q;
    ForE(i, 1, n){
        ForE(j, 1, m){
            cin >> a[i][j];
            if (a[i][j] != 2){
                stt[j].emplace(i);
            }
        }
    }
    ForE(j, 1, m){
        stt[j].emplace(n + 1);
    }
    while (q--){
        int j; cin >> j;
        int i = 1;
        while (1){
            i = *stt[j].lower_bound(i);
            if (i == n + 1){
                break;
            }
            if (a[i][j] == 1){
                a[i][j] = 2;
                stt[j].erase(i);
                j++;
            }
            else{
                a[i][j] = 2;
                stt[j].erase(i);
                j--;
            }
        }
        cout << j << ' ';
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