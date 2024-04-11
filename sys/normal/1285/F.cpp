#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 100005;
vector <int> Ve[Maxn], Div[Maxn];
int n, a[Maxn], mu[Maxn], prim[Maxn], sta[Maxn], top, cnt[Maxn], prim_cnt;
bool vis[Maxn];
long long ans;
void init(void)
{
	mu[1] = 1;
	for (int i = 2; i <= 100000; i++)
	{
		if (!vis[i]) prim[++prim_cnt] = i, mu[i] = -1;
		for (int j = 1; j <= prim_cnt && i * prim[j] <= 100000; j++)
		{
			vis[i * prim[j]] = true;
			if (i % prim[j] == 0)
				break;
			mu[i * prim[j]] = -mu[i];
		}
	}
}
void work(int x, int val)
{
	if (!Div[x].size())
	{
		int maxi = sqrt(x);
		for (int i = 1; i <= maxi; i++)
			if (x % i == 0)
			{
				Div[x].push_back(i);
				if (i * i != x) Div[x].push_back(x / i);
			}
	}
	for (vector <int> :: iterator it = Div[x].begin(); it != Div[x].end(); it++)
		cnt[*it] += val;
}
int cal(int x)
{
	int tmp = 0;
	if (!Div[x].size())
	{
		int maxi = sqrt(x);
		for (int i = 1; i <= maxi; i++)
			if (x % i == 0)
			{
				Div[x].push_back(i);
				if (i * i != x) Div[x].push_back(x / i);
			}
	}
	for (vector <int> :: iterator it = Div[x].begin(); it != Div[x].end(); it++)
		tmp += mu[*it] * cnt[*it];
	return tmp;
}
int main()
{
	scanf("%d", &n);
	init();
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		int maxi = sqrt(x);
		for (int j = 1; j <= maxi; j++)
		{
			if (x % j == 0)
			{
				Ve[j].push_back(x / j);
				if (j * j != x) Ve[x / j].push_back(j);
			}
		}
	}
	for (int i = 1; i <= 100000; i++)
	{
		while (top)
			work(sta[top--], -1);
		sort(Ve[i].begin(), Ve[i].end());
		for (vector <int> :: reverse_iterator it = Ve[i].rbegin(); it != Ve[i].rend(); it++)
		{
			int now = *it, las = 0;
			while (top && cal(now))
			{
				las = sta[top];
				work(sta[top], -1);
				top--;
			}
			ans = max(ans, las * (long long) now * i);
			sta[++top] = now;
			work(sta[top], 1);
		}
	}
	printf("%lld", ans);
	return 0;
}