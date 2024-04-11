//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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
#define maxN 10005
#define oo 1000000007
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

int nodes, src, dest;
int dist[maxN], q[maxN], work[maxN];

struct Edge {
  int to, rev;
  int f, cap;
};

vector<Edge> g[maxN];

void init() {
    fto(i, 0, nodes-1) g[i].clear();
}

void addEdge(int s, int t, int cap){
  Edge a = {t, g[t].size(), 0, cap};
  Edge b = {s, g[s].size(), 0, 0};
  g[s].push_back(a);
  g[t].push_back(b);
}

bool dinic_bfs() {
  fill(dist, dist + nodes, -1);
  dist[src] = 0;
  int qt = 0;
  q[qt++] = src;
  for (int qh = 0; qh < qt; qh++) {
    int u = q[qh];
    for (int j = 0; j < (int) g[u].size(); j++) {
      Edge &e = g[u][j];
      int v = e.to;
      if (dist[v] < 0 && e.f < e.cap) {
        dist[v] = dist[u] + 1;
        q[qt++] = v;
      }
    }
  }
  return dist[dest] >= 0;
}

int dinic_dfs(int u, int f) {
  if (u == dest)
    return f;
  for (int &i = work[u]; i < (int) g[u].size(); i++) {
    Edge &e = g[u][i];
    if (e.cap <= e.f) continue;
    int v = e.to;
    if (dist[v] == dist[u] + 1) {
      int df = dinic_dfs(v, min(f, e.cap - e.f));
      if (df > 0) {
        e.f += df;
        g[v][e.rev].f -= df;
        return df;
      }
    }
  }
  return 0;
}

int maxFlow(int _src, int _dest) {
  src = _src;
  dest = _dest;
  int result = 0;
  while (dinic_bfs()) {
    fill(work, work + nodes, 0);
    while (int delta = dinic_dfs(src, INT_MAX))
      result += delta;
  }
  return result;
}

int n, m, eu[maxN], ev[maxN];
vector<ii> ans;

bool Check(int x) {
    nodes = m+n+2;
    init();
    fto(i, 1, m) {
        addEdge(0, i, 1);
        addEdge(i, m+eu[i], 1);
        addEdge(i, m+ev[i], 1);
    }
    fto(u, 1, n) addEdge(m+u, m+n+1, x);
    int f = maxFlow(0, m+n+1);
    if (f < m) return false;

    ans.clear();
    fto(i, 1, m) {
        for(Edge e: g[i]) {
            if (e.f == 1) {
                int u = e.to-m;
                ans.pb(mp(u, eu[i]+ev[i]-u));
                break;
            }
        }
    }

    return true;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, m) scanf("%d%d", &eu[i], &ev[i]);

    int lo = 0, hi = m, res = 0;
    while (lo <= hi) {
        int mid = (lo+hi)/2;
        if (Check(mid)) {
            res = mid;
            hi = mid-1;
        } else lo = mid+1;
    }

    printf("%d\n", res);
    for(ii p: ans) printf("%d %d\n", p.ff, p.ss);

    return 0;
}