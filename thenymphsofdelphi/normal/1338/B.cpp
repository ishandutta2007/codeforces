#include<bits/stdc++.h>
using namespace std;

// Optimization

// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("O3")
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

const int N = 2e5 + 5, M = log2(N) + 1, mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
const ll infll = 1e18 + 7;

int n;
int a[N];
vi adj[N];
int memo[N][M + 1], h[N];

void dfs(int u, int p){
    memo[u][0] = p;
    ForE(i, 1, M){
        memo[u][i] = memo[memo[u][i - 1]][i - 1];
    }
    Fora(v, adj[u]){
        if (v != p){
            h[v] = h[u] + 1;
            dfs(v, u);
        }
    }
}

int lca(int u, int v){
    if (h[u] < h[v]){
        swap(u, v);
    }
    FordE(i, M, 0){
        if (h[u] - (1 << i) >= h[v]){
            u = memo[u][i];
        }
    }
    if (u == v){
        return u;
    }
    FordE(i, M, 0){
        if (memo[u][i] != memo[v][i]){
            u = memo[u][i];
            v = memo[v][i];
        }
    }
    return memo[u][0];
}

int dis(int u, int v){
    int p = lca(u, v);
    return h[u] + h[v] - 2 * h[p];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    For(i, 1, n){
        int u, v; cin >> u >> v; a[u]++; a[v]++; adj[u].pb(v); adj[v].pb(u);
    }
    int rt;
    ForE(i, 1, n){
        if (a[i] != 1){
            rt = i;
            break;
        }
    }
    dfs(rt, rt);
    set <int> stt;
    set <pii> stt2;
    int ans = n - 1;
    ForE(i, 1, n){
        if (a[i] == 1){
            stt.insert(h[i] % 2);
            if (stt2.find({h[i], memo[i][0]}) != stt2.end()) ans--;
            else stt2.insert({h[i], memo[i][0]});
        }
    }
    if (stt.size() == 1){
        cout << 1 << ' ';
    }
    else{
        cout << 3 << ' ';
    }
    cout << ans << endl;
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