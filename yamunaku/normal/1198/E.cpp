//
// Created by yamunaku on 2019/07/30.
//

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repl(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perl(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD9 998244353
#define MOD1 1000000007
#define IINF 1000000010
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)
#define CST(x) cout<<fixed<<setprecision(x)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> mti;
typedef vector<ll> vl;
typedef vector<vector<ll>> mtl;

template< typename flow_t >
struct Dinic {
    const flow_t INF;

    struct edge {
        int to;
        flow_t cap;
        int rev;
        bool isrev;
    };

    vector< vector< edge > > graph;
    vector< int > min_cost, iter;

    Dinic(int V) : INF(numeric_limits< flow_t >::max()), graph(V) {}

    void add_edge(int from, int to, flow_t cap) {
        graph[from].emplace_back((edge) {to, cap, (int) graph[to].size(), false});
        graph[to].emplace_back((edge) {from, 0, (int) graph[from].size() - 1, true});
    }

    bool bfs(int s, int t) {
        min_cost.assign(graph.size(), -1);
        queue< int > que;
        min_cost[s] = 0;
        que.push(s);
        while(!que.empty() && min_cost[t] == -1) {
            int p = que.front();
            que.pop();
            for(auto &e : graph[p]) {
                if(e.cap > 0 && min_cost[e.to] == -1) {
                    min_cost[e.to] = min_cost[p] + 1;
                    que.push(e.to);
                }
            }
        }
        return min_cost[t] != -1;
    }

    flow_t dfs(int idx, const int t, flow_t flow) {
        if(idx == t) return flow;
        for(int &i = iter[idx]; i < graph[idx].size(); i++) {
            edge &e = graph[idx][i];
            if(e.cap > 0 && min_cost[idx] < min_cost[e.to]) {
                flow_t d = dfs(e.to, t, min(flow, e.cap));
                if(d > 0) {
                    e.cap -= d;
                    graph[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    flow_t max_flow(int s, int t) {
        flow_t flow = 0;
        while(bfs(s, t)) {
            iter.assign(graph.size(), 0);
            flow_t f = 0;
            while((f = dfs(s, t, INF)) > 0) flow += f;
        }
        return flow;
    }

    void output() {
        for(int i = 0; i < graph.size(); i++) {
            for(auto &e : graph[i]) {
                if(e.isrev) continue;
                auto &rev_e = graph[e.to][e.rev];
                cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << e.cap + rev_e.cap << ")" << endl;
            }
        }
    }
};

struct rect{
    int l;
    int r;
    int d;
    int u;
};

int main(){
    int n,m;
    cin >> n >> m;
    vector<rect> rec(m);
    map<int,int> x,y;
    rep(i,m){
        cin >> rec[i].l >> rec[i].d >> rec[i].r >> rec[i].u;
        x[rec[i].l]=x[rec[i].r+1]=0;
        y[rec[i].d]=y[rec[i].u+1]=0;
    }
    int h=0,w=0;
    vi revx(x.size()+1),revy(y.size()+1);
    for(auto &p:x){
        revx[h]=p.first;
        p.second=(h++);
    }
    revx[h]=n;
    for(auto &p:y){
        revy[w]=p.first;
        p.second=(w++);
    }
    revy[w]=n;
    mti f(h, vi(w,0));
    rep(i,m){
        int l=x[rec[i].l];
        int r=x[rec[i].r+1];
        int d=y[rec[i].d];
        int u=y[rec[i].u+1];
        repl(j,l,r){
            repl(k,d,u){
                f[j][k]=1;
            }
        }
    }
    Dinic<ll> dnc(h+w+2);
    rep(i,h){
        dnc.add_edge(0,i+2,revx[i+1]-revx[i]);
    }
    rep(j,w){
        dnc.add_edge(j+h+2,1,revy[j+1]-revy[j]);
    }
    rep(i,h){
        rep(j,w){
            if(f[i][j]){
                dnc.add_edge(i+2,j+h+2,IINF);
            }
        }
    }
    cout << dnc.max_flow(0,1) << endl;
    return 0;
}