#include<bits/stdc++.h>
using namespace std;

// Optimization

//#pragma GCC optimize("O3")
#define endl '\n'

// Shortcut

// #define int long long
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

const int N = 1e5 + 5, mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
const ll infll = 1e18 + 7;


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int q = 1;
    cin >> q;
    while (q--){
        string s; cin >> s;
        int n = s.length();
        vector<int> d1(n);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
                k++;
            }
            d1[i] = k--;
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }
        vector<int> d2(n);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
            while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
                k++;
            }
            d2[i] = k--;
            if (i + k > r) {
                l = i - k - 1;
                r = i + k ;
            }
        }
        // PrintV(d1); PrintV(d2);
        int l = 0, r = n - 1;
        while (l <= r){
            if (s[l] == s[r]){
                l++;
                r--;
            }
            else{
                break;
            }
        }
        l--;
        r++;
        int ans = 0, idx1 = -1, idx2 = -1, idx3 = -1;
        for (int i = 0; i < n; i++){
            if (i - d1[i] + 1 <= l + 1){
                if (ans < d1[i] * 2 - 1 + (i - d1[i] + 1) * 2 && d1[i] * 2 - 1 + (i - d1[i] + 1) * 2 <= n){
                    ans = d1[i] * 2 - 1 + (i - d1[i] + 1) * 2;
                    idx1 = i;
                    idx2 = 1;
                    idx3 = i - d1[i] + 1;
                    // cout << "A " << ans << ' ' << idx1 << ' ' << idx2 << ' ' << idx3 << endl;
                }
            }
            if (i + d1[i] - 1 >= r - 1){
                if (ans < d1[i] * 2 - 1 + (n - 1 - (i + d1[i] - 1)) * 2 && d1[i] * 2 - 1 + (n - 1 - (i + d1[i] - 1)) * 2 <= n){
                    ans = d1[i] * 2 - 1 + (n - 1 - (i + d1[i] - 1)) * 2;
                    idx1 = i;
                    idx2 = 1;
                    idx3 = n - 1 - (i + d1[i] - 1);
                    // cout << ans << ' ' << idx1 << ' ' << idx2 << ' ' << idx3 << endl;
                }
            }
        }
        for (int i = 0; i < n; i++){
            if (i - d2[i] <= l + 1){
                if (ans < d2[i] * 2 + (i - d2[i]) * 2 && d2[i] * 2 + (i - d2[i]) * 2 <= n){
                    ans = d2[i] * 2 + (i - d2[i]) * 2;
                    idx1 = i;
                    idx2 = 2;
                    idx3 = i - d2[i];
                    // cout << ans << ' ' << idx1 << ' ' << idx2 << ' ' << idx3 << endl;
                }
            }
            if (i + d2[i] - 1 >= r - 1){
                if (ans < d2[i] * 2 + (n - 1 - (i + d2[i] - 1)) * 2 && d2[i] * 2 + (n - 1 - (i + d2[i] - 1)) * 2 <= n){
                    ans = d2[i] * 2 + (n - 1 - (i + d2[i] - 1)) * 2;
                    idx1 = i;
                    idx2 = 2;
                    idx3 = n - 1 - (i + d2[i] - 1);
                    // cout << ans << ' ' << idx1 << ' ' << idx2 << ' ' << idx3 << endl;
                }
            }
        }
        for (int i = 0; i < n; i++){
            if (i < idx3 || (n - i) <= idx3 || (i >= idx1 - (idx2 == 1 ? d1[idx1] : d2[idx1] + 1) + 1 && i <= idx1 + (idx2 == 1 ? d1[idx1] : d2[idx1]) - 1)){
                cout << s[i];
            }
        }
        cout << endl;
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