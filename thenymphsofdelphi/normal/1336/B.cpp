#include<bits/stdc++.h>
using namespace std;

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
const ll infll = 3e18 + 7;

int n[4];
int a[4][N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
int q; cin >> q; while (q--){
    int ans = infll;
    ForE(j, 1, 3) cin >> n[j];
    ForE(j, 1, 3){
        ForE(i, 1, n[j]){
            cin >> a[j][i];
        }
        sort(a[j] + 1, a[j] + n[j] + 1);
    }
    vi perm = {1, 2, 3};
    do{
        int nd1 = perm[0], nd2 = perm[1], nd3 = perm[2];
        For(msk1, 0, 3){ // Direction
            For(msk2, 0, 4){ // L/R
                ForE(idx1, 1, n[nd1]){
                    int idx2, idx3;
                    if (msk1 == 0){
                        idx2 = (msk2 & 1 ? lwb(a[nd2] + 1, a[nd2] + n[nd2] + 1, a[nd1][idx1]) - a[nd2]
                                         : upb(a[nd2] + 1, a[nd2] + n[nd2] + 1, a[nd1][idx1]) - a[nd2] - 1);
                        idx3 = (msk2 & 2 ? lwb(a[nd3] + 1, a[nd3] + n[nd3] + 1, a[nd1][idx1]) - a[nd3]
                                         : upb(a[nd3] + 1, a[nd3] + n[nd3] + 1, a[nd1][idx1]) - a[nd3] - 1);
                    }
                    if (msk1 == 1){
                        idx2 = (msk2 & 1 ? lwb(a[nd2] + 1, a[nd2] + n[nd2] + 1, a[nd1][idx1]) - a[nd2]
                                         : upb(a[nd2] + 1, a[nd2] + n[nd2] + 1, a[nd1][idx1]) - a[nd2] - 1);
                        idx3 = (msk2 & 2 ? lwb(a[nd3] + 1, a[nd3] + n[nd3] + 1, a[nd2][idx2]) - a[nd3]
                                         : upb(a[nd3] + 1, a[nd3] + n[nd3] + 1, a[nd2][idx2]) - a[nd3] - 1);
                    }
                    if (msk1 == 2){
                        idx3 = (msk2 & 2 ? lwb(a[nd3] + 1, a[nd3] + n[nd3] + 1, a[nd1][idx1]) - a[nd3]
                                         : upb(a[nd3] + 1, a[nd3] + n[nd3] + 1, a[nd1][idx1]) - a[nd3] - 1);
                        idx2 = (msk2 & 1 ? lwb(a[nd2] + 1, a[nd2] + n[nd2] + 1, a[nd3][idx3]) - a[nd2]
                                         : upb(a[nd2] + 1, a[nd2] + n[nd2] + 1, a[nd3][idx3]) - a[nd2] - 1);
                    }
                    if (idx2 < 1 || idx2 > n[nd2] || idx3 < 1 || idx3 > n[nd3]) continue;
                    // cout << nd1 << ' ' << idx1 << endl;
                    // cout << nd2 << ' ' << idx2 << endl;
                    // cout << nd3 << ' ' << idx3 << endl;
                    // cout << ans << ' ' << (a[nd1][idx1] - a[nd2][idx2]) << ' ' << (a[nd2][idx2] - a[nd3][idx3]) << ' ' << (a[nd3][idx3] - a[nd1][idx1]) << endl;
                    ans = min(ans, (a[nd1][idx1] - a[nd2][idx2]) * (a[nd1][idx1] - a[nd2][idx2]) +
                                  (a[nd2][idx2] - a[nd3][idx3]) * (a[nd2][idx2] - a[nd3][idx3]) +
                                  (a[nd3][idx3] - a[nd1][idx1]) * (a[nd3][idx3] - a[nd1][idx1]));
                }
            }
        }
        // ForE(idx1, 1, n[nd1]){
        //     int idx2 = lwb(a[nd2] + 1, a[nd2] + n[nd2] + 1, a[nd1][idx1]) - a[nd2], idx3 = lwb(a[nd3] + 1, a[nd3] + n[nd3] + 1, a[nd2][idx2]) - a[nd3];
        //     idx2 = max(idx2, 1ll);
        //     idx2 = min(idx2, n[nd2]);
        //     idx3 = max(idx3, 1ll);
        //     idx3 = min(idx3, n[nd3]);
        //     int dif = a[nd3][idx3] - a[nd1][idx1];
        //     dif /= 2;
        //     dif += a[nd1][idx1];
        //     int idx21 = lwb(a[nd2] + 1, a[nd2] + n[nd2] + 1, dif / 2) - a[nd2];
        //     int idx22 = upb(a[nd2] + 1, a[nd2] + n[nd2] + 1, dif / 2) - a[nd2] - 1;
        //     idx21 = max(idx21, 1ll);
        //     idx21 = min(idx21, n[nd2]);
        //     idx22 = max(idx22, 1ll);
        //     idx22 = min(idx22, n[nd2]);
        //     // cout << nd1 << ' ' << idx1 << endl;
        //     // cout << nd2 << ' ' << idx21 << ' ' << idx22 << endl;
        //     // cout << nd3 << ' ' << idx3 << endl;
        //     ans = min(ans, (a[nd1][idx1] - a[nd2][idx21]) * (a[nd1][idx1] - a[nd2][idx21]) +
        //                   (a[nd2][idx21] - a[nd3][idx3]) * (a[nd2][idx21] - a[nd3][idx3]) +
        //                   (a[nd3][idx3] - a[nd1][idx1]) * (a[nd3][idx3] - a[nd1][idx1]));
        //     ans = min(ans, (a[nd1][idx1] - a[nd2][idx22]) * (a[nd1][idx1] - a[nd2][idx22]) +
        //                   (a[nd2][idx22] - a[nd3][idx3]) * (a[nd2][idx22] - a[nd3][idx3]) +
        //                   (a[nd3][idx3] - a[nd1][idx1]) * (a[nd3][idx3] - a[nd1][idx1]));
        // }
    } while (next_permutation(bend(perm)));
    cout << ans << endl;
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