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

#define bend(a) a.begin(), a.end()
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

const int N = 15 + 5, mod = 1e9 + 7, inf = 1e9 + 7;

int n, m, a, b, c, k;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    vpii v[n + 1];
    pque <pair <int, pii > > q;
    int d[n + 1], fix[n + 1], w[n + 1];
    ForE(i, 1, m){
        cin >> a >> b >> c;
        v[a].pb({b,c});
        v[b].pb({a,c});
    }
    ForE(i, 1, n){
        d[i] = -1;
        fix[i] = 0;
    }
    q.push({0, {1, 0}});
    while (q.size()){
        int x = -q.top().fi;
        int u = q.top().se.fi;
        int p = q.top().se.se;
        q.pop();
        if (fix[u]){
            continue;
        }
        fix[u] = 1;
        d[u] = x;
        w[u] = p;
        For(i, 0, v[u].size()){
            q.push({-x - v[u][i].se, {v[u][i].fi, u}});
        }
    }
    if (d[n] == -1) Ptest(-1);
    vi ans;
    while (n){
        ans.pb(n);
        n = w[n];
    }
    reverse(bend(ans));
    For(i, 0, ans.size()){
        cout << ans[i] << " ";
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