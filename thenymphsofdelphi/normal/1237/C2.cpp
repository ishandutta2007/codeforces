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

const int N = 5e4 + 5, mod = 1e9 + 7, mod1 = 998242353, mod2 = 1e9 + 9, inf = 1e9 + 7;
const ll infll = 1e18 + 7;

struct node{
    int x, y, z;
    int idx;
} a[N];

bool cmp(node a, node b){
    if (a.x != b.x) return a.x < b.x;
    if (a.y != b.y) return a.y < b.y;
    if (a.z != b.z) return a.z < b.z;
    return a.idx < b.idx;
}

int n;
vector <node> tmp1, tmp2, tmp3;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    ForE(i, 1, n){
        int x, y, z;
        cin >> x >> y >> z;
        a[i].x = x;
        a[i].y = y;
        a[i].z = z;
        a[i].idx = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    tmp3.pb(a[1]);
    ForE(i, 2, n){
        if (a[i].x == a[i - 1].x){
            if (a[i].y == a[i - 1].y){
                tmp3.pb(a[i]);
            }
            else{
                For(j, 0, tmp3.size()){
                    if (j + 1 < tmp3.size()){
                        cout << tmp3[j].idx << ' ' << tmp3[j + 1].idx << endl;
                        j++;
                    }
                }
                if ((int)tmp3.size() & 1){
                    tmp2.pb(tmp3.back());
                }
                tmp3.clear();
                tmp3.pb(a[i]);
            }
        }
        else{
            For(j, 0, tmp3.size()){
                if (j + 1 < tmp3.size()){
                    cout << tmp3[j].idx << ' ' << tmp3[j + 1].idx << endl;
                    j++;
                }
            }
            if ((int)tmp3.size() & 1){
                tmp2.pb(tmp3.back());
            }
            tmp3.clear();
            For(j, 0, tmp2.size()){
                if (j + 1 < tmp2.size()){
                    cout << tmp2[j].idx << ' ' << tmp2[j + 1].idx << endl;
                    j++;
                }
            }
            if ((int)tmp2.size() & 1){
                tmp1.pb(tmp2.back());
            }
            tmp2.clear();
            tmp3.pb(a[i]);
        }
        // cout << "A ";
        // Fora(v, tmp1){
        //     cout << v.idx << ' ';
        // }
        // cout << endl;
        // cout << "A ";
        // Fora(v, tmp2){
        //     cout << v.idx << ' ';
        // }
        // cout << endl;
        // cout << "A ";
        // Fora(v, tmp3){
        //     cout << v.idx << ' ';
        // }
        // cout << endl;
    }
    For(j, 0, tmp3.size()){
        if (j + 1 < tmp3.size()){
            cout << tmp3[j].idx << ' ' << tmp3[j + 1].idx << endl;
            j++;
        }
    }
    if ((int)tmp3.size() & 1){
        tmp2.pb(tmp3.back());
    }
    tmp3.clear();
    For(j, 0, tmp2.size()){
        if (j + 1 < tmp2.size()){
            cout << tmp2[j].idx << ' ' << tmp2[j + 1].idx << endl;
            j++;
        }
    }
    if ((int)tmp2.size() & 1){
        tmp1.pb(tmp2.back());
    }
    tmp2.clear();
    For(j, 0, tmp1.size()){
        if (j + 1 < tmp1.size()){
            cout << tmp1[j].idx << ' ' << tmp1[j + 1].idx << endl;
            j++;
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