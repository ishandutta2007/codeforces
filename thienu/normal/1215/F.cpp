#include <bits/stdc++.h>

using namespace std;

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

int n, p, M, m;

int station(int i){
    return 2*i;
}

int power(int j){
    return 2*(j+p);
}

// a or b
int add_term(int a, int b, vvi &adj, vvi &radj){
    adj[a^1].push_back(b);
    adj[b^1].push_back(a);
    debug(a^1, b);
    debug(b^1, a);
    radj[a].push_back(b^1);
    radj[b].push_back(a^1);
}


void dfs1(int u, vvi &adj, vi &order, vi &vis){
    vis[u] = 1;
    for(int v : adj[u]){
        if(vis[v]) continue;
        dfs1(v, adj, order, vis);
    }
    order.push_back(u);
}

void dfs2(int u, vvi &radj, vi &vis, vi &comp){
    vis[u] = 1;
    comp.push_back(u);
    for(int v : radj[u]){
        if(vis[v]) continue;
        dfs2(v, radj, vis, comp);
    }
}

void solve(){
    cin >> n >> p >> M >> m;
    M += 2;
    int pred = 2*(p+M);
    vvi adj(pred);
    vvi radj(pred);
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        x--;y--;
        add_term(station(x), station(y), adj, radj);
    }
    for(int i = 0; i < p; i++){
        int l, r;
        cin >> l >> r;
        add_term(station(i)^1, power(r+1)^1, adj, radj);
        add_term(station(i)^1, power(l), adj, radj);
    }
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;y--;
        add_term(station(x)^1, station(y)^1, adj, radj);
    }
    for(int i = 0; i < M-1; i++){
        add_term(power(i), power(i+1)^1, adj, radj);
    }

    // find scc
    vi vis(pred);
    vi order;
    for(int i = 0; i < pred; i++){
        if(vis[i]) continue;
        dfs1(i, adj, order, vis);
    }

    reverse(order.begin(), order.end());
    fill(vis.begin(), vis.end(), 0);
    vi comp_num(pred);
    int ccnt = 0;
    for(int i : order){
        if(vis[i]) continue;
        vi comp;
        dfs2(i, radj, vis, comp);
        debug(comp);
        for(int j : comp){
            comp_num[j] = ccnt;
        }
        ccnt++;
    }

    vi topo(pred);
    for(int i = 0; i < pred; i++){
        topo[order[i]] = i;
    }
    debug(comp_num);

    debug(order);

    vi truth(pred);
    for(int i = 0; i < pred; i+=2){
        debug(i, comp_num[i], comp_num[i+1]);
        if(comp_num[i] == comp_num[i+1]){
            cout << -1 << endl;
            return;
        }
        if(topo[i] < topo[i+1]){
            truth[i] = false;
            truth[i+1] = true;
        }else{
            truth[i] = true;
            truth[i+1] = false;
        }
    }
    debug(truth);

    vi stations;
    for(int i = 0; i < p; i++){
        if(truth[station(i)]) stations.push_back(i);
    }
    int signal = 0;
    for(int i = 0; i < M; i++){
        if(truth[power(i)]){
            signal = i;
        }
    }
    cout << stations.size() << ' ' << signal << '\n';
    for(int i : stations){
        cout << i+1 << ' ';
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}