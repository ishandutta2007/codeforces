%:pragma GCC optimize(4)
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;

const int N = 200005;
const int M = 200005 * 2;

int fir[N] , ne[M] , to[M] , cnt , G[5005][5005] , n , m;

int gcd(int x ,int y) {
	if(y == 0) return x;
//	if(x <= 5000 && y <= 5000) return G[x][y];
	return gcd(y , x% y);
}

const int GMAX = 5000;

void getgcd() {
	for(int i = 1;i <= GMAX;i ++) G[i][0] = G[0][i] = i;
	for(int i = 1;i <= GMAX;i ++) {
		for(int j = 1;j <= GMAX;j ++) {
			if(i == j) G[i][j] = i;
			else  {
				if(i > j) G[i][j] = G[i - j][j];
				else G[i][j] = G[i][j - i];
			}
		}
	}
}

#define Set set<int>
#define Foreachson(i,x) for(int i = fir[x];i;i = ne[i])

void add(int x ,int y) {
	ne[++ cnt] = fir[x];
	fir[x] = cnt;
	to[cnt] = y;
}

void link(int x ,int y) {
	add(x,y);
	add(y,x);
}

int x , y , val[N] , no[N] , ans[N];
Set :: iterator hh;

void dfs(int x , int f ,Set it) {
	Foreachson(i,x) {
		int V = to[i];
		if(V == f) continue;
		Set nxt; 
		nxt.clear();
		int Ans = 0; 
		for(hh = it.begin(); hh != it.end(); hh ++) {
			int nu = *hh;
			nu = gcd(nu,val[V]);
			nxt.insert(nu);
			Ans = max(Ans , nu);
		}
		Ans = max(Ans , no[x]);
		ans[V] = Ans;
		nxt.insert(no[x]);
		no[V] = gcd(no[x] , val[V]);
		dfs(V , x , nxt);
	}
}

int main() {
	getgcd();
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++) scanf("%d",&val[i]);
	for(int i = 1;i <= n - 1;i ++) {
		scanf("%d%d",&x,&y);
		link(x,y);
	}
	Set index; index.clear();
	index.insert(0);
	ans[1] = no[1] = val[1];
	dfs(1,0,index);
	for(int i = 1;i <= n;i ++) printf("%d ",ans[i]);
}