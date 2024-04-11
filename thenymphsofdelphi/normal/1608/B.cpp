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

const int N = 2e5 + 5;

int n;
int a[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    cin >> n;
    int x, y; cin >> x >> y;
    if (x + y > n - 2){
        cout << -1 << endl;
        continue;
    }
    if (abs(x - y) > 1){
        cout << -1 << endl;
        continue;
    }
    int m = x + y + 2;
    if (x > y){
        ForE(i, 1, n - m){
            a[i] = i;
        }
        int z = n - m + 1;
        for (int i = n - m + 1; i <= n; i += 2){
            a[i] = z++;
        }
        for (int i = n - 1; i >= n - m + 2; i -= 2){
            a[i] = z++;
        }
    }
    else{
        ForE(i, 1, n - m){
            a[i] = n + 1 - i;
        }
        int z = m;
        for (int i = n - m + 1; i <= n; i += 2){
            a[i] = z--;
        }
        for (int i = (x == y ? n : n - 1); i >= n - m + 2; i -= 2){
            a[i] = z--;
        }
    }
    ForE(i, 1, n){
        cout << a[i] << ' ';
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