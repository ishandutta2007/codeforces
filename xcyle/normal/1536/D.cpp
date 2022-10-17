#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxn 200005
using namespace std;
int T, n, a[maxn], tmp[maxn], t[maxn], len;
void add(int x, int data)
{
	for (; x <= len; x += ((x) & (-x))) t[x] += data;
 } 
int que(int x)
 {
 	int res = 0;
	 for(; x; x -= (x & (-x))) res += t[x];
	 return res;	
 }
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		memset(t, 0, sizeof(t));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			tmp[i] = a[i];
		}
		sort(tmp + 1, tmp + n + 1);
		len = unique(tmp + 1, tmp + n + 1) - tmp - 1;
		for (int i = 1; i <= n; i++) a[i] = lower_bound(tmp + 1, tmp + len + 1, a[i]) - tmp;
		int flag = 1;
		for (int i = n - 1; i >= 1; i--)
		{
			if(que(a[i])) flag = 0;
			if(a[i] + 1 <= a[i + 1] - 1)
			{
				add(a[i] + 1, 1);
				add(a[i + 1], -1);
			}
			if(a[i + 1] + 1 <= a[i] - 1)
			{
				add(a[i + 1] + 1, 1);
				add(a[i], -1);
			}
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}