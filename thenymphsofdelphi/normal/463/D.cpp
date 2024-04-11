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

const int N = 1e3 + 5, mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
const ll infll = 1e18 + 7;

int n, m, ans;
int a[N][6], b[N][6];
vi adj[N], toposort[N];
int dist[N];
int ckdag[N];
bool ck[N];

struct dsu{
    int par[N];
    
    void init(){
        msetn1(par);
    }

    int root(int x){
        return par[x] < 0 ? x : par[x] = root(par[x]);
    }

    void merge(int x, int y){
        if ((x = root(x)) == (y = root(y))){
            return;
        }
        if (par[y] < par[x]){
            swap(x, y);
        }
        par[x] += par[y];
        par[y] = x;
    }
} dsu1;

void dfs(int u){
    ck[u] = 1;
    Fora(v, adj[u]){
        if (!ck[v]){
            dfs(v);
        }
    }
    toposort[ckdag[u]].pb(u);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    ForE(j, 1, m){
        ForE(i, 1, n){
            cin >> a[i][j];
            b[a[i][j]][j] = i;
        }
    }
    dsu1.init();
    ForE(i, 1, n){
        ForE(j, i + 1, n){
            int x = 0, y = 0;
            ForE(k, 1, m){
                if (b[i][k] > b[j][k]) x++;
                else y++;
            }
            if (x == 0){
                adj[i].pb(j);
                dsu1.merge(i, j);
            }
            if (y == 0){
                adj[j].pb(i);
                dsu1.merge(i, j);
            }
        }
    }
    int cnt = 1;
    ForE(i, 1, n){
        if (!ckdag[dsu1.root(i)]){
            ckdag[dsu1.root(i)] = cnt;
            cnt++;
        }
        ckdag[i] = ckdag[dsu1.root(i)];
    }
    cnt--;
    ForE(i, 1, n){
        if (!ck[i]){
            dfs(i);
        }
    }
    ForE(i, 1, cnt){
        reverse(bend(toposort[i]));
        Fora(u, toposort[i]){
            dist[u] = max(dist[u], 1);
            Fora(v, adj[u]){
                dist[v] = max(dist[v], dist[u] + 1);
            }
            ans = max(ans, dist[u]);
        }
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