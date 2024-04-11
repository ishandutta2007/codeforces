#include<bits/stdc++.h>
using namespace std;
 
// Optimization
 
//#pragma GCC optimize("O3")
#define endl '\n'
 
// Shortcut
 
// #define int long long
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
string s;
int a[N];
 
struct lazy_segment_tree{
    int segmn[4 * N], segmx[4 * N], lazy[4 * N];
    
    void down(int id, int l, int r){
        int mid = (l + r) >> 1;
        lazy[id << 1] += lazy[id];
        lazy[id << 1 | 1] += lazy[id];
        segmn[id << 1] += lazy[id];
        segmn[id << 1 | 1] += lazy[id];
        segmx[id << 1] += lazy[id];
        segmx[id << 1 | 1] += lazy[id];
        lazy[id] = 0;
    }
    
    void update(int id, int l, int r, int u, int v, int val){
        if (v < l || r < u){
            return;
        }
        if (u <= l && r <= v){
            segmn[id] += val;
            segmx[id] += val;
            lazy[id] += val;
            return;
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, u, v, val);
        update(id << 1 | 1, mid + 1, r, u, v, val);
        segmn[id] = min(segmn[id << 1], segmn[id << 1 | 1]);
        segmx[id] = max(segmx[id << 1], segmx[id << 1 | 1]);
    }
    
    int getmn(int id, int l, int r, int u, int v){
        if (v < l || r < u){
            return inf;
        }
        if (u <= l && r <= v){
            return segmn[id];
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        return min(getmn(id << 1, l, mid, u, v), getmn(id << 1 | 1, mid + 1, r, u, v));
    }
    
    int getmx(int id, int l, int r, int u, int v){
        if (v < l || r < u){
            return -inf;
        }
        if (u <= l && r <= v){
            return segmx[id];
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        return max(getmx(id << 1, l, mid, u, v), getmx(id << 1 | 1, mid + 1, r, u, v));
    }
} it;
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> s; s = ' ' + s;
    int pos = 1;
    ForE(i, 1, n){
        if (s[i] == 'L'){
            if (pos > 1){
                pos--;
            }
        }
        else if (s[i] == 'R'){
            pos++;
        }
        else{
            int tmp = 0;
            if (s[i] == '('){
                tmp++;
            }
            else if (s[i] == ')'){
                tmp--;
            }
            int dif = tmp - a[pos];
            a[pos] = tmp;
            it.update(1, 1, n, pos, n, dif);
        }
        int mn = it.getmn(1, 1, n, 1, n), lst = it.getmn(1, 1, n, n, n);
        // cout << endl << mn << ' ' << lst << endl;
        if (mn < 0 || lst){
            cout << -1 << ' ';
        }
        else{
            cout << it.getmx(1, 1, n, 1, n) << ' ';
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