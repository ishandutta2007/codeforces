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

const int N = 1e6 + 5, base = 64, mod = 1000003999, inf = 1e9 + 7;

int n;
string a[100005];
int hsh[N];
vi hashs[100005];
int powbase[N];

int cnv(char x){
    if (x >= 'A' && x <= 'Z'){
        return x - 'A' + 1;
    }
    if (x >= 'a'){
        return x - 'a' + 27;
    }
    return x - '0' + 53;
}

int binpow(int x, int y){
    int ans = 1;
    while (y){
        if (y & 1ll) ans = (ans * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return ans;
}

int geta(int l, int r){ // 0-indexed
    if (l > r) return 0;
    return ((hsh[r] - ((l <= 0 ? 0 : hsh[l - 1]) * powbase[r - l + 1]) % mod) % mod + mod) % mod;
}

int getb(int i, int l, int r){ // 0-indexed
    if (l > r) return 0;
    return ((hashs[i][r] - ((l <= 0 ? 0 : hashs[i][l - 1]) * powbase[r - l + 1]) % mod) % mod + mod) % mod;
}

signed main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    powbase[0] = 1;
    For(i, 1, N){
        powbase[i] = (powbase[i - 1] * base) % mod;
    }
    cin >> n;
    cin >> a[1];
    ForE(i, 2, n){
        cin >> a[i];
        hashs[i].pb(cnv(a[i][0]));
        For(j, 1, a[i].length()){
            hashs[i].pb((hashs[i][j - 1] * base + cnv(a[i][j])) % mod);
        }
    }
    hsh[0] = cnv(a[1][0]);
    For(i, 1, a[1].length()){
        hsh[i] = (hsh[i - 1] * base + cnv(a[1][i])) % mod;
    }
    ForE(i, 2, n){
        int t = a[1].length(), l = 0;
        For(j, 0, min(a[1].length(), a[i].length())){
            if (geta(a[1].length() - j - 1, a[1].length() - 1) == getb(i, 0, j)){
                l = j + 1;
            }
            //cout << geta(a[1].length() - j - 1, a[1].length() - 1) << ' ' << getb(i, 0, j) << endl;
        }
        //cout << l << endl;
        a[1] += a[i].substr(l, a[i].length() - l);
        //cout << a[i].substr(l, a[i].length() - l) << endl;
        //cout << t << ' ' << a[1] << endl;
        For(i, t, a[1].length()){
            hsh[i] = ((hsh[i - 1] * base + cnv(a[1][i])) % mod);
        }
    }
    cout << a[1];
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