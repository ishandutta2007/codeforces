#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int K = 15;

int a[K][N] , n , m , x , y , l , r , opt , more[K][N] , k , q , tot;
bitset <4096> B[N << 1];

int main(void) {
	scanf("%d%d%d" , &n , &k , &q);
	for(int i = 1;i <= k;++ i) {
		for(int j = 1;j <= n;++ j) {
			scanf("%d" , &a[i][j]);
		}
	}
	for(int i = 1;i <= k;++ i) for(int j = 1;j < (1 << k);++ j) B[i][j] = !!((1 << (i - 1)) & j);
	// any number is bigger than the min of the set
	for(int i = 1;i <= k;++ i) {
		for(int j = 1;j <= n;++ j) {
			for(int p = 1;p <= k;++ p) {
				if(a[p][j] >= a[i][j]) more[i][j] |= (1 << (p - 1));
			}
		}
	}
	tot = k;
	for(;q --> 0;) {
		scanf("%d%d%d" , &opt , &x , &y);
		if(opt <= 2) {
			B[++ tot] = (opt == 1) ? B[x] | B[y] : B[x] & B[y];
		}
		else {
			int ans = -1e9;
			for(int i = 1;i <= k;++ i) if(B[x][more[i][y]]) ans = max(ans , a[i][y]);
			printf("%d\n" , ans);
		}
	}
}