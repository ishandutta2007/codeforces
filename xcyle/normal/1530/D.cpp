#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define maxn 200005
using namespace std;
int T, n, a[maxn], t[maxn], b[maxn], c[maxn];
vector<int> s;
vector<int> g;
void solve()
{
	s.clear();
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) t[i] = 0;
	for (int i = 1; i <= n; i++) b[i] = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if(t[a[i]]) 
		{
			s.push_back(i);
			continue;
		}
		else
		{
			ans++;
			t[a[i]] = 1;
			b[i] = a[i];
			c[a[i]] = i;
		}
	}
//	for (int i = 1; i <= n; i++) printf("%d ", b[i]);
//	printf("\n");
	if(s.size() == 0) ans = ans;
	else if(s.size() == 1)
	{
		int x = s[0];
		if(t[x])
		{
			for (int i = 1; i <= n; i++)
			{
				if(!t[i]) b[x] = i;
			}
		}
		else
		{
			b[c[a[x]]] = x;
			b[x] = a[x];
		}
	}
	else
	{
		s.clear();
		g.clear();
		for (int i = 1; i <= n; i++)
		{
			if(!t[i] && !b[i]) 
			{
				s.push_back(i);
				g.push_back(i);
				t[i] = 1, b[i] = 1;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if(!b[i]) 
			{
				s.push_back(i);
			}
		}for (int i = 1; i <= n; i++)
		{
			if(!t[i]) 
			{
				g.push_back(i);
			}
		}
		b[s[s.size() - 1]] = g[0];
		for (int i = 0; i < s.size() - 1; i++)
		{
			b[s[i]] = g[i + 1];
		}
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++) printf("%d ", b[i]);
	printf("\n");
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}