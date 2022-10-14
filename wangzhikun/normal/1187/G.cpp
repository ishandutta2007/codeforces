#include <set>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int, int> pii;

template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

const int MAX_V = 10050;
const int INF = 2e9;
struct edge { int to, cap, cost, rev; };

struct MinCost {
    int V;
    vector<edge> G[MAX_V];
    int h[MAX_V];
    int dist[MAX_V];
    int prevv[MAX_V], preve[MAX_V];
    void add_edge(int from, int to, int cap, int cost) {
        G[from].push_back((edge){ to, cap, cost, G[to].size() });
        G[to].push_back((edge){ from, 0, -cost, G[from].size() - 1 });
    }
    int min_cost_flow(int s, int t, int f) {
        int res = 0;
        fill(h, h + V, 0);
        while (f > 0) {
            priority_queue<pii, vector<pii>, greater<pii> > que;
            fill(dist, dist + V, INF);
            dist[s] = 0;
            que.push(pii(0, s));
            while (!que.empty()) {
                pii p = que.top();
                que.pop();
                int v = p.second;
                if (dist[v] < p.first)
                    continue;
                for (int i = 0; i < G[v].size(); i++) {
                    edge &e = G[v][i];
                    if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
                        dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        que.push(pii(dist[e.to], e.to));
                    }
                }
            }
            if (dist[t] == INF) {
                return -1;
            }
            for (int v = 0; v < V; v++) h[v] += dist[v];
            int d = f;
            for (int v = t; v != s; v = prevv[v]) {
                d = min(d, G[prevv[v]][preve[v]].cap);
            }
            f -= d;
            res += d * h[t];
            for (int v = t; v != s; v = prevv[v]) {
                edge &e = G[prevv[v]][preve[v]];
                e.cap -= d;
                G[v][e.rev].cap += d;
            }
        }
        return res;
    }
} M;

int n,m,k,c,d;
int main() {
	read(n);read(m);read(k);read(c);read(d);
	M.V = n*110+10;
	int s = n*110+5,t = n*110+6;
	for(int i=0;i<k;i++){
		int cc =0 ;
		read(cc);cc--;
		M.add_edge(s,cc,1,0);
	}
	M.add_edge(n*100,t,INF,0);
	for(int i=0;i<m;i++){
		int u,v;
		read(u);read(v);
		u--;v--;
		for(int j=0;j<100;j++){
			for(int e = 1;e<=k;e++){
				M.add_edge(u+j*n,v+j*n+n,1,d*(e*2-1)+c);
				M.add_edge(v+j*n,u+j*n+n,1,d*(e*2-1)+c);
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<100;j++){
			if(i!=0)M.add_edge(i+j*n,i+j*n+n,INF,c);
			else M.add_edge(i+j*n,i+j*n+n,INF,0);
		}
	}
	cout<<M.min_cost_flow(s,t,k)<<endl;
	return 0;
}