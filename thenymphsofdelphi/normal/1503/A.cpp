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

const int N = 2e5 + 5;

int n;
string s;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
int q; cin >> q; while (q--){
    cin >> n;
    cin >> s;
    if (s[0] == '0' or s.back() == '0'){
        cout << "NO" << endl;
        continue;
    }
    int cnt = 0;
    For(i, 0, n){
        cnt += s[i] - '0';
    }
    if (cnt & 1){
        cout << "NO" << endl;
        continue;
    }
    cout << "YES" << endl;
    string t1(n, ' '), t2(n, ' ');
    int cnt2 = 0;
    For(i, 0, n){
        if (s[i] == '1'){
            cnt2++;
            if (cnt2 <= cnt / 2){
                t1[i] = t2[i] = '(';
            }
            else{
                t1[i] = t2[i] = ')';
            }
        }
    }
    cnt2 = 0;
    For(i, 0, n){
        if (s[i] == '0'){
            cnt2 = 1 - cnt2;
            if (cnt2){
                t1[i] = ')'; t2[i] = '(';
            }
            else{
                t1[i] = '('; t2[i] = ')';
            }
        }
    }
    cout << t1 << endl << t2 << endl;
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