// 
#include<bits/stdc++.h>
using namespace std;

const int N = 105;
const int M = N * 2;
const int INF = 2e9;

int fir[N] ,ne[M] , to[M] , dis[N][N] , leave[N] , dp[N][N] ,n , St , C[N] , m , Cur[N] , du[N] , vis[N][N] , L , cnt;
vector<int>G;

int getans(int x, int num);

bool Pd(int x , int num , int from , vector<int>&G) {
	int all = 0;
	for(int i = 0;i < (int) G.size();i ++) {
		int V = G[i] , Dis = dis[from][V];
		int res = 0;
		for(int j = 0;j < num;j ++) {
			if(Dis + getans(V , j) >= x) {
				res = max(res , num - j);
			}
		}
		all += res;
	}
	if(all < num) return 0;
	return 1;
}

int getans(int x , int num) {
	if(vis[x][num]) return dp[x][num];
	if(num == 0) return 0;
	vector<int>G; 
	G.clear();
	for(int i = 1;i <= L;i ++) if(leave[i] != x) {
		G.push_back(leave[i]);
	}
	int L = 0 , R = INF , res = 0;
	while(L <= R) {
		int Mid = (L + R) >> 1;
		if(Pd(Mid , num, x , G)) {
			L = Mid + 1; res = Mid;
		}
		else R = Mid - 1;
	}
	return dp[x][num] = res * (vis[x][num] = 1);
}

void add(int x, int y , int z) {
	ne[++ cnt] = fir[x]; fir[x] = cnt; to[cnt] = y; du[x] ++; C[cnt] = z;
}

void link(int x, int y, int z) {
	add(x , y , z); add(y ,x ,z);
}

#define Foreachson(i , x) for(int i = fir[x];i;i = ne[i])

void dfs(int x , int f, int no) {
	Foreachson(i , x) {
		int V = to[i];
		if(V != f) {
			dis[no][V] = dis[no][x] + C[i];
			dfs(V , x , no);
		}
	}
}

int pre[N] , col;
vector<int>Vec[N];

void dance(int x , int f) {
	if(f == St) pre[x] = x;else pre[x] = pre[f];
	Foreachson(i , x) {
		int V = to[i];
		if(V != f) {
			dance(V , x);
		}
	}
}

int Num[N] , now[N];

bool pd(int x) {
	memset(now , 0 , sizeof(now));
	for(int i = 0;i < (int) G.size();i ++) {
		int V = G[i] , Dis = dis[St][V]; 
		int res = 0;
		for(int j = 0;j < m;j ++) {
			if(Dis + getans(V , j) >= x) {
				res = max(res , m - j);
			}
		}
		now[pre[V]] += res;
	}
	Foreachson(i , St) {
		int V = to[i];
		if(now[V] < Num[V]) return 0;
	}
	return 1;
}

int main(void) {
	scanf("%d",&n);
	for(int i = 1;i <=n - 1;i ++) {
		int x, y  , z;
		scanf("%d%d%d",&x,&y,&z);
		link(x , y , z);
	}
	for(int i = 1;i <= n;i ++) dfs(i , 0 , i);
	scanf("%d",&St);
	scanf("%d",&m);
	for(int i = 1;i <= m;i ++) scanf("%d",&Cur[i]);
	for(int i = 1;i <= n;i ++) if(du[i] == 1) leave[++ L] = i;
	dance(St , 0);
	for(int i = 1;i <= m;i ++) Num[pre[Cur[i]]] ++;
	for(int i = 1;i <= L;i ++) if(leave[i] != St) G.push_back(leave[i]);
	int L = 0 , R = INF , ans = 0;
	while(L <= R) {
		int Mid = (L + R) >> 1;
		if(pd(Mid)) {
			L = Mid + 1; ans =  Mid;
		}
		else R = Mid - 1;
	}
	printf("%d\n" , ans);
}