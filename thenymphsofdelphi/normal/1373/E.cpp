#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// Optimization

//#pragma GCC optimize("O3")
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

#define PrintV(a) Fora(iiii, a) cout << iiii << ' '; cout << endl;
#define PrintVl(a) Fora(iiii, a) cout << iiii << endl;
#define PrintA(a, l, r) for (int iiii = l; iiii <= r; iiii++) cout << a[iiii] << ' '; cout << endl;
#define PrintAl(a, l, r) for (int iiii = l; iiii <= r; iiii++) cout << a[iiii] << endl;
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
#define mset1(a) memset(a, 1, sizeof(a))
#define msetn1(a) memset(a, -1, sizeof(a))
#define msetinf(a) memset(a, 0x3f, sizeof(a))
#define gcd __gcd
#define __builtin_popcount __builtin_popcountll
//mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());
//int randt(int l, int r){ return (rando() % (r - l + 1) + l); }

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

const int N = 2e5 + 5;
int mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
ll infll = 1e18 + 7;

int f(int x){
    int ans = 0;
    while (x){
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

int greed(int x){
    int ans = 0, t = 1;
    while (x > 9){
        ans += 9 * t;
        t *= 10;
        x -= 9;
    }
    ans += x * t;
    return ans;
}

int tgreed(int x){
    if (x <= 8) return x;
    x -= 8;
    int ans = 8, t = 10;
    while (x > 9){
        ans += 9 * t;
        t *= 10;
        x -= 9;
    }
    ans += x * t;
    return ans;
}

int nn, k;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
int q; cin >> q; while (q--){
    cin >> nn >> k;
    k++;
    bool ck = 0;
    For(i, 0, 10){
        int n = nn;
        For(j, 0, k){
            n -= f(i + j);
        }
        if (n == 0){
            ck = 1;
            cout << i << endl;
            break;
        }
    }
    if (ck) continue;
    int ans = infll;
    For(y, 0, 10){ // last digit of x
        int n = nn;
        For(i, 0, k){
            n -= (y + i) % 10;
        }
        if (y + k <= 10){
            if (n < k) continue;
            if (n % k) continue;
            // cout << y << ' ' << greed(n / k) * 10 + y << endl;
            ans = min(ans, greed(n / k) * 10 + y);
            continue;
        }
        int m = 10 - y;
        if (n < m + (k - m) * 2) continue;
        int kek = 10;
        For(lst, 0, 17){ // number of end digit 9
            int _n = n - k + m - 9 * lst * m;
            if (_n < k){
                kek *= 10;
                continue;
            }
            if (_n % k){
                kek *= 10;
                continue;
            }
            // cout << y << ' ' << lst << ' ' << tgreed(_n / k) * kek + kek - 10 + y << endl;
            ans = min(ans, tgreed(_n / k) * kek + kek - 10 + y);
            kek *= 10;
        }
    }
    cout << (ans == infll ? -1 : ans) << endl;
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