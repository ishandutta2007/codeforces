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
pii a[N];

void cal(){
    vi b[2][2];
    ForE(i, 1, n){
        b[a[i].fi & 1][a[i].se & 1].emplace_back(i);
    }
    int cntnempty = (b[0][0].empty() ? 0 : 1) + (b[0][1].empty() ? 0 : 1) + (b[1][0].empty() ? 0 : 1) + (b[1][1].empty() ? 0 : 1);
    if (cntnempty == 1){
        ForE(i, 1, n){
            a[i].fi /= 2; a[i].se /= 2;
        }
        cal();
    }
    if ((!b[0][0].empty() or !b[1][1].empty()) and (!b[0][1].empty() or !b[1][0].empty())){
        cout << isz(b[0][0]) + isz(b[1][1]) << endl;
        Fora(&elem, b[0][0]){
            cout << elem << ' ';
        }
        Fora(&elem, b[1][1]){
            cout << elem << ' ';
        }
        exit(0);
    }
    if (b[0][0].empty() and b[1][1].empty()){
        cout << isz(b[0][1]) << endl;
        Fora(&elem, b[0][1]){
            cout << elem << ' ';
        }
        exit(0);
    }
    cout << isz(b[0][0]) << endl;
    Fora(&elem, b[0][0]){
        cout << elem << ' ';
    }
    exit(0);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i].fi >> a[i].se;
        a[i].fi += 2e6; a[i].se += 2e6;
    }
    cal();
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