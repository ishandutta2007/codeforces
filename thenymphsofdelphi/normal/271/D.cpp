#include<bits/stdc++.h>
using namespace std;

// Optimization
//#pragma optimize ("O3")
#define endl '\n'

// Shortcut

#define int long long
#define eb emplace_back
#define pb push_back
#define pob pop_back
#define mp make_pair
#define upb upper_bound
#define lwb lower_bound
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define Ford(i, r, l) for (int i = r; i > l; i--)
#define FordE(i, r, l) for (int i = r; i >= l; i--)
#define Fora(i, a) for (auto i : a)

// I/O & Debug

#define PrintV(a) for (int iiii = 0; iiii < a.size(); iiii++) cout << a[iiii] << ' ';
#define PrintVl(a) for (int iiii = 0; iiii < a.size(); iiii++) cout << a[iiii] << endl;
#define PrintA(a, n) for (int iiii = 0; iiii < n; iiii++) cout << a[iiii] << ' ';
#define PrintAl(a, n) for (int iiii = 0; iiii < n; iiii++) cout << a[iiii] << endl;
#define Ptest(x) return cout << x, 0;
#define gl(s) getline(cin, s);
#define setpre(x) fixed << setprecision(x)
/*
#define debug(args...){ string _sDEB = #args; replace(_sDEB.begin(), _sDEB.end(), ',', ' '); stringstream _ssDEB(_sDEB); istream_iterator<string> _itDEB(_ssDEB); DEB(_itDEB, args); }
void DEB(istream_iterator<string> it) {}
template<typename T, typename... Args>
void DEB(istream_iterator<string> it, T a, Args... args){
    cout << *it << " = " << a << endl;
    DEB(++it, args...);
}
*/

// Functions

//#define isvowel(a) (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
#define bend(a) a.begin(), a.end()
#define rbend(a) a.rbegin(), a.rend()
#define mset(a) memset(a, 0, sizeof(a))
#define m1set(a) memset(a, 1, sizeof(a))
#define mn1set(a) memset(a, -1, sizeof(a))
#define mmset(a) memset(a, 0x3f, sizeof(a))
#define gcd __gcd
#define __builtin_popcount __builtin_popcountll
//mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());

// Data Structure

#define pque priority_queue
#define mts multiset
#define y0 _y0_
#define y1 _y1_
#define div divi
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <ld> vld;
typedef vector <string> vs;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <vi > vvi;
typedef vector <vll > vvll;
typedef vector <pii > vpii;
typedef vector <pll > vpll;

const int N = 1500 + 5, base = 28, mod1 = 1e9 + 7, mod2 = 1e9 + 9, inf = 1e9 + 7;

string s;
int hashs1[N], hashs2[N];
bool a[N], ck[27];
int n, k, ans, b[N], powbase1[N], powbase2[N];
set <pii> stt;

pii cal(int x, int y){
    pii ans = {(hashs1[y] - powbase1[y - x + 1] * (x == 0 ? 0 : hashs1[x - 1])) % mod1, (hashs2[y] - powbase2[y - x + 1] * (x == 0 ? 0 : hashs2[x - 1])) % mod2};
    if (ans.fi < 0) ans.fi += mod1;
    if (ans.se < 0) ans.se += mod2;
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    powbase1[0] = 1;
    powbase2[0] = 1;
    For(i, 1, N){
        powbase1[i] = (powbase1[i - 1] * base) % mod1;
        powbase2[i] = (powbase2[i - 1] * base) % mod2;
    }
    cin >> s;
    n = s.length();
    For(i, 0, 26){
        char c;
        cin >> c;
        ck[i] = c - '0';
        ck[i] = !ck[i];
    }
    cin >> k;
    For(i, 0, n){
        a[i] = ck[s[i] - 'a'];
    }
    b[0] = a[0];
    For(i, 1, n){
        b[i] = b[i - 1];
        if (a[i]) b[i]++;
    }
    hashs1[0] = s[0] - 'a' + 1;
    hashs2[0] = s[0] - 'a' + 1;
    For(i, 1, n){
        hashs1[i] = (hashs1[i - 1] * base + s[i] - 'a' + 1) % mod1;
        hashs2[i] = (hashs2[i - 1] * base + s[i] - 'a' + 1) % mod2;
    }
    For(i, 0, n){
        For(j, i, n){
            if (b[j] - (i == 0 ? 0 : b[i - 1]) <= k){
                //cout << i << ' ' << j << ' ' << cal(i, j) << endl;
                stt.insert(cal(i, j));
            }
        }
    }
    cout << stt.size();
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