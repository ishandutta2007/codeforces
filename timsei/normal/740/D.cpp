//SB le
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;

typedef long long LL;

const int N = 2e5 + 5;
const int M = N * 2;

int n , m , st[N][31], tag[N];
LL val[N][31] , hold[N] , to_root[N] , depth[N], w[N];

#define Foreachson(i,x) for(int i = fir[x];i;i = ne[i])
#define maptype map<int,int>

int cnt , fir[N] , ne[M] , to[M] , C[M] , ans[N];

void add(int x ,int y ,int z) {
	ne[++ cnt] = fir[x]; fir[x] = cnt; to[cnt] = y; C[cnt] = z;
}

void link(int x ,int y,int z) {
	add(x,y,z);add(y,x,z);
}

void dfs(int x ,int f) {
	st[x][0] = f;
	depth[x] = depth[f] + 1;
	val[x][0] = w[x];
	for(int i = 1;i <= 25;i ++) {
		st[x][i] = st[st[x][i-1]][i-1];
		val[x][i] = val[st[x][i-1]][i-1] + val[x][i-1];
	}
	Foreachson(i,x) {
		int V = to[i];
		if(V == f) continue;
		to_root[V] = to_root[x] + C[i];
		dfs(V,x);
	}
	if (hold[x] >= to_root[x]) {
		ans[st[x][0]] ++;
//		cout<<x<<endl; 
		return;
	}
//	cout<<x<<" bef"<<endl;
	if(hold[x] < w[x]) return;
	int it = x;
	for(int i = 25;i >= 0;i --) {
		if(val[it][i] <= hold[x]) {
			hold[x] -= val[it][i];
			it = st[it][i];
		}
	}
	ans[st[it][0]] --; ans[st[x][0]] ++;
//	cout<<x<<" "<<it<<endl;
}

void getans(int x ,int f) {
	Foreachson(i,x) {
		int V = to[i];
		if(V == f) continue;
		getans(V,x);
		ans[x] += ans[V];
	}
}

int main() {
//	freopen("data.txt","r",stdin);
//	freopen("myout.txt","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++) scanf("%d",&hold[i]);
	for(int i = 2;i <= n;i ++) {
		int p ,ww;
		scanf("%d%d",&p,&ww);
		w[i] = ww;
		link(i,p,ww);
	}
	for(int i = 1;i <= n;i ++) {
		for(int j = 1;j <= 30; j ++) 
		val[i][j] = 1e18;
	}
	dfs(1,0);
	getans(1,0);
	for(int i = 1;i <= n;i ++) printf("%d ",ans[i]);puts("");
//	for(int i = 1;i <= n;i ++) cout<<st[i][0]<<endl;
}