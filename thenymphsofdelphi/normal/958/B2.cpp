#include<bits/stdc++.h>
using namespace std;

// Shortcut

//#pragma optimize ("O3")
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
#define m1set(a) memset(a, -1, sizeof(a));
#define mmset(a) memset(a, 0x3f, sizeof(a));
//mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());

// Data Structure

#define pque priority_queue
#define mts multiset
#define y0 _y0_
#define y1 _y1_
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

const int N = 1e5 + 5, mod = 1e9 + 7, inf = 1e9 + 7;

int n, rt, mx = -1;
vi adj[N];
int h[N], child[N];

struct cmp{
    bool operator() (const pii& x, const pii& y) const{
        if (x.se != y.se) return x.se > y.se;
        return x.fi > y.fi;
    }
};

multimap <pii, int, cmp> mtm;

void dfs1(int u, int p, int t){
    h[u] = t;
    Fora(v, adj[u]){
        if (v != p){
            dfs1(v, u, t + 1);
        }
    }
}

void dfs2(int u, int p){
    bool ck = 0;
    Fora(v, adj[u]){
        if (v != p){
            dfs2(v, u);
            ck = 1;
            if (h[u] <= h[v]){
                h[u] = h[v];
                child[u] = v;
            }
        }
    }
    if (!ck){
        h[u] = 0;
        child[u] = -1;
    }
    else{
        h[u]++;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    if (n == 1) Ptest("1");
    if (n == 2) Ptest("1 2");
    cout << "1 ";
    For(i, 1, n){
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs1(1, 1, 0);
    ForE(i, 1, n){
        if (mx < h[i]){
            mx = h[i];
            rt = i;
        }
    }
    //cout << rt << endl;
    mset(h);
    dfs2(rt, rt);
    //cout << "DEBUG " << child[16] << endl;
    ForE(i, 1, n){
        if (i != rt){
            mtm.insert({{i, h[i]}, i});
            //cout << i << ' ' << h[i] << endl;
        }
    }
    int cnt = 1;
    ForE(i, 2, n){
        //cout << endl << mtm.size() << endl;
        if (mtm.empty()){
            //cout << "CNT ";
            cout << n << ' ';
            continue;
        }
        pii idx = mtm.begin()->fi;
        do{
            //cout << idx.fi << ' ' << h[idx.fi] << endl;
            cnt++;
            mtm.erase({idx.fi, h[idx.fi]});
            idx.fi = child[idx.fi];
            if (idx.fi != -1) idx.se = h[idx.fi];
        } while (idx.fi != -1);
        //cout << "CNT ";
        cout << cnt << ' ';
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