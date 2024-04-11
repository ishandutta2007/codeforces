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

const int N = 2e2 + 5, mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
const ll infll = 1e18 + 7;

int q;
string s, ans;
int n;
set <int> stt[26];
int par[26];
bool vis[26];
int cnt, tmp;
vi lol;

void init(){
    msetn1(par);
    mset(vis);
    ans = "";
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

void dfs(int u, bool t){
    if (t) ans += (char)(u + 'a');
    else lol.pb(u);
    vis[u] = 1;
    if (stt[u].size() == 1){
        cnt++;
        tmp = u;
    }
    Fora(v, stt[u]){
        if (!vis[v]){
            dfs(v, t);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
cin >> q;
while (q--){
    bool ck = 0;
    cin >> s;
    n = s.length();
    init();
    For(i, 0, 26){
        stt[i].clear();
    }
    For(i, 1, n){
        stt[s[i] - 'a'].insert(s[i - 1] - 'a');
        stt[s[i - 1] - 'a'].insert(s[i] - 'a');
        merge(s[i] - 'a', s[i - 1] - 'a');
    }
    For(i, 0, 26){
        if (stt[i].size() > 2){
            ck = 1;
            break;
        }
    }
    if (ck){
        cout << "NO" << endl;
        continue;
    }
    For(i, 0, 26){
        if (!vis[i]){
            cnt = 0;
            lol.clear();
            dfs(i, 0);
            if (cnt == 0){
                if (par[i] == -1){
                    ans += (char)(i + 'a');
                    continue;
                }
                ck = 1;
                break;
            }
            Fora(v, lol) vis[v] = 0;
            dfs(tmp, 1);
        }
    }
    if (ck){
        cout << "NO" << endl;
        continue;
    }
    cout << "YES" << endl;
    cout << ans << endl;
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