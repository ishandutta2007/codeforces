using namespace std;
#include"cstdio"
#include"iostream"
#include"cstring"
#include"algorithm"
#include"cmath"
#define N 10001
#define int long long
const int mod = 1000000007;
int res[2002][2002] , C[2001][2001] , ans[2001][2001];
int A[N];
int n , m , k;
void prework() {
	C[0][0] = 1;
	for(int i = 1; i <= 1001 ; i ++) {
		C[i][0] = 1;
		for(int j = 1 ;j <= 1001 ;j ++) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]);
			C[i][j] = C[i][j] % mod;
		}
	}
	A[0] = 1;
	for(int i = 1;i <= 1000;i++) {
		A[i] = A[i-1] * i;
		A[i] = A[i]  % mod;
	}
	res[0][0] = 1;
	for(int i = 1 ; i <= 1000 ;i ++) {
		for(int j = 50; j >= 0; j--) {
			for(int k = 1000 - i; k >= 0; k--) {
				res[j + 1][k + i] += res[j][k];
				res[j + 1][k + i] %= mod; 
			}
		}
	}
	memset(ans, 0 , sizeof(ans));
	for(int i = 1; i <= 1001 ;i ++) {
		for(int  j = 1; j <= 45 ; j ++) {
			ans[i][j] = 0;
			for(int k = 1 ; k <= i ;k++) {
				ans[i][j] = ans[i][j] + C[i - k + j][j] % mod  * res[j][k] % mod * A[j] % mod;
				if(ans[i][j] >= mod) {
					ans[i][j] = ans[i][j] % mod;
				}
			}
		}
	}
}
void read() {
	scanf("%lld%lld",&n,&k);
	int wh = (k * (k + 1)) / 2;
	if(wh > n) {
		ans[n][k] = 0;
	}
}
void print() {
	printf("%lld\n",ans[n][k]);
}
void onecase() {
	read();
	print();
}
main() {
	prework();
	int t; cin>>t;
	while(t -- ) {
		onecase();
	}
}