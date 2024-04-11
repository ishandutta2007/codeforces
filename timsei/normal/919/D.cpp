#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
const int M = N * 2;

int n , m , fir[N] ,  ne[M] , to[M] , cnt , stk[N] , ans , Vis[N] , dp[N] , tot , du[N] , y;
char s[N];
bool vis[N] , in[N];

#define Foreachson(i , x) for(int i = fir[x];i;i = ne[i])

void get(int x) {
	if(Vis[x] == y) return;
	Vis[x] = y; dp[x] = 0;
	Foreachson(i , x) {
		register int V = to[i];
		get(V);
		dp[x] = max(dp[x] , dp[V]);
	}
	dp[x] = (s[x] == y + 'a') + dp[x];
	ans = max(ans , dp[x]);
}

queue <int> q;

int main(void) {
	scanf("%d%d" , &n , &m);
	scanf("%s" , s + 1);
	for(int i = 1;i <= m;++ i) {
		int x , y;
		scanf("%d%d" , &x , &y);
		ne[++ cnt] = fir[x]; fir[x] = cnt; to[cnt] = y; ++ du[y];
	}
	for(int i = 1;i <= n;++ i) if(!du[i]) q.push(i) , ++ tot;
	while(!q.empty()) {
		int ind = q.front(); q.pop();
		Foreachson(i , ind) {
			int V = to[i];
			if(-- du[V] == 0) {
				q.push(V);
				++ tot;
			}
		}
	}
	if(tot != n) {
		puts("-1"); return 0;
	}
	memset(Vis , 127 , sizeof(Vis));
	for(int i = 0;i < 26;++ i) {
		y = i;
		for(int j = 1;j <= n;++ j) if(Vis[j] != i) get(j);
	}
	cout << ans << endl;
}