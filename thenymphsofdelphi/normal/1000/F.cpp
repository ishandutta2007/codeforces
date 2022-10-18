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
int b[N], pos[N];
int ans[N];

struct query{
    int l, r, idx;
    query(int l = 0, int r = 0, int idx = 0){
        this->l = l;
        this->r = r;
        this->idx = idx;
    }
} que[N];

bool cmp(query x, query y){
    if (x.r != y.r) return x.r < y.r;
    return x.l < y.l;
}

struct segment_tree{
    pii seg[4 * N];
    
    void build(int id, int l, int r){
        if (l == r){
            seg[id] = {inf, l};
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        pii val1 = seg[id << 1], val2 = seg[id << 1 | 1];
        if (val1.fi <= val2.fi){
            seg[id] = val1;
        }
        else{
            seg[id] = val2;
        }
    }
    
    void update(int id, int l, int r, int i, int val){
        if (i < l || r < i){
            return;
        }
        if (l == r){
            seg[id] = {val, l};
            return;
        }
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, i, val);
        update(id << 1 | 1, mid + 1, r, i, val);
        pii val1 = seg[id << 1], val2 = seg[id << 1 | 1];
        if (val1.fi <= val2.fi){
            seg[id] = val1;
        }
        else{
            seg[id] = val2;
        }
    }
    
    pii get(int id, int l, int r, int u, int v){
        if (v < l || r < u){
            return {inf + 1, -1};
        }
        if (u <= l && r <= v){
            return seg[id];
        }
        int mid = (l + r) >> 1;
        pii val1 = get(id << 1, l, mid, u, v), val2 = get(id << 1 | 1, mid + 1, r, u, v);
        if (val1.fi <= val2.fi){
            return val1;
        }
        else{
            return val2;
        }
    }
} it;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ForE(i, 1, n) cin >> a[i];
    cin >> q;
    ForE(i, 1, q){
        int l, r; cin >> l >> r;
        que[i] = query(l, r, i);
    }
    sort(que + 1, que + 1 + q, cmp);
    it.build(1, 1, n);
    int curr = 0;
    ForE(i, 1, q){
        while (curr != que[i].r){
            curr++;
            it.update(1, 1, n, curr, pos[a[curr]]);
            if (pos[a[curr]] != 0){
                it.update(1, 1, n, pos[a[curr]], inf);
            }
            else{
                a[0] = a[curr];
            }
            pos[a[curr]] = curr;
        }
        pii tmp = it.get(1, 1, n, que[i].l, que[i].r);
        // ForE(j, 1, n){
        //     cout << it.get(1, 1, n, j, j) << ' ';
        // }
        // cout << endl << que[i].idx << endl;
        // cout << tmp.fi << ' ' << tmp.se << endl;
        if (tmp.fi >= que[i].l){
            ans[que[i].idx] = 0;
        }
        else{
            ans[que[i].idx] = a[tmp.se];
        }
    }
    ForE(i, 1, q){
        cout << ans[i] << endl;
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