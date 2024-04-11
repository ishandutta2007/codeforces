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

const int N = 1e4 + 5;

int n;
string s[N];

map <string, pii> mpp;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    ForE(i, 1, n){
        cin >> s[i];
        set <string> stt;
        For(j, 0, isz(s[i])){
            For(k, j, isz(s[i])){
                string ss = s[i].substr(j, k - j + 1);
                stt.insert(ss);
            }
        }
        Fora(&ss, stt){
            if (!mpp.count(ss)){
                mpp[ss] = make_pair(1, i);
            }
            else{
                mpp[ss].fi++;
            }
        }
    }
int q; cin >> q; while (q--){
    string t; cin >> t;
    if (mpp.count(t)){
        cout << mpp[t].fi << ' ' << s[mpp[t].se] << endl;
    }
    else{
        cout << 0 << ' ' << '-' << endl;
    }
}
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