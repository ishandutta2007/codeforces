#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define maxn 200005
using namespace std;
int n, sum[maxn];
char s[maxn];
vector<int> t; 
long long val[maxn]; 
int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	t.push_back(0);
	for (int i = 1; i <= n; i++) 
	{
		sum[i] = sum[i - 1] + (s[i] == '1');
		if(s[i] == '1') t.push_back(i);
	}
	long long ans = 0;
	int top = min(n, 100);
	val[n + 1] = n + 1;
	for (int i = 1; i <= top; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			val[j] = j - i * sum[j];
		}
		sort(val, val + n + 1);
		for (int j = 0; j <= n; j++)
		{
			for (int k = j; k <= n + 1; k++)
			{
				if(val[j] != val[k])
				{
					ans += (long long)(k - j) * (k - j - 1) / 2;
					j = k - 1;
					break;
				}
			}
		}
	}
	for (int i = 1; i <= 2000; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if(sum[j] < i) continue;
			int r = j - t[sum[j] - i], l = max(top * i + 1, j - t[sum[j] - i + 1] + 1);
			l = (l + i - 1) / i * i, r = r / i * i;
			if(l > r) continue;
			ans += (r - l) / i + 1;
		}
	}
	printf("%lld", ans);
	return 0;
}