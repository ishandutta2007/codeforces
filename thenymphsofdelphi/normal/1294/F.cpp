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

#define PrintV(a) Fora(iiii, a) cout << iiii << ' ';
#define PrintVl(a) Fora(iiii, a) cout << iiii << endl;
#define PrintA(a, l, r) for (int iiii = l; iiii <= r; iiii++) cout << a[iiii] << ' ';
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

const int N = 2e5 + 5, mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
const ll infll = 1e18 + 7;

int n, diadist;
vi adj[N];
int dist[N], par[N];
bool ck[N];

void dfs(int u, int p = -1){
    if (p != -1){
        dist[u] = dist[p] + 1;
    }
    else{
        dist[u] = 0;
    }
    Fora(v, adj[u]){
        if (v == p) continue;
        dfs(v, u);
    }
}

pii diameter(){
    pii ans;
    int mx;
    dfs(1);
    mx = -1;
    ForE(i, 1, n){
        if (dist[i] > mx){
            mx = dist[i];
            ans.fi = i;
        }
    }
    mset(dist);
    dfs(ans.fi);
    mx = -1;
    ForE(i, 1, n){
        if (dist[i] > mx){
            mx = dist[i];
            ans.se = i;
        }
    }
    diadist = mx;
    return ans;
}

void dfs2(int u, int p = -1){
    par[u] = p;
    Fora(v, adj[u]){
        if (v == p){
            continue;
        }
        dfs2(v, u);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    For(i, 1, n){
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    pii ans = diameter();
    if (diadist == n - 1){
        ForE(i, 1, n){
            if (i != ans.fi && i != ans.se){
                cout << diadist << endl;
                cout << ans.fi << ' ' << ans.se << ' ' << i << endl;
                return 0;
            }
        }
    }
    dfs2(ans.fi);
    int rdist, thi;
    queue <pii > qu;
    int vt = ans.se;
    while (vt != ans.fi){
        qu.push({vt, 0});
        ck[vt] = 1;
        vt = par[vt];
    }
    qu.push({vt, 0});
    ck[vt] = 1;
    while (!qu.empty()){
        pii t = qu.front();
        qu.pop();
        ck[t.fi] = 1;
        rdist = t.se;
        thi = t.fi;
        Fora(v, adj[t.fi]){
            if (ck[v]) continue;
            qu.push({v, t.se + 1});
            ck[v] = 1;
        }
    }
    cout << diadist + rdist << endl;
    cout << ans.fi << ' ' << ans.se << ' ' << thi << endl;
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