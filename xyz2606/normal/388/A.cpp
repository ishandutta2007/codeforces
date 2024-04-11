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
int n, a[111], ans, cnt[111], sum;
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	memset(cnt, 0, sizeof(cnt));
	for(int i = 1; i <= n; i++) cnt[a[i]]++;
	ans = 0; sum = 0;
	for(int i = 0; i <= 100; i++)
	{
		sum += cnt[i];
		int x = sum / (i + 1);
		if(sum % (i + 1)) x++;
		if(x > ans) ans = x;
	}
	printf("%d\n", ans);
	fclose(stdin);
	return 0;
}