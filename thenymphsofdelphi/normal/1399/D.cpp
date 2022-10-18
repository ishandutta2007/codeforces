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

const int N = 2e5 + 5;

int n;
string s;
int ans[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
int q; cin >> q; while (q--){
    cin >> n;
    cin >> s; s = ' ' + s;
    queue <int> qu0, qu1;
    int cnt = 0;
    ForE(i, 1, n){
        if (s[i] == '0'){
            if (!qu1.empty()){
                ans[i] = qu1.front(); qu1.pop();
            }
            else{
                ans[i] = ++cnt;
            }
            qu0.push(ans[i]);
        }
        else{
            if (!qu0.empty()){
                ans[i] = qu0.front(); qu0.pop();
            }
            else{
                ans[i] = ++cnt;
            }
            qu1.push(ans[i]);
        }
    }
    cout << cnt << endl;
    ForE(i, 1, n){
        cout << ans[i] << ' ';
    } cout << endl;
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