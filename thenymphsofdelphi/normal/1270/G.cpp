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

const int N = 1e6 + 5;

int n;
int a[N];

bool ck[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i]; a[i] = i - a[i];
    }
    ForE(i, 1, n){
        ck[i] = 0;
    }
    int u = 1; ck[u] = 1;
    while (!ck[a[u]]){
        u = a[u]; ck[u] = 1;
    }
    u = a[u];
    vi vans = {u};
    while (a[vans.back()] != u){
        int v = a[vans.back()]; vans.emplace_back(v);
    }
    cout << isz(vans) << endl;
    Fora(&v, vans){
        cout << v << ' ';
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