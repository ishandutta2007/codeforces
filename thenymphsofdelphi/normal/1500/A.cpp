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

const int N = 2e5 + 5, M = 5e6 + 5;

int n;
int a[N];
pii cac[M];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    For(i, 0, M){
        cac[i] = make_pair(-1, -1);
    }
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }
    ForE(i, 1, n){
        For(j, 1, i){
            if (cac[a[i] + a[j]] == make_pair(-1, -1)){
                cac[a[i] + a[j]] = make_pair(i, j);
            }
            else if (cac[a[i] + a[j]].fi != i && cac[a[i] + a[j]].se != i && cac[a[i] + a[j]].fi != j && cac[a[i] + a[j]].se != j){
                cout << "YES" << endl;
                cout << i << ' ' << j << ' ' << cac[a[i] + a[j]].fi << ' ' << cac[a[i] + a[j]].se << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
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