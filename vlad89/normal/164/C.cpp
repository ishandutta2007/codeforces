#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define UN(a) sort(all(a)),(a).resize(unique(all(a))-(a).begin())
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset ((a), (b), sizeof (a))
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

template <int N, int M, ll inf, class T>
struct MinCostMaxFlow {
     struct Edge {
        int w, next;
        T cap, cost;
        Edge(int iw, T icap, T icost, int inext) : w(iw),cap(icap),cost(icost),next(inext) {}
        Edge(){}
    };
    int first[N], prev[N], n, m, s, t;     
    T dist[N], phi[N];
    Edge E[2*M];
    
    void init (int in, int is, int it)  
    {
        n = in; s = is; t = it;  m = 0;
        REP (i, n) first[i] = -1;
    }    
    void add(int q, int w, T cap, T cost) {
        E[m] = Edge (w, cap, cost, first[q]); first[q] = m++;
        E[m] = Edge (q, 0, -cost, first[w]);  first[w] = m++;
    }        
    bool augment() {
        REP (i, n) dist[i] = inf;
        dist[s] = 0;        
        set<pair <T, int> > pq; 
        pq.insert (make_pair (dist[s], s));
        while (sz (pq)) {
            int i = pq.begin()->Y;
            T d = pq.begin()->X; 
            pq.erase (pq.begin());
            if (dist[i] != d) continue;
            for(int x = first[i]; x > -1; x = E[x].next)
                if (E[x].cap && dist[E[x].w] > d+E[x].cost - (phi[E[x].w]-phi[i])) {
                    dist[E[x].w] = d+E[x].cost - (phi[E[x].w]-phi[i]);
                    prev[E[x].w] = x;                    
                    pq.insert (make_pair (dist[E[x].w], E[x].w)); 
                }
        }          
        return dist[t]!=inf;
    }
    pair <T, T> mincost(int k) {           // {flow_size,flow_cost}
        pair <T, T> res;
        REP (i, n) phi[i] = 0;
        while (augment() && k) {
	    --k;
            T add = inf;
            for(int x=t; x!=s; x = E[prev[x]^1].w) add = min (add, E[prev[x]].cap);
            res.X += add;
            res.Y += add * (dist[t]+phi[t]-phi[s]);
            for(int x=t; x!=s; x = E[prev[x]^1].w) {
                E[prev[x]].cap -= add;
                E[prev[x]^1].cap += add;
            }
            REP(i, n) if (phi[i] < inf) phi[i] += dist[i];           
        }
        return res;
    }
};

MinCostMaxFlow<2000, 4005, 1000000001, int> mcmf;
pair<pii, int> a[1024];

int main () {
#ifdef LocalHost
    freopen("input.txt", "r", stdin);
#endif
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> b;
    REP (i, n) {
	scanf("%d%d%d", &a[i].X.X, &a[i].X.Y, &a[i].Y);
	a[i].X.Y += a[i].X.X;
	b.pb(a[i].X.X);
	b.pb(a[i].X.Y);
    }
    UN(b);
    mcmf.init(sz(b), 0, sz(b)-1);
    REP (i, n) {
	int q = lower_bound(all(b), a[i].X.X) - b.begin();
	int w = lower_bound(all(b), a[i].X.Y) - b.begin();
	mcmf.add(q, w, 1, -a[i].Y);
    }
    REP (i, sz (b)-1)
	mcmf.add(i, i+1, k, 0);
    mcmf.mincost(k);
    REP (i, n) {
	if (i)
	    printf(" ");
	if (!mcmf.E[2*i].cap)
	    printf("1");
	else
	    printf("0");
    }
    printf("\n");
    return 0;
}