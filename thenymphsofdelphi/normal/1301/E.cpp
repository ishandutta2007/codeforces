#include<bits/stdc++.h>
using namespace std;

// Optimization

//#pragma GCC optimize("O3")
#define endl '\n'

// Shortcut

//#define int long long
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

const int N = 5e2 + 5, K = log2(N) + 2, mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
const ll infll = 1e18 + 7;

int n, m, q;
char a[N][N];
int val[N][N];
int rmq[N][K][N][K];

int cal(int x1, int y1, int x2, int y2){
    if (x1 > x2 || y1 > y2) return -1;
	int tx = log2(x2 - x1 + 1), ty = log2(y2 - y1 + 1);
	return max(max(rmq[x1][tx][y1][ty], rmq[x1][tx][y2 - (1 << ty) + 1][ty]), max(rmq[x2 - (1 << tx) + 1][tx][y1][ty], rmq[x2 - (1 << tx) + 1][tx][y2 - (1 << ty) + 1][ty]));
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q;
    ForE(i, 1, n){
        ForE(j, 1, m){
            cin >> a[i][j];
        }
    }
    For(i, 1, n){
        For(j, 1, m){
            if (a[i][j] != 'R' || a[i][j + 1] != 'G' || a[i + 1][j] != 'Y' || a[i + 1][j + 1] != 'B') continue;
            int idx = 1, x, y;
            while (1){
                bool ck = 0;
                // R
                x = i - idx + 1, y = j - idx + 1;
                while (x != i + 1){
                    if (x < 1 || x > n || y < 1 || y > m || a[x][y] != 'R'){ ck = 1; break; }
                    x++;
                }
                if (ck){ /*cout << 1 << endl;*/ val[i][j] = idx - 1; break;}
                x = i - idx + 1, y = j - idx + 1;
                while (y != j + 1){
                    if (x < 1 || x > n || y < 1 || y > m || a[x][y] != 'R'){ ck = 1; break; }
                    y++;
                }
                if (ck){ /*cout << 2 << endl;*/ val[i][j] = idx - 1; break;}
                // G
                x = i - idx + 1, y = j + idx;
                while (x != i + 1){
                    if (x < 1 || x > n || y < 1 || y > m || a[x][y] != 'G'){ ck = 1; break; }
                    x++;
                }
                if (ck){ /*cout << 3 << endl;*/ val[i][j] = idx - 1; break;}
                x = i - idx + 1, y = j + idx;
                while (y != j){
                    if (x < 1 || x > n || y < 1 || y > m || a[x][y] != 'G'){ ck = 1; break; }
                    y--;
                }
                if (ck){ /*cout << 4 << endl;*/ val[i][j] = idx - 1; break;}
                // Y
                x = i + idx, y = j - idx + 1;
                while (x != i){
                    if (x < 1 || x > n || y < 1 || y > m || a[x][y] != 'Y'){ ck = 1; break; }
                    x--;
                }
                if (ck){ /*cout << 5 << endl;*/ val[i][j] = idx - 1; break;}
                x = i + idx, y = j - idx + 1;
                while (y != j + 1){
                    if (x < 1 || x > n || y < 1 || y > m || a[x][y] != 'Y'){ ck = 1; break; }
                    y++;
                }
                if (ck){ /*cout << 6 << endl;*/ val[i][j] = idx - 1; break;}
                // B
                x = i + idx, y = j + idx;
                while (x != i){
                    if (x < 1 || x > n || y < 1 || y > m || a[x][y] != 'B'){ ck = 1; break; }
                    x--;
                }
                if (ck){ /*cout << 7 << endl;*/ val[i][j] = idx - 1; break;}
                x = i + idx, y = j + idx;
                while (y != j){
                    if (x < 1 || x > n || y < 1 || y > m || a[x][y] != 'B'){ ck = 1; break; }
                    y--;
                }
                if (ck){ /*cout << 8 << endl;*/ val[i][j] = idx - 1; break;}
                idx++;
            }
        }
    }
    // For(i, 1, n){
    //     For(j, 1, m){
    //         cout << val[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    
    For(i, 1, n){
        For(j, 1, m){
            rmq[i][0][j][0] = val[i][j];
        }
    }
    For(i, 1, n){
        For(l, 1, K){
            For(j, 1, m - (1 << l) + 1){
                rmq[i][0][j][l] = max(rmq[i][0][j][l - 1], rmq[i][0][j + (1 << (l - 1))][l - 1]);
            }
        }
    }
    For(k, 1, K){
        For(i, 1, n - (1 << k) + 1){
            For(l, 0, K){
                For(j, 1, m){
                    rmq[i][k][j][l] = max(rmq[i][k - 1][j][l], rmq[i + (1 << (k - 1))][k - 1][j][l]);
                }
            }
        }
    }
    while (q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2; x2--; y2--;
        if (x1 > x2 || y1 > y2){ cout << 0 << endl; continue; }
        int idx = 1;
        int l = 0, r = min(x2 - x1, y2 - y1) / 2 + 1;
        while (l < r){
            int mid = (l + r + 1) >> 1;
            //cout << mid << ' ' << x1 + mid - 1 << ' ' << y1 + mid - 1 << ' ' << x2 - mid + 1 << ' ' << y2 - mid + 1 << endl;
            int tmp = cal(x1 + mid - 1, y1 + mid - 1, x2 - mid + 1, y2 - mid + 1);
            if (tmp >= mid){
                l = mid;
            }
            else{
                r = mid - 1;
            }
        }
        cout << (ll)l * l * 4ll << endl;
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