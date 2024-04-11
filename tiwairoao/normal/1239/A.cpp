#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 100000;
const int MOD = int(1E9) + 7;
int f[MAXN + 5];
int main() {
	int n, m; scanf("%d%d", &n, &m);
	f[0] = f[1] = 1;
	for(int i=2;i<=max(n,m);i++)
		f[i] = (f[i-1] + f[i-2])%MOD;
	printf("%lld\n", 2LL*(f[n] + f[m] - 1)%MOD);
}
//It's just for test.