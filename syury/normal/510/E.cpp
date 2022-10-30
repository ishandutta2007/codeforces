    #include<bits/stdc++.h>
     
    using namespace std;
    typedef long long lint;
    typedef long double ldb;
    typedef unsigned long long uli;
     
    #define X first
    #define Y second
    #define F(i, l, r) for(auto i = l; i != r; i++)
    #define Df(i, l, r) for(auto i = l; i != r; i--)
    #define I(i, a) for(auto i : a)
    #define pb push_back
    #define rs resize
    #define mk make_pair
    #define asg assign
    #define all(x) x.begin(),x.end()
    #define ret return
    #define cont continue
    #define brk break
    #define ins insert
    #define era erase
    #define fi0(x) memset(x, 0, sizeof(x))
    #define finf(x) memset(x, 127, sizeof(x))
    #define acpy(y, x) memcpy(y, x, sizeof(y))
    #define y1 adjf
    #define tm dhgdg
     
    const int MAXN = 2e2 + 4;
    const int MAXP = 5e4;
    const int MAXV = MAXN + 4;
    const int inf = 1e9;
     
    bool isp[MAXP];
    int a[MAXN];
    int n;
    int c[MAXV][MAXV];
    int f[MAXV][MAXV];
    int d[MAXV];
    int q[MAXV];
    int ptr[MAXV];
    int qh, qt;
     
    const long long flow_inf = 1e18;
     
    struct Dinic{
    	struct FlowEdge{
    		int v, u;
    		long long cap, flow = 0;
    		FlowEdge(int _v, int _u, long long _cap):v(_v), u(_u), cap(_cap){}
    	};
    	vector<FlowEdge> edges;
    	vector<vector<int> > adj;
    	int n, m = 0;
    	int s, t;
    	vector<int> level, ptr;
    	vector<int> q;
    	int qh, qt;
    	void resize(int _n){n = _n; q.resize(n); adj.resize(n); level.resize(n); ptr.resize(n);}
    	Dinic(){}
    	Dinic(int _n, int _s, int _t){resize(_n); s = _s; t = _t;}
    	void add_edge(int v, int u, long long cap){
    		edges.push_back(FlowEdge(v, u, cap));
    		edges.push_back(FlowEdge(u, v, 0));
    		adj[v].push_back(m);
    		adj[u].push_back(m + 1);
    		m += 2;
    	}
    	bool bfs(){
    		while(qh < qt){
    			int v = q[qh++];
    			for(int id : adj[v]){
    				if(edges[id].cap - edges[id].flow < 1)continue;
    				if(level[edges[id].u] != -1)continue;
    				level[edges[id].u] = level[v] + 1;
    				q[qt++] = edges[id].u;
    			}
    		}
    		return level[t] != -1;
    	}
    	long long dfs(int v, long long pushed = flow_inf){
    		if(pushed == 0)return 0;
    		if(v == t)return pushed;
    		for(int & cid = ptr[v]; cid < (int)adj[v].size(); cid++){
    			int id = adj[v][cid];
    			int u = edges[id].u;
    			if(level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)continue;
    			long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
    			if(tr == 0)continue;
    			edges[id].flow += tr;
    			edges[id^1].flow -= tr;
    			return tr;
    		}
    		return 0;
    	}
    	long long flow(){
    		long long f = 0;
    		while(true){
    			ptr.assign(n, 0);
    			level.assign(n, -1);
    			level[s] = 0;
    			qh = 0, qt = 1;
    			q[0] = s;
    			if(!bfs())break;
    			while(long long pushed = dfs(s)){f += pushed;}
    		}
    		return f;
    	}
    };
     
     
     
    bool used[MAXN];
    int lst[MAXN];
    int sz = 0;
    int ancnt = 0;
     
    void mark(int v){
    	used[v] = true;
    	lst[sz++] = v + 1;
    	F(i, 0, n){
    		int w = (a[i]&1) ? f[i][v] : f[v][i];
    		if(w > 0 && !used[i])mark(i);
    	}
    }
     
    int main(){
    	ios_base::sync_with_stdio(0);
    	cin.tie(0);
    	Dinic solver(MAXV, 0, 1);
    	fi0(c); fi0(f);
    	fi0(isp);
    	isp[2] = false;
    	F(i, 2, MAXP){
    		if(isp[i])cont;
    		for(lint j = i * 1ll * i; j < MAXP; j += i)isp[j] = true;
    	}
    	scanf("%d", &n);
    	F(i, 0, n)scanf("%d", &a[i]);
    	F(i, 0, n)
    		F(j, i + 1, n){
    			if(isp[a[i] + a[j]])cont;
    			if(a[i]&1)solver.add_edge(i + 2, j + 2, 1); else solver.add_edge(j + 2, i + 2, 1);
    		}
    	F(i, 0, n){
    		if(a[i]&1)solver.add_edge(0, i + 2, 2); else solver.add_edge(i + 2, 1, 2);
    	}
    	int flow = solver.flow();
    	if(flow != n){printf("Impossible"); ret 0;}
    	for(auto e : solver.edges){
    		int v = e.v - 2, u = e.u - 2;
    		if(v < 0)v += n + 2;
    		if(u < 0)v += n + 2;
    		f[v][u] = e.flow;
    	}
    	fi0(used);
    	F(i, 0, n)if(!used[i]){ancnt++; sz = 0; mark(i);}
    	fi0(used);
    	printf("%d", ancnt);
    	F(i, 0, n)if(!used[i]){printf("\n"); sz = 0; mark(i); printf("%d ", sz); F(j, 0, sz)printf("%d ", lst[j]);}
    	ret 0;
    }