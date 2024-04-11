#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 200000;
char str[MAXN + 5];
int sum[MAXN + 5];
bool pf[MAXN + 5], sf[MAXN + 5];
int main() {
	int n; scanf("%d", &n);
	scanf("%s", str + 1);
	int mn = MAXN;
	for(int i=1;i<=n;i++)
		sum[i] = sum[i-1] + (str[i] == '(' ? 1 : -1), mn = min(mn, sum[i]);
	if( sum[n] != 0 || mn < -1 )
		puts("No");
	else puts("Yes");
}