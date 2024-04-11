//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef pair<int, int> pii;

const int inf = (int)1e9;
const int N = (int)5e5 + 55;

int n, m;
vector<pii> grt[N];
vector<pii> gr[N];
int col[N];
bool inq[N];
int d[N];
queue<int> q;

void solve(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int v, u, c;
        cin >> v >> u >> c;
        --v; --u;
        gr[v].emplace_back(u, c);
        grt[u].emplace_back(v, c);
    }
    fill(col, col + n, -1);
    col[n - 1] = 0;
    q.push(n - 1);
    inq[n - 1] = 1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto [u, c]: grt[v]){
            if(col[u] == -1){
                col[u] = c^1;
            }
            if(col[u] == c && !inq[u]){
                inq[u] = 1;
                q.push(u);
            }
        }
    }
    for(int i = 0; i < n; i++)
        if(col[i] == -1)
            col[i] = 0;
    fill(d, d + n, inf);
    d[0] = 0;
    q.push(0);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto [u, c]: gr[v]){
            if(c == col[v] && d[u] == inf){
                d[u] = d[v] + 1;
                q.push(u);
            }
        }
    }
    cout << (d[n - 1] == inf ? -1 : d[n - 1]) << '\n';
    for(int i = 0; i < n; i++)
        cout << col[i];
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(9);
    int T=1;
    //cin >> T;
    while(T--)
        solve();
    return 0;
}