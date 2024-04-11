#include<bits/stdc++.h>
using namespace std;

// Shortcut

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

const int N = 1e6 + 5, mod = 1e9 + 7, inf = 1e9 + 7;

int n, k, l2;
vi adj[N];
vi rem;
bool ck[N];
int memo[N][21], lev[N];

void init(){
    ForE(i, 0, n + 1){
        ForE(j, 0, l2){
            memo[i][j] = -1;
        }
    }
}

void dfs(int u, int p){
    memo[u][0] = p;
    ForE(i, 1, l2){
        memo[u][i] = memo[memo[u][i - 1]][i - 1];
    }
    Fora(v, adj[u]){
        if (v != p){
            lev[v] = lev[u] + 1;
            dfs(v, u);
        }
    }
}

int cal(int u){
    int ans = 0;
    FordE(i, l2, 0){
        if (!ck[memo[u][i]]){
            ans += (1 << i);
            //cout << "D " << i << ' ' << u << ' ' << memo[u][i] << endl;
            u = memo[u][i];
        }
    }
    return ans + 1;
}

void add(int idx){
    while (!ck[idx]){
        //cout << idx << endl;
        ck[idx] = 1;
        rem.pb(idx);
        idx = memo[idx][0];
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    l2 = ceil(log2(n));
    For(i, 1, n){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    init();
    dfs(n, n);
    rem.pb(n);
    ck[n] = 1;
    int idx = n - 1;
    while (rem.size() < n - k && idx >= 1){
        int t = cal(idx);
        //cout << idx << ' ' << t << ' ' << rem.size() << endl;
        if (t + rem.size() <= n - k){
            add(idx);
        }
        idx--;
    }
    ForE(i, 1, n){
        if (!ck[i]) cout << i << ' ';
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