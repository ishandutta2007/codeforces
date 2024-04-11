#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
// #define endl '\n'
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

const int inf = 1e9;

int query(int x, int y){
    cout << "? " << x << ' ' << y << endl;
    int ans; cin >> ans; if (ans == -1) exit(0);
    return ans;
}

void answer(int x1, int y1, int x2, int y2){
    cout << "! " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
    exit(0);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    int q11 = query(1, 1);
    int qinf1 = query(inf, 1);
    int x1x2 = q11 - qinf1 + inf + 1;
    int mx = x1x2 / 2;
    int y1 = query(mx, 1) + 1;
    int y2 = inf - query(mx, inf);
    int x1 = q11 + 1 - y1 + 1;
    int x2 = -qinf1 + inf + y1 - 1;
    answer(x1, y1, x2, y2);
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