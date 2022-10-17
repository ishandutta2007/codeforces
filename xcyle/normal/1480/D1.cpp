#include <iostream>
#include <cstdio>
#define maxn 100005
using namespace std;
int n, a[maxn];
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int last = 0, ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if(a[i + 1] == a[i])
		{
			ans += 2;
			last = a[i];
			while(a[i] == a[i + 1]) i++;
		}
		else
		{
			int j, flag = 0;
			for (j = i + 1; j <= n; j++)
			{
				if(a[j] == a[j + 1]) break;
				if(a[j] != a[i - 1] && a[j - 1] != a[i - 1]) flag = 1;
			}
			j--;
			ans += (j - i + 1);
			if(!flag && a[i - 1] == a[j + 1] && i != 1 && i != n) ans--;
//			printf("%d %d\n", flag, j + 1);
			i = j;
		}
	}
	printf("%d", ans);
	return 0;
}