#include<bits/stdc++.h>
using namespace std;

// Shortcut

#define int long long
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

#define PrintV(a) for (int i = 0; i < a.size(); i++) cout << a[i] << ' ';
#define PrintVl(a) for (int i = 0; i < a.size(); i++) cout << a[i] << endl;
#define PrintA(a, n) for (int i = 0; i < n; i++) cout << a[i] << ' ';
#define PrintAl(a, n) for (int i = 0; i < n; i++) cout << a[i] << endl;
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

#define bend(a) a.begin(),a.end()
#define mset(a) memset(a, 0, sizeof(a));
#define sortV(a) sort(bend(a));
#define sortA(a, n) sort(a, a + n);
#define rev(s) reverse(bend(s));
//mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());

// Data Structure

#define pque priority_queue
#define mts multiset
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

const int N = 1e5 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

int n;
vi adj[N];
int a[N], cur;

bool ok;
 
void dfs(int v, int par){
    ok = (ok && (a[v] == cur));
    For(i, 0, adj[v].size()){
        if (adj[v][i] != par){
            dfs(adj[v][i], v);
        }
    }
}
 
bool solve(int v){
    bool ans = 1;
    For(i, 0, adj[v].size()){
        cur = a[adj[v][i]];
        ok = true;
        dfs(adj[v][i], v);
        ans = (ans && ok);
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    For(i, 1, n){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ForE(i, 1, n) cin >> a[i];
    For(i, 1, n){
        Fora(v, adj[i]){
            if (a[i] != a[v]){
                bool x = solve(i), y = solve(v);
                if (x){
                    cout << "YES" << endl << i;
                }
                else if (y){
                    cout << "YES" << endl << v;
                }
                else{
                    cout << "NO";
                }
                return 0;
            }
        }
    }
    cout << "YES" << endl << 1;
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