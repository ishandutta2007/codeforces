#include<bits/stdc++.h>
const int N = 100010;
using namespace std;

int n, k, a[N], b[N];
vector <int> sit;
vector <pair <int, char>> ans;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &k);
	for (int i = 1; i <= k; i++)
		scanf("%d", &b[i]);
	int j = 1;
	sit = {1};
	for (int i = 1; i <= k; i++)
	{
		int now = 0;
		while (now < b[i] && j <= n)
			now += a[j ++];
		if (now != b[i])
			return printf("NO\n"), 0;
		sit.push_back(j);
	}
	if (j <= n)
		return printf("NO\n"), 0;
	for (int i = 0; i < k; i++)
	{
		int left = sit[i], right = sit[i + 1], maxi = 0;
		if (left == right - 1)
			continue;
		for (int j = left; j < right; j++)
			maxi = max(maxi, a[j]);
		int s = 0;
		if (a[left] > a[left + 1] && a[left] == maxi)
			s = left;
		if (a[right - 1] > a[right - 2] && a[right - 1] == maxi)
			s = right - 1;
		for (int j = left + 1; j < right - 1; j++)
			if (a[j] == maxi && (a[j] > a[j - 1] || a[j] > a[j + 1]))
				s = j;
		if (!s)
			return printf("NO\n"), 0;
		if (s == left)
			for (int j = s; j < right - 1; j++)
				ans.push_back({s - left + i + 1, 'R'});
		else if (s == right - 1)
			for (int j = s; j > left; j--)
				ans.push_back({j - left + i + 1, 'L'});
		else if (a[s] > a[s + 1])
		{
			for (int j = s; j < right - 1; j++)
				ans.push_back({s - left + i + 1, 'R'});
			for (int j = s; j > left; j--)
				ans.push_back({j - left + i + 1, 'L'});
		}
		else
		{
			for (int j = s; j > left; j--)
				ans.push_back({j - left + i + 1, 'L'});
			for (int j = s; j < right - 1; j++)
				ans.push_back({i + 1, 'R'});
		}
	}
	printf("YES\n");
	for (int i = 0; i < ans.size(); i++)
		printf("%d %c\n", ans[i].first, ans[i].second);
	return 0;
}