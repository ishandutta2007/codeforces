#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int a[N] , f[N] ,n , m , x , y , l , r , k , g[N];
int S[N][11];

int p(int x) {
	int now = 1;
	while(x) {
		if(x % 10) now = now * (x % 10);
		x /= 10;
	}
	return now;
}

int G(int x) {
	int T = p(x);
	if(T < 10) return T;
	else return g[T];
}

main(void) {
	for(int i = 1;i < N;++ i) g[i] = G(i);
	for(int i = 1;i < N;++ i) {
		for(int j = 0;j < 10;++ j) S[i][j] = S[i - 1][j];
		++ S[i][g[i]];
	}
	int t , l , r , k;
	for(scanf("%d" , &t);t --;) {
		scanf("%d%d%d" , &l , &r , &k);
		cout << S[r][k] - S[l - 1][k] << endl;
	}
}