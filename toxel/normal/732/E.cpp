#include<bits/stdc++.h>
using namespace std;
const int N = 200010;
int n, m, p[N], a[N], b[N];
pair <int, int> s[N];
map <int, vector <int> > Hash; 

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &p[i]);
	for (int i = 0; i < m; i++)
	{
		int x;
		scanf("%d", &x);
		s[i] = {x, i + 1};
	}
	sort(s, s + m);
	for (int i = 0; i < n; i++)
		if (Hash.count(p[i]))
			Hash[p[i]].push_back(i);
		else
		{
			vector <int> v;
			v.push_back(i);
			Hash[p[i]] = v;
		}
	int ans = 0, ans1 = 0;
	for (int i = 0; i < m; i++)
	{
		int cnt = 0;
		bool flag = false;
		while (s[i].first > 1)
		{
			if (Hash.count(s[i].first) && !Hash[s[i].first].empty())
			{
				a[s[i].second] = cnt;
				b[Hash[s[i].first].back()] = s[i].second;
				Hash[s[i].first].pop_back();
				ans++;
				ans1 += cnt;
				flag = true;
				break;
			}
			s[i].first = (s[i].first + 1) / 2;
			cnt++;
		}
		if (flag)
			continue;
		if (Hash.count(s[i].first) && !Hash[s[i].first].empty())
		{
			a[s[i].second] = cnt;
			b[Hash[s[i].first].back()] = s[i].second;
			Hash[s[i].first].pop_back();
			ans++;
			ans1 += cnt;
		}
	}
	printf("%d %d\n", ans, ans1);
	for (int i = 1; i <= m; i++)
		printf("%d ", a[i]);
	printf("\n");
	for (int i = 0; i < n; i++)
		printf("%d ", b[i]);
	return 0;
}