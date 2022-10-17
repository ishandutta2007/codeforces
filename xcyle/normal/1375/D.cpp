#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)

using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
inline ll readll()
{
	ll x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int T, n, a[1005], m;
int cnt, ans[10005];
int num[1005];
priority_queue<int> q;
int pos[1005];
void solve()
{
	scanf("%d", &n);
	cnt = 0;
	for (int i = 0; i <= n; i++) 
	{
		num[i] = 0;
	}
	for (int i = 1; i <= n; i++) 
	{
		scanf("%d", &a[i]);
		num[a[i]]++;
	}
	while(!q.empty()) q.pop();
	for (int i = 0; i <= n; i++)
	{
		if(!num[i]) q.push(-i);
	}
	while(!q.empty())
	{
		int x = -q.top();
//		printf("%d\n", x);
		q.pop();
		if(x >= n) break;
		ans[++cnt] = x + 1;
		num[a[x + 1]]--;
		if(!num[a[x + 1]]) q.push(-a[x + 1]);
		a[x + 1] = x;
	}
	for (int i = 1; i <= n; i++)
	{
		pos[a[i]] = i;
	}
//	for (int i = 1; i <= n; i++) printf("%d ", a[i]);
//	printf("\n");
	for (int i = 1; i <= n; i++)
	{
		if(a[i] != i - 1)
		{
			ans[++cnt] = i;
			int now = a[i] + 1;
			a[i] = n;
//			printf("%d ", i);
			while(now != i)
			{
//				printf("%d ", now);
				ans[++cnt] = now;
				int tmp = now;
				now = a[now] + 1;
				a[tmp] = tmp - 1;
			}
//			printf("\n");
//			printf("!!!!!\n");
//			for (int i = 1; i <= n; i++) printf("%d ", a[i]);
//			printf("\n");
			ans[++cnt] = i;
			a[i] = i - 1;
		}
	}
	printf("%d\n", cnt);
	for (int i = 1; i <= cnt; i++) printf("%d ", ans[i]);
	printf("\n");
} 
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}