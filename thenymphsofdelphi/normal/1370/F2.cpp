#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// Optimization

//#pragma GCC optimize("O3")
// #define endl '\n'

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
//int randt(int l, int r){ return (rando() % (r - l + 1) + l); }

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

const int N = 1e3 + 5;
int mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
ll infll = 1e18 + 7;

int n;
vi adj[N];
int h[N];

pii ask(bool all, vi _ask){
    if (all){
        ForE(i, 1, n){
            _ask.pb(i);
        }
    }
    cout << "? " << _ask.size() << ' ';
    Fora(v, _ask) cout << v << ' ';
    cout << endl;
    pii ans; cin >> ans.fi >> ans.se;
    if (ans.fi == -1 && ans.se == -1) exit(0);
    return ans;
}

void answer(int x, int y){
    cout << "! " << x << ' ' << y << endl;
    string s; cin >> s;
    if (s != "Correct") exit(0);
}

void dfs(int u, int p){
    if (u == p) h[u] = -1;
    h[u] = h[p] + 1;
    Fora(v, adj[u]){
        if (v == p) continue;
        dfs(v, u);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
int q; cin >> q; while (q--){
    cin >> n;
    ForE(i, 1, n){
        adj[i].clear();
    }
    For(i, 1, n){
        int u, v; cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }
    pii ansquery;
    ansquery = ask(true, {});
    int d = ansquery.se;
    dfs(ansquery.fi, ansquery.fi);
//     PrintA(h, 1, n);
    int l = (d + 1) / 2 - 1, r = d;
    map <int, int> mpp;
    while (l < r){
        int mid = (l + r + 1) >> 1;
        if (mid == d + 1) break;
        vi vquery;
        ForE(i, 1, n){
            if (h[i] == mid){
                vquery.pb(i);
            }
        }
        if (vquery.size() == 0){
            r = mid - 1;
            continue;
        }
//		cout << "KEK " << mid << endl;
        ansquery = ask(false, vquery);
        mpp[mid] = ansquery.fi;
        if (ansquery.se == d){
            l = mid;
        }
        else{
            r = mid - 1;
        }
    }
    int vx = mpp[l];
    dfs(vx, vx);
    // cout << "A" << endl;
    // PrintA(h, 1, n);
    vi vquery;
    ForE(i, 1, n){
        if (h[i] == d){
            vquery.pb(i);
        }
    }
    ansquery = ask(false, vquery);
    answer(vx, ansquery.fi);
}
}

/*
==================================+
INPUT:                            |
------------------------------    |
1
8
2 4
1 8
5 6
5 7
8 2
3 7
7 4

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/