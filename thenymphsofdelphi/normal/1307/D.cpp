#include<bits/stdc++.h>
using namespace std;

// Optimization

//#pragma GCC optimize("O3")
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

const int N = 2e5 + 5, mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e18 + 7;
const ll infll = 1e18 + 7;

int n, m, k, ans;
int dist[N][2];
vpii adj[N];
vi spe;
vector <pair <int, pii>> val; // {ai - bi, i}

void dijkstra(int u, int tmp){
    pque <pii, vpii, greater <pii > > pq;
    ForE(i, 1, n){
        dist[i][tmp] = inf;
    }
    pq.push({0, u});
    dist[u][tmp] = 0;
    while (!pq.empty()){
        int t = pq.top().se, dt = pq.top().fi;
        pq.pop();
        if (dt != dist[t][tmp]) continue;
        Fora(v, adj[t]){
            if (dist[v.fi][tmp] > dist[t][tmp] + v.se){
                dist[v.fi][tmp] = dist[t][tmp] + v.se;
                pq.push({dist[v.fi][tmp], v.fi});
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    ForE(i, 1, k){
        int x; cin >> x;
        spe.pb(x);
    }
    ForE(i, 1, m){
        int u, v; cin >> u >> v;
        adj[u].pb({v, 1});
        adj[v].pb({u, 1});
    }
    dijkstra(1, 0);
    dijkstra(n, 1);
    // ForE(i, 1, n){
    //     cout << dist[i][0] << ' ' << dist[i][1] << endl;
    // }
    ans = dist[n][0];
    Fora(v, spe){
        val.pb({dist[v][0] - dist[v][1], {v, dist[v][1]}});
    }
    sort(bend(val));
    FordE(i, val.size() - 2, 0){
        val[i].se.se = max(val[i].se.se, val[i + 1].se.se);
    }
    // For(i, 0, val.size()){
    //     cout << val[i].fi << ' ' << val[i].se.fi << ' ' << val[i].se.se << endl;
    // }
    int tmp = 0;
    For(i, 0, val.size() - 1){
        // cout << val[i].fi + dist[val[i].se.fi][1] + 1 + val[i + 1].se.se << endl;
        tmp = max(tmp, val[i].fi + dist[val[i].se.fi][1] + 1 + val[i + 1].se.se);
    }
    cout << min(ans, tmp);
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