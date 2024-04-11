#include<bits/stdc++.h>
using namespace std;

// Shortcut

//#define int long long
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

#define isvowel(a) (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
#define bend(a) a.begin(), a.end()
#define rbend(a) a.rbegin(), a.rend()
#define mset(a) memset(a, 0, sizeof(a));
#define mmset(a) memset(a, 0x3f, sizeof(a));
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

const int N = 1e5 + 5, mod = 1e9 + 7, inf = 1e9 + 7;

int n;
string a[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }
    a[0] = "0";
    ForE(i, 1, n){
        string s = a[i], t = a[i - 1];
        if (s.length() < t.length()){
            Ptest("NO");
        }
        if (s.length() > t.length()){
            For(j, 0, s.length()){
                if (s[j] == '?'){
                    if (j == 0) a[i][j] = '1';
                    else a[i][j] = '0';
                }
            }
            continue;
        }
        string pres = "", pret = "", ns;
        bool ck = 1;
        For(j, 0, s.length()){
            pres += s[j];
            pret += t[j];
            if (s[j] == '?'){
                pres[j] = (char)min(t[j] + 1, (int)'9');
            }
            //cout << pres << ' ' << pret << endl;
            if (pres > pret){
                ck = 0;
                ns = pres;
                For(k, j + 1, s.length()){
                    if (s[k] == '?') ns += '0';
                    else ns += s[k];
                }
                a[i] = min(a[i], ns);
            }
            if (s[j] == '?') pres[j] = pret[j];
        }
        if (ck) Ptest("NO");
    }
    cout << "YES" << endl;
    ForE(i, 1, n){
        cout << a[i] << endl;
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