#define _USE_MATH_DEFINES
#include<bits/stdc++.h>//////////////////////////////////////////
#define deb(...)/////////////////////////////////////////////////
#define DBP(...)/////////////////////////////////////////////////
#ifdef LOC///////////////////////////////////////////////////////
#include"debuglib.h"/////////////////////////////////////////////
#endif///////////////////////////////////////////////////////////
#define x first//////////////////////////////////////////////////
#define y second/////////////////////////////////////////////////
#define pb push_back/////////////////////////////////////////////
#define sz(x)int((x).size())/////////////////////////////////////
#define each(a,x)for(auto&a:(x))/////////////////////////////////
#define all(x)(x).begin(),(x).end()//////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)///////////////////////
using namespace std;using ll=long long;using Pii=pair<int,int>;//
using Vi=vector<int>;void run();int main(){cin.sync_with_stdio///
(0);cin.tie(0);cout<<fixed<<setprecision(18);run();return 0;}////
//-------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }

constexpr int INF = 1e8;

char mem[400<<20]; // Set memory limit
size_t nMem;

void* operator new(size_t n) { nMem += n; return &mem[nMem-n]; }
void operator delete(void*) {}

struct MaxFlow {
    using T = int;

    struct Edge {
        int dst, inv;
        T flow, cap;
    };

    vector<vector<Edge>> G;
    vector<T> add;
    Vi prev;

    // Initialize for n vertices
    MaxFlow(int n = 0) : G(n) {}

    // Add new vertex
    int addVert() {
        G.emplace_back(); return sz(G)-1;
    }

    // Add edge between u and v with capacity cap
    // and reverse capacity rcap
    void addEdge(int u, int v, T cap, T rcap=0) {
        G[u].pb({ v, sz(G[v]), 0, cap });
        G[v].pb({ u, sz(G[u])-1, 0, rcap });
    }

    // Compute maximum flow from src to dst.
    // Flow values can be found in edges,
    // vertices with `add` >= 0 belong to
    // cut component containing `s`.
    T maxFlow(int src, int dst) {
        T f = 0;

        do {
            queue<int> Q;
            Q.push(src);
            prev.assign(sz(G), -1);
            add.assign(sz(G), -1);
            add[src] = INF;

            while (!Q.empty()) {
                int i = Q.front();
                T m = add[i];
                Q.pop();

                if (i == dst) {
                    while (i != src) {
                        auto& e = G[i][prev[i]];
                        e.flow -= m;
                        G[e.dst][e.inv].flow += m;
                        i = e.dst;
                    }
                    f += m;
                    break;
                }

                each(e, G[i]) if (add[e.dst] < 0) {
                    if (e.flow < e.cap) {
                        Q.push(e.dst);
                        prev[e.dst] = e.inv;
                        add[e.dst] = min(m, e.cap-e.flow);
                    }
                }
            }
        } while (prev[dst] != -1);

        return f;
    }
};

void run() {
    int n, m; cin >> n >> m;
    vector<string> board(n);
    each(row, board) cin >> row;

    MaxFlow flow(n*m*2);

    rep(i, 0, n*m) {
        flow.addEdge(i*2+1, i*2, 1);
    }

    rep(i, 0, n) rep(j, 0, m) {
        if (i+1 < n && board[i][j] == '.' && board[i+1][j] == '.') {
            flow.addEdge((i*m+j)*2, ((i+1)*m+j)*2+1, 1);
        }
        if (j+1 < m && board[i][j] == '.' && board[i][j+1] == '.') {
            flow.addEdge((i*m+j)*2, (i*m+j+1)*2+1, 1);
        }
    }

    cout << flow.maxFlow(0, (n*m-1)*2+1) << endl;
}