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
const ll infll = 1e18 + 7;

vi d[N];
int ans, a[3], cnt[8];

bool gay(int x, int y, int z){
    int b[3] = {x, y, z};
    do{
        if ((b[0] & 1) && (b[1] & 2) && (b[2] & 4)) return 1;
    } while (next_permutation(b, b + 3));
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
For(i, 1, N){
    for (int j = i; j < N; j += i){
        d[j].pb(i);
    }
}
int q; cin >> q; while (q--){
    mset(cnt);
    For(i, 0, 3){
        cin >> a[i];
    }
    For(i, 0, 3){
        Fora(v, d[a[i]]){
            int val = 0;
            For(j, 0, 3){
                if (a[j] % v == 0) val += (1 << j);
            }
            cnt[val]++;
        }
    }
    For(i, 1, 8){
        cnt[i] /= __builtin_popcount(i);
    }
    int ans = 0;
    For(i, 1, 8){
        For(j, i + 1, 8){
            For(k, j + 1, 8){
                if (gay(i, j, k)){
                    ans += cnt[i] * cnt[j] * cnt[k];
                }
            }
        }
    }
    For(i, 1, 8){
        For(j, i + 1, 8){
            if (gay(i, i, j)){
                ans += (cnt[i] + cnt[i] * (cnt[i] - 1) / 2) * cnt[j];
            }
            if (gay(i, j, j)){
                ans += (cnt[j] + cnt[j] * (cnt[j] - 1) / 2) * cnt[i];
            }
        }
    }
    ans += (cnt[7] + cnt[7] * (cnt[7] - 1) + cnt[7] * (cnt[7] - 1) * (cnt[7] - 2) / 6);
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