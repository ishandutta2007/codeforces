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

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;
typedef vector <vi> vvi;

const int N = 1e5 + 5;

string s, t;
vector <bool> ck;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    getline(cin, s);
    ck.assign(isz(s), 1);
    For(i, 1, isz(s)){
        if (s[i] == ' ' and s[i - 1] == ' '){
            ck[i] = 0;
        }
    }
    t = ""; For(i, 0, isz(s)) if (ck[i]) t += s[i]; s = t; ck.assign(isz(s), 1);
    For(i, 0, isz(s) - 1){
        if (s[i] == ' ' and !islower(s[i + 1])){
            ck[i] = 0;
        }
    }
    t = ""; For(i, 0, isz(s)) if (ck[i]) t += s[i]; s = t; ck.assign(isz(s), 1);
    For(i, 0, isz(s) - 1){
        if ((!islower(s[i]) and s[i] != ' ') and islower(s[i + 1])){
            s.insert(s.begin() + i + 1, ' ');
        }
    }
    cout << s << endl;
}

/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/