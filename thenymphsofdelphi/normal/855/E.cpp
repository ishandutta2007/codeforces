#include<bits/stdc++.h>
using namespace std;

// Shortcut

#define int long long
#define endl '\n'
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
#define mset(a) memset(a, 0, sizeof(a));
//mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());

// Data Structure

#define pque priority_queue
#define mts multiset
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

const int N = 5e3 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

int b;
int dp[11][64][1024];
int num[61];

int solve (int pos, int mk1, bool mk2, int z){
    if (!pos){
        if (!z){
            return (mk1 == 0);
        }
        return 0;
    }
    if (!mk2 && !z && dp[b][pos][mk1] != -1){
        return dp[b][pos][mk1];
    }
    int ans = 0, n = (mk2 ? (num[pos - 1] + 1) : b);
    int tmk1, tmk2, tz;
    For(i, 0, n){
        tmk1 = (((z) && (i == 0)) ? mk1 : (mk1 ^ (1ll << i)));
        tmk2 = ((mk2) && (i == n - 1)) ? 1 : 0;
        tz = (((z) && (i == 0)) ? 1 : 0);
        ans += solve(pos - 1, tmk1, tmk2, tz);
    }
    if (!mk2 && !z){
        return dp[b][pos][mk1] = ans;
    }
    return ans;
}

int ans (int r){
    int cnt = 0;
    while (r){
        num[cnt++] = r % b;
        r /= b;
    }
    return solve(cnt, 0, 1, 1);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    int q;
    cin >> q;
    while (q--){
        int l, r;
        cin >> b >> l >> r;
        cout << ans(r) - ans(l - 1) << endl;
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