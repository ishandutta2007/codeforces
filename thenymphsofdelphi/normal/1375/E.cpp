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

int n;
int a[N];

vi b[N];
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
    ForE(i, 1, n){
        vpii c;
        For(j, 1, i){
            if (a[j] > a[i]){
                c.emplace_back(a[j], j);
            }
        }
        sort(bend(c));
        Fora(&elem, c){
            b[i].emplace_back(elem.se);
        }
    }
    FordE(i, n, 1){
        Fora(&elem, b[i]){
            vans.emplace_back(elem, i);
        }
    }
    cout << isz(vans) << endl;
    Fora(&elem, vans){
        cout << elem.fi << ' ' << elem.se << endl;
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