#include <stdio.h>
#include <algorithm>
using namespace std;

constexpr int MOD = 10007;
int z[100005];

int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; i++) scanf("%d",&z[i]);
	sort(z,z+n);
	int ans=0;
	for (int i = 0; i < n; i++)
		ans = (ans + (long long)z[i] * z[n-1-i]) % MOD;
	printf("%d", ans);
}