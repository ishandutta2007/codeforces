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

const int N = 2e5 + 5, mod = 1e9 + 7;



signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int q; cin >> q; while (q--){
    int n; cin >> n;
    string s; cin >> s;
    string t = s; sort(bend(t));
    int ans = 0;
    For(i, 0, n){
        if (s[i] != t[i]){
            ans++;
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