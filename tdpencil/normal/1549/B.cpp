#include <bits/stdc++.h>
#include <chrono>
 
#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define vl vector<long long>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define REP(i,a) for (int i = 0; i < (a); i++)
#define add push_back
using namespace std;
 
 
 
int ni() {
    int x; cin >> x;
    return x;
}
 
ll nl() {
    ll x; cin >> x;
    return x;
}
 
double nd() {
    double x; cin >> x;
    return x;
}
 
string next() {
    string x; cin >> x;
    return x;
}
 
struct HopcroftKarp {
    vi match;
    vi dist;
    vector<vi> graph;
    int N;
    int M;
    int T;
    const int INF = 1000000000;
 
    HopcroftKarp(int N, int M) {
        this->N=N;
        this->M=M;
        T = N+M+1;
        match.assign(T,0);
        dist.assign(T,0);
        graph.assign(T,vi{});
    }
 
    //1 indexed
    void addEdge(int u, int v) {
        graph[u].add(v);
        graph[v].add(u);
    }
 
    bool BFS() {
        queue<int> q;
        for (int u = 1; u <= N; u++) {
            if (match[u]==0) {
                dist[u] = 0;
                q.push(u);
            } else {
                dist[u] = INF;
            }
        }
        dist[0] = INF;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (dist[u]<dist[0]) {
                for (int v: graph[u]) {
                    if (dist[match[v]] == INF) {
                        dist[match[v]] = dist[u]+1;
                        q.push(match[v]);
                    }
                }
            }
        }
        return dist[0]<INF;
    }
 
    bool DFS(int u) {
        if (u > 0) {
            for (int v: graph[u]) {
                if (dist[match[v]]==dist[u]+1 && DFS(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
            dist[u] = INF;
            return false;
        }
        return true;
    }
 
    vector<pii> run() {
        int m = 0;
        while (BFS()) {
            for (int u = 1; u <= N; u++) {
                if (match[u]==0 && DFS(u)) {
                    m++;
                }
            }
        }
        vector<pii> ans;
        for (int v = N+1; v <= N+M; v++) {
            if (match[v]>0) {
                ans.add(make_pair(match[v],v));
            }
        }
        return ans;
    }
};
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int Q = ni();
    REP(q,Q) {
        int N = ni();
        string enemy = next();
        string gregor = next();
 
        HopcroftKarp flow(N,N);
        REP(i,N) {
            if (gregor[i]=='1') {
                if (i > 0 && enemy[i-1]=='1')
                    flow.addEdge(i+1,N+i);
                if (i < N-1 && enemy[i+1]=='1')
                    flow.addEdge(i+1,N+i+2);
                if (enemy[i]=='0')
                    flow.addEdge(i+1,N+i+1);
            }
        }
        auto matching = flow.run();
        cout << sz(matching) << '\n';
    }
}