#include <bits/stdc++.h>
using namespace std;

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

const int N = 5e4 + 5, mod = 1e9 + 7;

int n;
int a[N][5];

bool cmp(int x, int y){
    int ans = 0;
    For(j, 0, 5){
        if (a[x][j] < a[y][j]){
            ans++;
        }
    }
    return ans >= 3;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int q; cin >> q; while (q--){
    cin >> n;
    ForE(i, 1, n){
        For(j, 0, 5){
            cin >> a[i][j];
        }
    }
    int ans = 1;
    ForE(i, 2, n){
        if (!cmp(ans, i)){
            ans = i;
        }
    }
    ForE(i, 1, n){
        if (i == ans){
            continue;
        }
        if (!cmp(ans, i)){
            ans = -1;
            break;
        }
    }
    cout << ans << endl;
}
}

/*
==================================================+
INPUT                                             |
--------------------------------------------------+

--------------------------------------------------+
==================================================+
OUTPUT                                            |
--------------------------------------------------+

--------------------------------------------------+
==================================================+
*/