#include<bits/stdc++.h>
using namespace std;

// Shortcut

#pragma optimize ("O3")
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

//#define isvowel(a) (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
#define bend(a) a.begin(), a.end()
#define rbend(a) a.rbegin(), a.rend()
#define mset(a) memset(a, 0, sizeof(a));
#define mmset(a) memset(a, 0x3f, sizeof(a));
//mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());

// Data Structure

#define pque priority_queue
#define mts multiset
#define y0 _y0_
#define y1 _y1_
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

const int N = 2e5 + 5, M = 5, mod = 1e9 + 7, inf = 1e9 + 7;

int n, k, q;
int a[N][M], b[M];

struct segment_tree{
    int seg[4 * N][1 << M];
    
    void build(int id, int l, int r){
        if (l == r){
            For(i, 0, (1 << k)){
                int sum = 0;
                For(j, 0, k){
                    if (i & (1 << j)){
                        sum += a[l][j];
                    }
                    else{
                        sum -= a[l][j];
                    }
                    seg[id][i] = sum;
                }
            }
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        For(i, 0, (1 << k)){
            seg[id][i] = min(seg[id << 1][i], seg[id << 1 | 1][i]);
        }
    }
    
    void upd(int id, int l, int r, int i){
        if (i < l || r < i){
            return;
        }
        if (l == r){
            For(i, 0, (1 << k)){
                int sum = 0;
                For(j, 0, k){
                    if (i & (1 << j)){
                        sum += b[j];
                    }
                    else{
                        sum -= b[j];
                    }
                }
                seg[id][i] = sum;
            }
            return;
        }
        int mid = (l + r) >> 1;
        upd(id << 1, l, mid, i);
        upd(id << 1 | 1, mid + 1, r, i);
        For(i, 0, (1 << k)){
            seg[id][i] = min(seg[id << 1][i], seg[id << 1 | 1][i]);
        }
    }
    
    int get(int id, int l, int r, int u, int v, int id2){
        if (v < l || r < u){
            return inf;
        }
        if (u <= l && r <= v){
            return seg[id][id2];
        }
        int mid = (l + r) >> 1;
        return min(get(id << 1, l, mid, u, v, id2), get(id << 1 | 1, mid + 1, r, u, v, id2));
    }
} it1;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    ForE(i, 1, n){
        For(j, 0, k){
            cin >> a[i][j];
        }
    }
    it1.build(1, 1, n);
    cin >> q;
    while (q--){
        int id;
        cin >> id;
        if (id == 1){
            int x;
            cin >> x;
            For(i, 0, k){
                cin >> b[i];
            }
            it1.upd(1, 1, n, x);
        }
        else{
            int x, y;
            cin >> x >> y;
            int ans = -1;
            For(i, 0, (1 << k)){
                ans = max(ans, abs(it1.get(1, 1, n, x, y, i) + it1.get(1, 1, n, x, y, (((1 << k) - 1) ^ i))));
            }
            cout << ans << endl;
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