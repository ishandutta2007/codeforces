#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <map>
using namespace std;

const int N = 2e3 + 5;
const int M = 2e5 + 5;

typedef long long LL;

LL Dis[2][N] , n , m , x , y , z , dp[N][N][2] , S[N][N] , T[N][N] , s , t , pr[N] , P[N];
long long ma[N][N] , X[N] , Y[N];

LL fir[N] , ne[M] , to[M] , C[M] , cnt;

bool inq[N];

void add(LL x ,LL y , LL z) {
	ne[++ cnt] = fir[x]; fir[x] = cnt; to[cnt] = y; C[cnt] = z;
}

void link(LL x , LL y , LL z) {
	add(x , y , z); add(y , x , z);
}

#define Foreachson(i , x) for(LL i = fir[x];i;i = ne[i])

struct NODE {
	LL x , dis;
	friend bool operator < (NODE xxx , NODE yyy) {
		return xxx.dis > yyy.dis;
	}
};

priority_queue <NODE> q;

LL d;

bool cmp(LL x , LL y) {
	return Dis[d][x] < Dis[d][y];
}

void dijkstra(LL s , LL *dis) {
	memset(dis , 127 , sizeof(dis));
	memset(inq , 0 , sizeof(inq));
	while(!q.empty()) q.pop();
	q.push((NODE){s , 0});
	while(!q.empty()) {
		while(!q.empty() && inq[q.top().x]) q.pop();
		if(q.empty()) break;
		NODE ind = q.top(); q.pop();
		inq[ind.x] = 1; dis[ind.x] = ind.dis;
		Foreachson(i , ind.x) {
			LL V = to[i];
 			if(inq[V]) continue;
			q.push((NODE){V , ind.dis + C[i]});
		}
	}
}

LL GS(LL sx , LL sy, LL tx, LL ty) {
	return S[tx][ty] + S[sx - 1][sy - 1] - S[sx - 1][ty] - S[tx][sy - 1];
}

LL GT(LL sx , LL sy, LL tx, LL ty) {
	return T[tx][ty] + T[sx - 1][sy - 1] - T[sx - 1][ty] - T[tx][sy - 1];
}


int main(void) {
	cin >> n >> m;
	cin >> s >> t;
	for(LL i = 1;i <= n;++ i) cin >> pr[i];
	for(LL i = 1;i <= m;++ i) {
		cin >> x >> y >> z;
		link(x , y , z);
	}
	dijkstra(s , Dis[0]); dijkstra(t , Dis[1]);
	d = 0;
	for(LL i = 1;i <= n;++ i) P[i] = i;
	sort(P + 1 , P + n + 1 , cmp);
	LL t1 = 0 , t2 = 0;
	for(LL i = 1;i <= n;++ i) {
		if(Dis[d][P[i]] != Dis[d][P[i - 1]] || i == 1) ++ t1;
		X[P[i]] = t1;
	}
	d = 1;
	sort(P + 1 , P + n + 1 , cmp);
	for(LL i = 1;i <= n;++ i) {
		if(Dis[d][P[i]] != Dis[d][P[i - 1]] || i == 1) ++ t2;
		Y[P[i]] = t2;
	}
	for(LL i = 1;i <= n;++ i) S[X[i]][Y[i]] += pr[i] , ++ T[X[i]][Y[i]];
	++ n;
	for(LL i = 1;i <= n;++ i) {
		for(LL j = 1;j <= n;++ j) {
			S[i][j] += S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];
			T[i][j] += T[i - 1][j] + T[i][j - 1] - T[i - 1][j - 1];
		}
	}
		
	for(LL i = n - 1;i >= 0;-- i) {
		for(LL j = n - 1;j >= 0;-- j) {
			if(GT(i + 1 , j + 1 , i + 1 , n) == 0) dp[i][j][0] = dp[i + 1][j][0];
			else dp[i][j][0] = max(dp[i + 1][j][0] , dp[i + 1][j][1]) + GS(i + 1 , j + 1 , i + 1 , n);
			if(GT(i + 1 , j + 1 , n , j + 1) == 0) dp[i][j][1] = dp[i][j + 1][1];
			else dp[i][j][1] = min(dp[i][j + 1][0] , dp[i][j + 1][1]) - GS(i + 1 , j + 1 , n , j + 1);
		}
	}
	long long one = dp[0][0][0];
	if(one == 0) {
		puts("Flowers");
		return 0;
	}
	if(one > 0) puts("Break a heart"); else puts("Cry");
}