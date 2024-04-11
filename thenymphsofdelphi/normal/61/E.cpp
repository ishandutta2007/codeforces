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

const int N = 1e6 + 5, mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
const ll infll = 1e18 + 7;

int n;
int a[N];
set <int> st; map <int, int> mpp;
ll ans;

struct lazy_segment_tree{ // Sum query
    int seg[4 * N], lazy[4 * N];
    
    void down(int id, int l, int r){ // "Push" lazy value down
        int mid = (l + r) >> 1;
        lazy[id << 1] += lazy[id];
        lazy[id << 1 | 1] += lazy[id];
        seg[id << 1] += lazy[id] * (mid - l + 1);
        seg[id << 1 | 1] += lazy[id] * (r - mid);
        lazy[id] = 0;
    }
    
    void build(int id, int l, int r){ // Build lazy segment tree
        if (l == r){
            seg[id] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        seg[id] = seg[id << 1] + seg[id << 1 | 1];
    }
    
    void update(int id, int l, int r, int u, int v, int val){ // Add val to a[i] : u <= i <= v
        if (v < l || r < u){
            return;
        }
        if (u <= l && r <= v){
            seg[id] += (r - l + 1) * val;
            lazy[id] += val;
            return;
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, u, v, val);
        update(id << 1 | 1, mid + 1, r, u, v, val);
        seg[id] = seg[id << 1] + seg[id << 1 | 1];
    }
    
    int get(int id, int l, int r, int u, int v){ // Get sum of a[i] : u <= i <= v
        if (v < l || r < u){
            return 0;
        }
        if (u <= l && r <= v){
            return seg[id];
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
    }
} it;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
        st.insert(a[i]);
    }
    int idx = 0;
    Fora(v, st){
        idx++;
        mpp[v] = idx;
    }
    ForE(i, 1, n){
        a[i] = mpp[a[i]];
    }
    ForE(i, 1, n){
        int tmp = it.get(1, 1, n, a[i], a[i]);
        //cout << i << ' ' << a[i] << ' ' << tmp << ' ' << (a[i] - 1 - (i - 1 - tmp)) << endl;
        ans += (ll)tmp * (ll)(a[i] - 1 - (i - 1 - tmp));
        it.update(1, 1, n, 1, a[i], 1);
    }
    cout << ans;
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