#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 5e3 + 5;

int n, X, Y;
string s, t;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    cin >> n >> X >> Y;
    cin >> s; s = ' ' + s;
    cin >> t; t = ' ' + t;

    int sum = 0;
    ForE(i, 1, n){
        s[i] = (s[i] == t[i] ? '0' : '1');
        sum += (s[i] == '1');
    }
    if (sum % 2 == 1){
        cout << -1 << endl;
        continue;
    }
    if (sum == 0){
        cout << 0 << endl;
        continue;
    }

    if (X >= Y){
        int mnpos = 0, mxpos = 0;
        ForE(i, 1, n){
            if (s[i] == '1'){
                if (mnpos == 0){
                    mnpos = i;
                }
                mxpos = i;
            }
        }
        if (sum == 2 and mnpos + 1 == mxpos){
            cout << min(X, 2 * Y) << endl;
            continue;
        }
        cout << (ll)sum / 2 * Y << endl;
        continue;
    }
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