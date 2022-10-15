#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
using namespace std;
int n, k, ans, a[111];
int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	ans = 0;
	for(int i = 1; i < n; i++) ans = max(ans, a[i] - a[i + 1] - k);
	printf("%d\n", ans);
	fclose(stdin);
	return 0;
}