/**
 *    author:  otera    
**/
#include<iostream>
#include<string> 
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm> 
#include<functional>
#include<iomanip>
#include<queue>
#include<deque>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<cassert>
using namespace std;

#define int long long
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60 ;
const ll mod=1e9+7 ;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<int, int> P;
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// edge class (for network-flow)
template<class FLOWTYPE> struct Edge {
    int rev, from, to;
    FLOWTYPE cap, icap;
    Edge(int r, int f, int t, FLOWTYPE c) : rev(r), from(f), to(t), cap(c), icap(c) {}
    friend ostream& operator << (ostream& s, const Edge& E) {
        if (E.cap > 0) return s << E.from << "->" << E.to << '(' << E.cap << ')';
        else return s;
    }
};
 
// graph class (for network-flow)
template<class FLOWTYPE> struct Graph {
    vector<vector<Edge<FLOWTYPE> > > list;
     
    Graph(int n = 0) : list(n) { }
    void init(int n = 0) { list.clear(); list.resize(n); }
    void reset() { for (int i = 0; i < (int)list.size(); ++i) for (int j = 0; j < list[i].size(); ++j) list[i][j].cap = list[i][j].icap; }
    inline vector<Edge<FLOWTYPE> >& operator [] (int i) { return list[i]; }
    inline const size_t size() const { return list.size(); }
     
    inline Edge<FLOWTYPE> &redge(Edge<FLOWTYPE> e) {
        if (e.from != e.to) return list[e.to][e.rev];
        else return list[e.to][e.rev + 1];
    }
     
    void addedge(int from, int to, FLOWTYPE cap) {
        list[from].push_back(Edge<FLOWTYPE>((int)list[to].size(), from, to, cap));
        list[to].push_back(Edge<FLOWTYPE>((int)list[from].size() - 1, to, from, 0));
    }
     
    void add_undirected_edge(int from, int to, FLOWTYPE cap) {
        list[from].push_back(Edge<FLOWTYPE>((int)list[to].size(), from, to, cap));
        list[to].push_back(Edge<FLOWTYPE>((int)list[from].size() - 1, to, from, cap));
    }
 
    /* 
    // debug
    friend ostream& operator << (ostream& s, const Graph& G) {
        s << endl; for (int i = 0; i < G.V; ++i) { s << i << " : " << G.list[i] << endl; }return s;
    }
    */
};
 
template<class FLOWTYPE> struct Dinic {
    const FLOWTYPE INF = 1<<30; // to be set
    vector<int> level, iter;
 
    Dinic() { }
    void dibfs(Graph<FLOWTYPE> &G, int s) {
        level.assign((int)G.size(), -1);
        level[s] = 0;
        queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (int i = 0; i < G[v].size(); ++i) {
                Edge<FLOWTYPE> &e = G[v][i];
                if (level[e.to] < 0 && e.cap > 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }
     
    FLOWTYPE didfs(Graph<FLOWTYPE> &G, int v, int t, FLOWTYPE f) {
        if (v == t) return f;
        for (int &i = iter[v]; i < G[v].size(); ++i) {
            Edge<FLOWTYPE> &e = G[v][i], &re = G.redge(e);
            if (level[v] < level[e.to] && e.cap > 0) {
                FLOWTYPE d = didfs(G, e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    re.cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
     
    FLOWTYPE solve(Graph<FLOWTYPE> &G, int s, int t) {
        level.assign((int)G.size(), -1); iter.assign((int)G.size(), 0);
        FLOWTYPE res = 0;
        while (true) {
            dibfs(G, s);
            if (level[t] < 0) return res;
            for (int i = 0; i < (int)iter.size(); ++i) iter[i] = 0;
            FLOWTYPE flow = 0;
            while ((flow = didfs(G, s, t, INF)) > 0) {
                res += flow;
            }
        }
    }
};

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

void solve() {
	int n, m; cin >> n >> m;
    vector<vector<char>> s(n, vector<char>(m));
    vector<bool> used(2 * n * m, false);
    int cnt = 0;
    rep(i, n) {
        rep(j, m) {
            cin >> s[i][j];
            if(s[i][j] == '#') ++ cnt;
        }
    }
    Graph<int> g(2 * n * m + 2);
    int sr = 2 * n * m, t = 2 * n * m + 1;
    int co = 0;
    rep(i, n) {
        rep(j, m) {
            rep(k, 2) {
                int ni = i + dx[k], nj = j + dy[k];
                if(0 <= ni and ni < n and 0 <= nj and nj < m) {
                    if(s[i][j] == '#' and s[ni][nj] == '#') {
                        if(k == 0) g.addedge(sr, k * n * m + i * m + j, 1);
                        else g.addedge(k * n * m + i * m + j, t, 1);
                        ++ co;
                    }
                }
            }
        }
    }
    // cerr << cnt << endl;
    map<pair<int, pair<int, int>>, int> mp;
    rep(i, n) {
        rep(j, m) {
            rep(k, 2) {
                int ni = i + dx[k], nj = j + dy[k];
                mp[{k, {i, j}}] = k * n * m + i * m + j;
            }
            for(int k = 2; k < 4; ++ k) {
                int ni = i + dx[k], nj = j + dy[k];
                int nk = k - 2;
                mp[{k, {i, j}}] = nk * n * m + ni * m + nj;
            }
        }
    }
    rep(i, n) {
        rep(j, m) {
            rep(k, 4) {
                int ni = i + dx[k], nj = j + dy[k];
                int nii = i + dx[(k + 1) % 4], njj = j + dy[(k + 1) % 4];
                if(0 <= ni and ni < n and 0 <= nj and nj < m and 0 <= nii and nii < n and 0 <= njj and njj < m) {
                    if(s[i][j] == '#' and s[ni][nj] == '#' and s[nii][njj] == '#') {
                        int a = mp[{k, {i, j}}], b = mp[{(k + 1) % 4, {i, j}}];
                        if(k % 2 == 1) swap(a, b);
                        g.addedge(a, b, 1);
                    }
                }
            }
        }
    }
    Dinic<int> dic;
    int flow = dic.solve(g, sr, t);
    // cerr << co << " " << flow << endl;
    cout << cnt - (co - flow) << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}