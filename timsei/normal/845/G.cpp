%:pragma GCC optimize(4)
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 100005;
const int M = N * 2;

int fir[N] , ne[M] , to[M] , C[M] , cnt , d[N] , n , m;

int cir[M] , cirnum , fil , pow[31];

bool vis[N];

void add(int x ,int y ,int z) {
	ne[++ cnt] = fir[x]; fir[x] = cnt; to[cnt] = y; C[cnt] = z;
}

void link(int x ,int y ,int z) {
	add(x,y,z); add(y,x,z);
} 

#define Foreachson(i,x) for(int i = fir[x]; i ;i = ne[i])

void dfs(int x) {
	vis[x] = 1;
	Foreachson(i,x) {
		int V = to[i];
		if(vis[V]) {
			int it = d[x] ^ C[i] ^ d[V];
			if(it != 0)
			cir[++ cirnum] = it;
		}
		else {
			d[V] = d[x] ^ C[i];
			dfs(V);
		}
	}
}

void xiao_yuan(void) {
	for(int i = 30;i >= 0;i --) {
		int k = pow[i];
		int it = fil + 1;
		while(it <= cirnum && !(k & cir[it])) it ++;
		if(it == cirnum + 1) continue;
		fil ++;
		swap(cir[it] , cir[fil]);
		for(int j = 1;j <= cirnum;j ++) if(j != fil){
			if(cir[j] & k) cir[j] ^= cir[fil];
		}
	}
}

void build(void) {
	scanf("%d%d",&n,&m);
	int x ,y,z;
	for(int i = 1;i <= m;i ++) {
		scanf("%d%d%d",&x,&y,&z);
		link(x,y,z);
	}
}

int main() {
	pow[0] = 1;
	for(int i = 1;i <= 30;i ++) pow[i] = pow[i - 1] * 2;
	build();
	dfs(1);
	xiao_yuan();
	int ans = d[n];
	for(int i = 1;i <= fil;i ++) ans = min(ans , ans ^ cir[i]);
	printf("%d\n",ans);
}