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

const int N = 5e5 + 5, mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
const ll infll = 1e18 + 7;

int n, q;
int a[N];
int tid, tl, tr, cnt;
vector <pair <int, pii> > deb;

struct segment_tree{
    int seg[4 * N];
    
    void build(int id, int l, int r){
        deb.pb({id, {l, r}});
        if (l == r){
            seg[id] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        seg[id] = __gcd(seg[id << 1], seg[id << 1 | 1]);
    }
    
    void update(int id, int l, int r, int i, int val){
        if (i < l || r < i){
            return;
        }
        if (l == r){
            seg[id] = val;
            return;
        }
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, i, val);
        update(id << 1 | 1, mid + 1, r, i, val);
        seg[id] = __gcd(seg[id << 1], seg[id << 1 | 1]);
    }
    
    void get1(int id, int l, int r, int u, int v, int val){
        if (v < l || r < u){
            return;
        }
        if (u <= l && r <= v){
            if (seg[id] % val){
                cnt++;
                tid = id;
                tl = l;
                tr = r;
            }
            return;
        }
        int mid = (l + r) >> 1;
        get1(id << 1, l, mid, u, v, val);
        get1(id << 1 | 1, mid + 1, r, u, v, val);
        return;
    }
    
    bool get2(int id, int l, int r, int val){
        if (l == r){
            return true;
        }
        int mid = (l + r) >> 1;
        if ((seg[id << 1] % val) && (seg[id << 1 | 1] % val)){
            return false;
        }
        if (seg[id << 1] % val){
            return get2(id << 1, l, mid, val);
        }
        return get2(id << 1 | 1, mid + 1, r, val);
    }
} it;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }
    it.build(1, 1, n);
    cin >> q;
    while (q--){
        int que; cin >> que;
        if (que == 1){
            int l, r, val; cin >> l >> r >> val;
            tl = 0; tr = 0; cnt = 0;
            it.get1(1, 1, n, l, r, val);
            if (cnt == 0){
                cout << "YES" << endl;
                continue;
            }
            if (cnt >= 2){
                cout << "NO" << endl;
                continue;
            }
            if (it.get2(tid, tl, tr, val)){
                cout << "YES" << endl;
                continue;
            }
            cout << "NO" << endl;
        }
        else{
            int i, val;
            cin >> i >> val;
            it.update(1, 1, n, i, val);
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