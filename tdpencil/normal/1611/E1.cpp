#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

typedef long long ll;
typedef long double ld;
#define pb push_back
#define all(x) x.begin(),x.end()
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define f first
#define s second
#define ar array
#define vt vector
#define ub upper_bound
#define lb lower_bound
#define V vector
#define nl '\n'
#define vi vector<int>
#define pii pair<int, int>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vt vector
#define vl vector<ll>
#define vpi vector<pi>
#define vpl vt<pl>
#define trav(x,y) for(auto &x:y)
#define vb vector<bool>
#define ull unsigned long long
#define sz(x) int(x.size())
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define F0R(i,N) rep(i,0,N)
#define P pair
ll n, m, k;
const int mxN=1e5,M=998244353,mod=1e9+7;
const ll MOD = 1e9+7;
const ll inf = 8e18;
template<typename K> using pq = priority_queue<K>;
template<typename K> using pqg = priority_queue<K, vt<K>, greater<K>>;
template<typename K> using dq = deque<K>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
void solve(int test_case = 0) {
    int n, k;
    cin >> n >> k;
    vector<int> leaves;
    leaves.reserve(n);
    vector<int> deg(n);
    vector<bool> isGuard(n);
    for(int j = 0; j < k; j++)
        cin >> m, isGuard[--m] = true;
    vector<vector<int>> gr(n);
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        gr[x].pb(y);
        gr[y].pb(x);
        ++deg[x];
        ++deg[y];
    }
    queue<int> bfs;
    vector<int> guardDistance(n,99999999);
    vector<int> rootDistance(n,99999999);
    rootDistance[0]=0;

    vector<bool> vis(n);
    for(int i = 0; i < n; i++)
        if(isGuard[i])
            bfs.push(i), guardDistance[i]=0;
    while(!bfs.empty()) {
        int t = bfs.front();
        bfs.pop();
        if(vis[t])
            continue;
        vis[t]=true;
        for(int e : gr[t])
            bfs.push(e), guardDistance[e] = min(guardDistance[e], guardDistance[t] + 1);
    }
    assert(bfs.empty());
    vis.assign(n, false);
    bfs.push(0);
    while(!bfs.empty()) {
        int t = bfs.front();
        bfs.pop();
        if(vis[t])
            continue;
        vis[t]=true;
        for(int e : gr[t])
            bfs.push(e), rootDistance[e] = min(rootDistance[t] + 1, rootDistance[e]);
    }
    
    for(int i = 1; i < n; i++) {
        if(deg[i] == 1) // leaf
            if(guardDistance[i] > rootDistance[i]) { 
                //cout << guardDistance[i] << " " << rootDistance[i] << nl;
                //cout << "YES: " << i << nl;
                cout << "YES\n";
                return;
            }
    }
    cout << "NO\n";
}



int main()
{
    //setup();
    cin.tie(0)->sync_with_stdio(0);
    //precalc();
    int T = 1;
    cin >> T;
    for(int nt = 0, i; nt < T; nt++) {
        solve(nt);
        ++i;
    }
}