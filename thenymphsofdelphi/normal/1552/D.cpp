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

const int N = 10 + 5, mod = 1e9 + 7;

int n;
int a[N];

bool ans;

int b[N], t;

void bt(int u){
    if (u == n + 1){
        ForE(i, 1, n){
            if (b[i] == 0 and t == a[i]){
                ans = 1;
            }
        }
        return;
    }
    b[u] = -1; t -= a[u]; bt(u + 1); t += a[u];
    b[u] = 0; bt(u + 1);
    b[u] = 1; t += a[u]; bt(u + 1); t -= a[u];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int q; cin >> q; while (q--){
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
        a[i] = abs(a[i]);
    }
    ans = 0; t = 0;
    bt(1);
    if (ans){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
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