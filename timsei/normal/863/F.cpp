#include<bits/stdc++.h>
using namespace std;

const int N = 125;
const int M = N * N + N * N + 105;

int fir[N] , ne[M] , to[M] , C[M] , Cost[M] , cnt = 1 , dis[N] , ans , L[N] , R[N] ,n , q , ty , l , r ,s , t , v , pre[N] , inq[N];

#define Pair pair<int,int>

void read(void) {
	scanf("%d%d",&n,&q);
	s = 0 , t = 2 * n + 1;
	for(int i = 1;i <= n;i ++) L[i] = 1, R[i] = n;
	for(int i = 1;i <= q;i ++) {
		scanf("%d%d%d%d",&ty,&l,&r , &v);
		if(ty == 1) {
			for(int j = l;j <=r ;j ++) {
				L[j] = max(L[j] , v);
			}
		}
		else {
			for(int j = l;j <= r;j ++) {
				R[j] = min(R[j] , v);
			}
		}
	}
}

void add(int x , int  y , int fl ,int Co) {
	ne[++ cnt] = fir[x]; fir[x] = cnt; to[cnt] = y; C[cnt] = fl; Cost[cnt] = Co;
}

void link(int x , int y ,int fl , int Co) {
	add(x , y , fl , Co);
	add(y , x , 0 , - Co);
}

void build(void) {
	for(int i = 1;i <= n;i ++) {
		link(s , i , 1 , 0);
		for(int j = L[i];j <= R[i];j ++) link(i , j + n , 1 , 0);
		for(int j = 1;j <= n;j ++) link(i + n , t , 1 , (j * j - (j - 1) * (j - 1)));
	}
}

#define Foreachson(i , x) for(int i = fir[x];i;i = ne[i])

bool SPFA(int s , int t) {
	memset(dis , 63 , sizeof(dis));
	dis[s] = 0;
	queue<int>q; while(!q.empty()) q.pop();q.push(s);
	while(!q.empty()) {
		int ind = q.front(); inq[ind] = 0;q.pop();
		Foreachson(i , ind) if(C[i]){
			int V = to[i];
			if(dis[V] > dis[ind] + Cost[i]) {
				pre[V] = i;
				dis[V] = dis[ind] + Cost[i];
				if(!inq[V]) {
					inq[V] = 1;
					q.push(V);
				}
			}
		}
	}
	return dis[t] <= 2505;
}

Pair Cost_Flow(int s , int t) {
	Pair ret; ret.first = ret.second = 0;
	while(SPFA(s , t)) {
		int now = t;
		ret.first ++;
		while(pre[now]) {
			ret.second += Cost[pre[now]];
			C[pre[now]] --; C[pre[now] ^ 1] ++;
			now = to[pre[now] ^ 1];
		}
	}
	return ret;
}

int main(void) {
	read();
	build();
	Pair res = Cost_Flow(s , t);
	if(res.first < n) {
		puts("-1");
	}
	else cout<<res.second;
}