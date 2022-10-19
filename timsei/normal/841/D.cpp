#include<bits/stdc++.h>
using namespace std;

const int N = 500005;
const int M = N * 2;

#define Foreachson(i,x) for(int i = fir[x];i;i = ne[i])

int fir[N] , ne[M] , to[M] , cnt = 1 , ans , n , x, y , k , d[N] , m , c[N];
#define Pair pair<int,int>
int out[N] , depth[N];

bool vis[N];

int yes[N];

void add(int x ,int y) {
	ne[++cnt] = fir[x]; fir[x] = cnt; to[cnt] = y;
}

void link(int x ,int y) {
	add(x,y);add(y,x);
}

void dfs(int x ,int f ,int fl) {
	vis[x] = 1;
	Foreachson(i,x) {
		int V = to[i];
		if(V == f || vis[V]) continue;
		dfs(V,x,i / 2);
	}
	
	if(fl != 0) {
		if(c[x] != d[x]) {
			yes[fl] = 1;
			c[x] ^= 1;
			c[f] ^= 1;
		}
	}
}

void doit(int x) {
	dfs(x , 0 , 0);
	if((d[x] != -1) && (c[x] != d[x])) {
		puts("-1");return;	
	}
	for(int i = 1;i <= m;i ++) if(yes[i]) {
		out[++k] = i;
	}
	printf("%d\n",k);
	for(int i = 1;i <= k;i ++) printf("%d\n",out[i]);
}

int main() {
	scanf("%d%d",&n,&m);
	int it = -1;
	for(int i = 1;i <= n;i ++) {
		scanf("%d",&d[i]);
		if(d[i] == -1) {
			it = i;
		}
	}
	if(it != -1) {
		for(int i = 1;i <= n;i ++) if((d[i] == -1) && (i != it)) d[i] = 0;
	}
	else it = 1;
	for(int i = 1;i <= m;i ++) {
		scanf("%d%d",&x,&y);
		link(x,y);
	}
	doit(it);
}