#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
int n, m, p, k, a[1001][1001];
long long s[1000001], t[1000001], sum, ans;
priority_queue<long long> hp;
int main()
{
	scanf("%d%d%d%d", &n, &m, &k, &p);
	for(int i = 1; i <= n; i++)
	{
		sum = 0;
		for(int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]), sum += a[i][j];
		hp.push(sum);
	}
	s[0] = 0;
	for(int i = 1; i <= k; i++)
	{
		s[i] = s[i - 1] + hp.top();
		//printf("%I64d\n", s[i] - s[i - 1]);
		hp.pop();
		hp.push(s[i] - s[i - 1] - p * m);
	}
	while(!hp.empty()) hp.pop();
	for(int  i = 1; i <= m; i++)
	{
		sum = 0;
		for(int j = 1; j <= n; j++)
			sum += a[j][i];
		hp.push(sum);
	}
	t[0] = 0;
	for(int i = 1; i <= k; i++)
	{
		t[i] = t[i - 1] + hp.top();
		hp.pop();
		hp.push(t[i] - t[i - 1] - p * n);
	}
	ans = 0x8000000000000000;
	for(int i = 0; i <= k; i++)
		ans = max(ans, s[i] + t[k - i] - (long long)i * (k - i) * p);
	printf("%I64d\n", ans);
	fclose(stdin);
	return 0;
}