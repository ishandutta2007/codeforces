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

const int N = 1e2 + 5;

const ld vangchoe = ((ld)1 + sqrtl((ld)5)) / (ld)2;

int n;
pair <ld, ld> a[5 * N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        a[i * 4 - 2] = make_pair(vangchoe / 2, sqrtl(1 - (vangchoe / 2) * (vangchoe / 2)));
        a[i * 4 - 1] = make_pair(vangchoe, 0);
        a[i * 4 - 0] = make_pair(vangchoe - (vangchoe - 1) / 2, -sqrtl(1 - ((vangchoe - 1) / 2) * ((vangchoe - 1) / 2)));
        a[i * 4 + 1] = make_pair((vangchoe - 1) / 2, -sqrtl(1 - ((vangchoe - 1) / 2) * ((vangchoe - 1) / 2)));

        a[i * 4 - 2].fi += vangchoe * (i - 1);
        a[i * 4 - 1].fi += vangchoe * (i - 1);
        a[i * 4 - 0].fi += vangchoe * (i - 1);
        a[i * 4 + 1].fi += vangchoe * (i - 1);
    }
    cout << 4 * n + 1 << endl;
    ForE(i, 1, 4 * n + 1){
        cout << fixed << setprecision(12) << a[i].fi * 10 << ' ' << a[i].se * 10 << endl;
    }
    cout << fixed << setprecision(0);
    cout << "1 2 3 4 5 " << endl;
    ForE(i, 2, n){
        cout << i * 4 - 5 << ' ' << i * 4 - 2 << ' ' << i * 4 - 1 << ' ' << i * 4 - 0 << ' ' << i * 4 + 1 << endl;
    }
    cout << "1 ";
    ForE(i, 1, n){
        cout << i * 4 - 0 << ' ' << i * 4 - 2 << ' ' << i * 4 + 1 << ' ' << i * 4 - 1 << ' ';
    }
    FordE(i, n - 1, 1){
        cout << i * 4 - 1 << ' ';
    }
    cout << "1 " << endl;
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