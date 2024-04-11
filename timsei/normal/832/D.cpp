using namespace std;
#include<bits/stdc++.h>
#define N 200001
#define forw(i,x) for(int i=fir[x];i;i=ne[i])
int st[N][31], fa[N] , d[N];
#define per t
int n , m , k , q ,lca1 ,lca2 , c1 , c2 ,ans;
int per[4];
int ne[N*2] , fir[N] , to[N*2] , cnt;
void add(int x,int y) {
	ne[++cnt] = fir[x]; fir[x] = cnt; to[cnt] = y;
}
void dfs(int x,int f) {
	d[x] = d[f] + 1;
	fa[x]=f;
	st[x][0]=f;
	for(int i=1;i <= 25 ;i ++ ) {
		st[x][i] = st[st[x][i-1]][i-1];
	}
	forw(i,x) {
		int V= to[i];
		if(V==f) continue;
		dfs(V,x);
	}
}
int LCA(int x,int y) {
	if(d[x]<d[y]) swap(x,y);
	for(int i = 25; i >= 0 ; i--) {
		if(d[st[x][i]] >= d[y]) x = st[x][i];
	}
	if(x==y) return x;
	for(int i = 25; i >= 0; i --) {
		if(st[x][i] != st[y][i]) {
			x=st[x][i];y=st[y][i];
		}
	}
	return st[x][0];
}
void pd() {
	int a = LCA(per[1], per[2]);
	int b = LCA(per[1], per[3]);
	int c = LCA(per[2], per[3]);
	if (b == c)
	ans = max(ans, d[a] - d[b] + d[per[3]] - d[b]);
	else {
		if (a == c) ans = max(ans, d[per[3]] - d[b]);
		else ans = max(ans, d[per[3]] - d[c]);
	}
}
int main() {
	scanf("%d%d",&n,&q);
	for(int i= 2 ;i<= n; i++) {
		scanf("%d" , &k);
		add(i,k);add(k,i);
	}
	dfs(1,0);
	for(int i = 1 ;i<=q;i++) {
		for(int j = 1;j<= 3 ;j++)  {
			scanf("%d",&per[j]);
		}
		sort(per+1,per+4);
		ans=0;
		pd();
		while(next_permutation(per+1,per+4)) {
			pd();
		}
		printf("%d\n",ans+1);
	}
}