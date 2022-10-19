%:pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

const int N = 111111;
const int Block_Size = 400;
const int M = N * 2;

int n , m , x , y , in[N] , out[N] , lim[N] , fir[N] , ne[M] , to[M] , cnt , fa[N];
bool tour[N];
int dfs_clock , dep[N];
int st[N][22];

void add(int x , int y) {
	ne[++ cnt] = fir[x];
	fir[x] = cnt;
	to[cnt] = y;
}

void link(int x , int y) {
	add(x , y);
	add(y , x);
}

#define Foreachson(i , x) for(int i = fir[x];i;i = ne[i])

void dfs(int x , int f) {
	in[x] = ++ dfs_clock;
	fa[x] = f;
	st[x][0] = f;
	dep[x] = dep[f] + 1;
	for(int i = 1;i < 20;++ i)
	st[x][i] = st[st[x][i - 1]][i - 1];
	Foreachson(i , x) {
		int V = to[i];
		if(V == f)
		continue;
		dfs(V , x);
	}
	out[x] = ++ dfs_clock;
}

bool cmp(int x , int y) {
	return in[x] < in[y];
}

int W[N] , tot;

int LCA(int x , int y) {
	if(x == y)
	return x;
	if(dep[x] > dep[y]) {
		swap(x , y);
	}
	for(int i = 19;i >= 0;-- i) {
		if(dep[st[y][i]] >= dep[x]) 
		y = st[y][i];
	}
	if(x == y) return x;
	for(int i = 19;i >= 0;-- i) {
		if(st[x][i] != st[y][i]) {
			x = st[x][i];
			y = st[y][i];
		}
	}
	return st[x][0];
}

int A[N] , All , pa[N] , who[N] , tag[N] , ans ,fo[N];

vector <int> G[N] , B , C , D;

vector <int> E[N] , F[N];

void calc(int x , int y) {
	int a = x , b = y;
	while(y != x) {
		if(y != a && y != b) {
			if(!tour[y])
			B.push_back(lim[y]);
		}
		y = fa[y];
	}
	sort(B.begin() , B.end());
	if(!B.size())
	return;
	int tot = 1;
	for(int i = 1;i < (int) B.size();++ i) {
		if(B[i] != B[i - 1]) {
			C.push_back(B[i - 1]);
			D.push_back(tot);
			tot = 1;
		}
		else ++ tot;
	}
	C.push_back(B.back());
	D.push_back(tot);
}

int Q[N] , T[N];

void get(int x , int f) {
	Foreachson(i , x) {
		int V = to[i];
		if(V == f)
		continue;
		get(V , x);
	}
	T[fa[x]] += T[x];
	lim[x] += T[x];
}

int stk[N];

bool isson(int x , int y) {
	return in[y] > in[x] && out[y] < out[x];
}

void build(int l , int r) {
	tot = 0;
	int now = 0;
	for(int i = l;i <= r;++ i) {
		A[++ now] = abs(Q[i]);
	}
	A[++ now] = 1;
	sort(A + 1 , A + now + 1 , cmp);
	
	for(int i = 1;i <= now;++ i) {
		if(A[i] != A[i - 1]) {
			W[++ tot] = A[i];
		}
	}
	
	now = tot;
	for(int i = 1;i < now;++ i) {
		W[++ tot] = LCA(W[i] , W[i + 1]);
	}
	sort(W + 1 , W + tot + 1 , cmp);
		
	All = 0;
	for(int i = 1;i <= tot;++ i) {
		if(W[i] != W[i - 1]) {
			A[++ All] = W[i];
		}
	}
	
	int cnt = 0;
		
	for(int i = 1;i <= All;++ i) {
		G[A[i]].clear();
		fo[A[i]] = lim[A[i]];
	}
	
	for(int i = 1;i <= All;++ i) {
		if(!cnt) 
		stk[++ cnt] = A[i];
		else {
			while(!isson(stk[cnt] , A[i]) && cnt) 
			-- cnt;
			stk[++ cnt] = A[i];
			pa[A[i]] = stk[cnt - 1];
		}
		if(pa[A[i]])
		G[pa[A[i]]].push_back(A[i]);
	}
	//pa didn't go right

	for(int i = 1;i <= All;++ i) {
		for(int j = 0;j < (int) G[A[i]].size();++ j) {
			int V = G[A[i]][j];
			B.clear();
			C.clear();
			D.clear();
			calc(A[i] , V);
			E[V] = C; F[V] = D;
			who[V] = 0;
			while(who[V] < E[V].size() && E[V][who[V]] < 0) 
			++ who[V];
			tag[V] = 0;
		}
	}
	
	for(int i = l;i <= r;++ i) {
		if(Q[i] < 0) {
			int now = - Q[i];
			tour[now] = 0;
			while(now) {
				++ fo[now];
				++ tag[now];
				if(!tour[now] && now != -Q[i]) {
					if(fo[now] == 0) {
					 	-- ans;
					}
				}
				if(now == 1) break;
				if(who[now] && E[now][who[now] - 1] + tag[now] >= 0) {
					-- who[now];
					ans -= F[now][who[now]];
				}
				now = pa[now];
			}
			if(fo[-Q[i]] < 0) {
				++ ans;
			}
		}
		else {
			int now = Q[i];
			tour[now] = 1;
			if(fo[now] < 0) -- ans;
			while(now) {
				-- fo[now];
				-- tag[now];
				if(!tour[now]) {
					if(fo[now] == -1) {
						++ ans;
					}
				}
				if(now == 1)
				break;
				if(who[now] < E[now].size() && E[now][who[now]] + tag[now] < 0) {
					ans += F[now][who[now]];
					++ who[now];
				}
				now = pa[now];
			}
		}
		printf("%d " , ans);
	}
	memset(T , 0 , sizeof(T));
	for(int i = l;i <= r;++ i) {
		if(Q[i] < 0) {
			int now = -Q[i];
			tour[now] = 0;
			++ T[now];
		}
		else {
			now = Q[i];
			tour[now] = 1;
			-- T[now];
		}
	}
	get(1 , 0);
}

main(void) {
	scanf("%d" , &n);
	cin >> m;
	for(int i = 2;i <= n;++ i) {
		int x;
		scanf("%d" , &x);
		link(i , x);
		fa[i] = x;
	}
	dfs(1 , 0);
	for(int i = 1;i <= n;++ i)
	scanf("%d", &lim[i]);
	for(int i = 1;i <= m;++ i) {
		scanf("%d" , &Q[i]);
	}
	for(int i = 1;i <= m;i += 1000) {
		build(i , min(i + 999 , m));
	}
}