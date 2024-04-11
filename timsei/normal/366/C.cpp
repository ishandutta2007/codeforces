%:pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;

const int N = 10005;

bitset<N>B[2][N];

int n , m , k , l , a[N] , b[N]  , ans;
bool vis[105][N];

int main(void) {
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;i ++) scanf("%d",&a[i]);
	for(int i = 1;i <= n;i ++) scanf("%d",&b[i]);
	for(int i = 1;i <= n;i ++) swap(a[i] , b[i]);
	vis[1][0] = 1; B[1][0][0] = 1;
	int now = 1;
	for(int i = 1;i <= n;i ++) {
		for(int j = 0;j <= 10000;j ++) if(vis[i - 1][j]) B[now ^ 1][j] = 0;
		for(int j = 0;j <= 10000;j ++) if(vis[i][j]) {
			vis[i + 1][j] = 1;
			B[now ^ 1][j] |= B[now][j];
			if(a[i] + j <= 10000) {
				B[now ^ 1][a[i] + j] |= (B[now][j] << b[i]);
				vis[i + 1][a[i] + j] = 1;
			}
		}
		now ^= 1;
		for(int j = 0;j <= 10000;j ++) if(j * k <= 10000 && B[now][j][j * k]) {
			ans = j;
		}
	}
	if(ans * k == 0) {
		puts("-1"); return 0;
	}
	cout<<ans * k<<endl;
}