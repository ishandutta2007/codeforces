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

const int N = 1e3 + 5;

int n, m, k;
bool a[N][N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    ForE(i, 1, k){
        int x, y; cin >> x >> y;
        a[x][y] = 1;
        if (a[x - 1][y - 1] && a[x - 1][y] && a[x][y - 1] && a[x][y]){
            cout << i << endl;
            return 0;
        }
        if (a[x - 1][y + 1] && a[x - 1][y] && a[x][y + 1] && a[x][y]){
            cout << i << endl;
            return 0;
        }
        if (a[x + 1][y - 1] && a[x + 1][y] && a[x][y - 1] && a[x][y]){
            cout << i << endl;
            return 0;
        }
        if (a[x + 1][y + 1] && a[x + 1][y] && a[x][y + 1] && a[x][y]){
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
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