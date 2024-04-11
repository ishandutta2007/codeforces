#include<bits/stdc++.h>
using namespace std;

// Optimization

//#pragma GCC optimize("O3")
//#define endl '\n'

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

const int N = 1e3 + 5, mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e18 + 7;
const ll infll = 1e18 + 7;

int n, m;
map <int, int> mpp;
int a[2 * N], b[2 * N], islarge[2 * N], ck[2 * N];

signed main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    cin >> n >> m;
    ForE(i, 1, 2 * n){
        cin >> a[i];
        ck[i] = 1;
    }
    ForE(i, 1, m){
        int x, y; cin >> x >> y;
        b[x] = y; b[y] = x;
        if (a[x] >= a[y]) islarge[x] = 1;
        else islarge[y] = 1;
    }
    int turn; cin >> turn;
    if (turn == 1){
        ForE(j, 1, m){
            ForE(i, 1, 2 * n){
                if (ck[i] && islarge[i]){
                    cout << i << endl;
                    ck[i] = 0;
                    break;
                }
            }
            int que; cin >> que; if (que == -1) return 0;
            ck[que] = 0;
        }
        ForE(j, 1, n - m){
            int mx = 0, idx;
            ForE(i, 1, 2 * n){
                if (ck[i] && a[i] > mx){
                    mx = a[i];
                    idx = i;
                }
            }
            cout << idx << endl;
            ck[idx] = 0;
            int que; cin >> que; if (que == -1) return 0;
            ck[que] = 0;
        }
        return 0;
    }
    else{
    	ForE(j, 1, n){
	        int que; cin >> que;
	        ck[que] = 0;
	        if (ck[b[que]]){
	            cout << b[que] << endl;
	            ck[b[que]] = 0;
	            m--;
	        }
	        else{
	            if (m){
	                ForE(i, 1, 2 * n){
	                    if (ck[i] && islarge[i]){
	                        cout << i << endl;
	                        ck[i] = 0;
	                        m--;
	                        break;
	                    }
	                }
	            }
	            else{
	                int mx = 0, idx;
	                ForE(i, 1, 2 * n){
	                    if (ck[i] && a[i] > mx){
	                        mx = a[i];
	                        idx = i;
	                    }
	                }
	                cout << idx << endl;
	                ck[idx] = 0;
	            }
	        }
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