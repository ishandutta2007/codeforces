#include <bits/stdc++.h>
 
using namespace std;
 
#define FOE(i, s, t) for (int i = s; i <= t; i++)
#define FOR(i, s, t) for (int i = s; i < t; i++)
#define FOD(i, s, t) for (int i = s; i >= t; i--)
 
#define LL long long
#define mp make_pair
#define pb push_back
#define K 60001
#define M 600001 

int d, n;
#define inf 100000000

vector<int> res;
struct CMaxFlow{
    int nxt[M], dir[M], h, n, que[M], rev[M], cost[M], f[M], dis[M], vis[M];

    void init(int cnt){
        FOE(i, 1, cnt) nxt[i] = -1;
        n = h = cnt;
    }

    //undirected: add twice
    //format: u->v, cost c, flow d

    void insert(int u, int v, int c, int w){
        nxt[++h] = nxt[u]; nxt[u] = h; dir[h] = v; rev[h] = h + 1; cost[h] = c; f[h] = w;
        nxt[++h] = nxt[v]; nxt[v] = h; dir[h] = u; rev[h] = h - 1; cost[h] = -c; f[h] = 0;
    }
    int finalflow, finalcost;
    int d[M], sus[M], pre[M], id[M];

    bool ShortestPath(int S, int T){
        int head = 0, tail = 1;
        FOE(i, 0, n){
            dis[i] = inf;
            vis[i] = false;
        }
        dis[S] = 0;
        que[0] = S;
        while(tail != head){
            int u = que[head];
            vis[u] = true;
            for (int po = nxt[u]; po > 0; po = nxt[po]){
                if(f[po] && dis[dir[po]] > dis[u] + cost[po]){
                    dis[dir[po]] = dis[u] + cost[po];
                    pre[dir[po]] = u;
                    id[dir[po]] = po;
                    if(!vis[dir[po]]){
                        vis[dir[po]] = true;
                        que[tail++] = dir[po];
                        tail %= M;
                    }
                }}
            vis[u] = false;
            head = (head + 1) % M;
        }
        if(dis[T] == inf) return false;
        return true;
    }

    void fix(int S, int u){
        if (u == S) return;
        int neg = pre[u];
        sus[neg] = u;
        fix(S, neg);
    }

    int argu(int u, int T, int flow){
        if (u == T) return flow;
        int ee = id[sus[u]];
        int ff = argu(sus[u], T, min(flow, f[ee]));
    //	printf("%d->%d via %d, flow %d\n", u, sus[u], ee, ff);
        f[ee] -= ff;
        f[rev[ee]] += ff;
        finalcost += cost[ee] * ff;
        return ff;
    }

    void CostedMaxFlow(int S, int T){
        finalflow = finalcost = 0;
        while (ShortestPath(S, T)){
            fix(S, T);
            finalflow += argu(S, T, inf);
        }
        return;
    }
}F;
int a[K];
int handled[K];
int nxt[K];

void trace(int u) {
	handled[u] = 1;
	
	if (nxt[u] == -1) return;
	
	FOR(i, 0, d) {
		int v = (1 << i);
		
		if ((nxt[u] & v) && !(u & v)) {
			res.pb(i);
		}
	}
	
	trace(nxt[u]);
}

int sol[K];

int main() {
	scanf("%d%d", &d, &n);
	
	FOE(i, 1, n) {
		string x; cin >> x;
		
		int v = 0;
		
		FOD(j, d - 1, 0) {
			v = v * 2 + (int)(x[j] - '0');
		}
		
	//	printf("V = %d\n", v);
		
		a[v] = 1;
	}
	
	int h = (1 << d);
	
	F.init(h * 2 + 3);
	int S = h * 2 + 1;
	int T = h * 2 + 2;
	
	FOR(i, 0, h) F.insert(S, i, 0, 1);
	
	FOR(i, 0, h) {
		FOR(j, 0, d) {
			int v = (1 << j);
			if (i & v) sol[i]++;
		}
	}
	
	FOR(i, 1, h) if (a[i]) {
		F.insert(i + h, T, 0, 1);
		FOD(j, i - 1, 0) if (a[j] && ((j & i) == j)) {
			F.insert(j, i + h, -sol[j], 1);
		}
	}
	
	F.CostedMaxFlow(S, T);
	FOR(i, 0, h) nxt[i] = -1;
	FOR(i, 0, h) {
        for (int po = F.nxt[i]; po > 0; po = F.nxt[po]) {
        	int tar = F.dir[po];
        	int f = F.f[po];
			if (f == 0 && tar != S) {
				nxt[i] = tar - h;
			}
		}
	}
	
	FOR(i, 0, h) if ((nxt[i] != -1 || a[i]) && !handled[i]) {
		FOR(j, 0, d) {
			int v = (1 << j);
			
			if (i & v) {
				res.pb(j);
			}
		}
		trace(i);
		res.pb(-1);
	}
	
	printf("%d\n", res.size() - 1);
	
	FOR(i, 0, (int)(res.size()) - 1) {
		int x = res[i];
		if (x == -1) printf("R");
		else printf("%d", x);
		printf(" ");	
	}
}