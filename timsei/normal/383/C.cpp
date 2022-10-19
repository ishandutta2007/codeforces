#include <bits/stdc++.h>
using namespace std;

const int N = 1111111;
const int M = N * 2;

#define int long long

int dep[N] , n , m , x , y , fir[N] , ne[M] , to[M] , cnt , in[N] , dfs_clock , out[N] , val[N];

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
	dep[x] = dep[f] + 1;
	in[x] = ++ dfs_clock;
	Foreachson(i , x) {
		int V = to[i];
		if(V == f) {
			continue;
		}
		dfs(V , x);
	}
	out[x] = dfs_clock;
}

int S[2][N];

#define lowbit(x) (x & (-x))

void add(int x , int v , int ty) {
	for(int i = x;i < N;i += lowbit(i)) {
		S[ty][i] += v;
	}
}

int sum(int x , int ty) {
	int res = 0;
	for(int i = x;i;i -= lowbit(i)) {
		res += S[ty][i];
	}
	return res;
}

main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1;i <= n;++ i) 
	cin >> val[i];
	int a , b , c;
	for(int i = 1;i < n;++ i) {
		cin >> x >> y;
		link(x , y);
	}
	dfs(1 , 0);
	for(;m --;) {
		cin >> a;
		if(a == 1) {
			cin >> b >> c;
			add(in[b] , c , dep[b] & 1);
			add(out[b] + 1 , -c , dep[b] & 1);
			add(in[b] , -c , (dep[b] & 1) ^ 1);
			add(out[b] + 1 , c , (dep[b] & 1) ^ 1);
		}
		else {
			cin >> b;
			cout << sum(in[b] , (dep[b] & 1)) + val[b] << endl;
		}
	}
}