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

string s, t;

int cal(){
    int x = 0, y = 0, tx = 5, ty = 5;
    For(i, 0, 10){
        if (i % 2 == 0){
            x += t[i] - '0';
            tx--;
        }
        else{
            y += t[i] - '0';
            ty--;
        }
        if (x > y + ty or y > x + tx){
            return i + 1;
        }
    }
    return 10;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; ForE(test, 1, tests){
    cin >> s;

    int ans = 11;
    t = s;
    For(i, 0, 10){
        if (t[i] == '?'){
            if (i % 2 == 0){
                t[i] = '1';
            }
            else{
                t[i] = '0';
            }
        }
    }
    ans = min(ans, cal());
    t = s;
    For(i, 0, 10){
        if (t[i] == '?'){
            if (i % 2 == 0){
                t[i] = '0';
            }
            else{
                t[i] = '1';
            }
        }
    }
    ans = min(ans, cal());
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