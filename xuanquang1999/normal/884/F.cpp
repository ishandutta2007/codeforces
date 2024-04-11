//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> point;
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define maxN 200005
#define oo 2000000007
#define sz(a) (int)a.size()

const double PI = acos(-1.0);

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

struct Edge {
    int v, f, cap, cost, rev;
    Edge(int v, int cap, int cost, int rev): v(v), cap(cap), cost(cost), rev(rev) {f = 0;}
};

struct MinCostMaxFlow {
    vector<vector<Edge> > g;
    int n;

    MinCostMaxFlow(int n): n(n) {
        g.assign(n+1, vector<Edge>());
    }

    void addEdge(int u, int v, int cap, int cost) {
        g[u].pb(Edge(v, cap, cost, sz(g[v])));
        g[v].pb(Edge(u, 0, -cost, sz(g[u])-1));
    }

    void SPFA(int s, vector<int> &dist, vector<int> &pNode, vector<int> &pEdge, vector<int> &delta) {
        dist.assign(n+1, oo);
        vector<bool> inQueue(n+1, false);
        queue<int> q;
        q.push(s);
        dist[s] = 0;
        delta[s] = oo;
        inQueue[s] = true;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            inQueue[u] = false;
            fto(i, 0, sz(g[u])-1) {
                int v = g[u][i].v, nflow = g[u][i].cap - g[u][i].f;
                if (nflow == 0) continue;

                int ndist = dist[u]+g[u][i].cost;
                if (dist[v] > ndist) {
                    dist[v] = ndist;
                    delta[v] = min(delta[u], nflow);
                    pNode[v] = u;
                    pEdge[v] = i;
                    if (!inQueue[v]) {
                        inQueue[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }

    ii getFlow(int s, int t) {
        vector<int> dist(n+1);
        vector<int> pNode(n+1);
        vector<int> pEdge(n+1);
        vector<int> delta(n+1);

        int maxFlow = 0, cost = 0;
        while (true) {
            SPFA(s, dist, pNode, pEdge, delta);
            if (dist[t] == oo) break;

            int df = delta[t];
            maxFlow += df;
            cost += df*dist[t];
            for(int v = t; v != s; v = pNode[v]) {
                int u = pNode[v], i = pEdge[v];
                g[u][i].f += df;
                g[v][g[u][i].rev].f -= df;
            }
        }

        return mp(maxFlow, cost);
    }
};

int n, a[maxN], cnt[maxN];
string s;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    cin >> s;
    fto(i, 1, n) scanf("%d", &a[i]);

    fto(i, 0, n-1) ++cnt[s[i]];

    MinCostMaxFlow f(n/2+28);
    fto(c, 'a', 'z') f.addEdge(0, c-'a'+1, cnt[c], 0);
    for(int i = 1, j = n; i < j; ++i, --j) {
        vector<int> cost(256, 0);
        if (s[i-1] == s[j-1]) cost[s[i-1]] = max(a[i], a[j]);
        else {
            cost[s[i-1]] = a[i];
            cost[s[j-1]] = a[j];
        }

        fto(c, 'a', 'z') f.addEdge(c-'a'+1, 26+i, 1, -cost[c]);
        f.addEdge(26+i, 27+n/2, 2, 0);
    }

    ii p = f.getFlow(0, 27+n/2);
    printf("%d", -p.ss);


    return 0;
}