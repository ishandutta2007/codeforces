#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
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
ld p;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> p;
    int lo = 0, hi = n;
    while (lo < hi){
        int mid = (lo + hi) >> 1;
        int a3 = mid * (mid - 1) * (mid - 2) / 6;
        int a2 = mid * (mid - 1) / 2 * (n - mid);
        int a1 = mid * (n - mid) * (n - mid - 1) / 2;
        int tp = 0;
        tp += a3 * 6;
        tp += a2 * 6;
        tp += a1 * 3;
        if ((ld)tp / (n * (n - 1) * (n - 2) / 6 * 6) >= p){
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    cout << lo << endl;
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