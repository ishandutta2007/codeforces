#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
const int M = N * 2;

int n , m  , x , y , a , b , u , v , fir[N] , ne[M] , to[M] , cnt , S[N] , fa[N];

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
	fa[x] = f;
	S[x] = 1;
	Foreachson(i , x) {
		int V = to[i];
		if(V == f)
		continue;
		dfs(V  , x);
		S[x] += S[V];
	}
}

main(void) {
	scanf("%d" , &n); cin >> a >> b;
	for(int i = 1;i < n;++ i) {
		scanf("%d%d" , &x , &y);
		link(x , y);
	}
	dfs(a , 0);
	int now = b;
	int res = n;
	while(fa[now] != a) {
		now = fa[now];
	}
	res -= S[now];
	cout << n * 1LL * (n - 1) - res * 1LL * S[b] << endl;
}