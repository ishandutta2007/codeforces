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

const int N = 2e5 + 5, M = 18;

int n;
string s, t;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    cin >> n >> s >> t;

    if (s == t){
        cout << 0 << endl;
        continue;
    }
    {
        bool ck = 1;
        Fora(c, s){
            ck &= (c == '0');
        }
        if (ck){
            cout << -1 << endl;
            continue;
        }
        ck = 1;
        Fora(c, t){
            ck &= (c == '0');
        }
        if (ck){
            cout << -1 << endl;
            continue;
        }
    }
    int cnt1s = 0, cnt1t = 0;
    Fora(c, s){
        cnt1s += (c == '1');
    }
    Fora(c, t){
        cnt1t += (c == '1');
    }
    if (cnt1s != cnt1t and cnt1s != n + 1 - cnt1t){
        cout << -1 << endl;
        continue;
    }
    int ans = INT_MAX;
    if (cnt1s == cnt1t){
        int dif = 0;
        For(i, 0, n){
            dif += (s[i] != t[i]);
        }
        if (dif % 2 == 0){
            ans = min(ans, dif);
        }
    }
    if (cnt1s == n + 1 - cnt1t){
        int same = 0;
        For(i, 0, n){
            same += (s[i] == t[i]);
        }
        if (same % 2 == 1){
            ans = min(ans, same);
        }
    }
    if (ans == INT_MAX){
        cout << -1 << endl;
        continue;
    }
    cout << ans << endl;
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