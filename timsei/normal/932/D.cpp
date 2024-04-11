#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 6e5 + 5;
const int Si = 20;

int n , m , x , y , l , r , st[N][20] , mx[N][20] , pre[N] , fa[N] , S[N][20] , ty , ans , sz = 0 , W[N] , val[N];

void getit(int x) {
	int now = fa[x];
	val[x] = max(val[now] , W[x]);
	if(W[fa[x]] >= W[x]) {
		pre[x] = now;
	}
	else{
		if(val[now] < W[x]){
			pre[x] = 0;
		}
		else {
			for(int i = 19;i >= 0;-- i) if(W[mx[now][i]] < W[x]) now = mx[now][i];
			pre[x] = pre[now];
		}
	}
	mx[x][0] = pre[x];
	S[x][0] = W[pre[x]];
	for(int i = 1;i < Si;++ i) mx[x][i] = mx[mx[x][i - 1]][i - 1] , S[x][i] = (S[x][i - 1] + S[mx[x][i - 1]][i - 1] >= 1e18) ? 1e18 : (S[x][i - 1] + S[mx[x][i - 1]][i - 1]);
}

int getans(int x , int y) {
	int now = 0;
	if(y < W[x]) return 0;
	y -= W[x];
	now = 1;
	for(int i = 19;i >= 0;-- i) if(S[x][i] <= y){
		y -= S[x][i]; now += 1 << i; x = mx[x][i];
	}
	return now;
}

main(void) {
	int t; ++ sz; W[0] = 1e18;
	S[1][0] = 1e18; mx[1][0] = 0;
	for(int i = 1;i < Si;++ i) S[1][i] = 1e18;
	cin >> t;
	for(;t --;) {
		scanf("%lld%lld%lld" , &ty , &x , &y);
		if(ty == 1) {
			x ^= ans; y ^= ans; fa[++ sz] = x; W[sz] = y;
			getit(sz);
		}
		else {
			x ^= ans; y ^= ans;
			printf("%lld\n" , ans = getans(x , y));
		}
	}
//	for(int i = 1;i <= 3;++ i) cerr << fa[i] <<" "<< pre[i] <<" " << W[i] << endl;
}