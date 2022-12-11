#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int t[N][N];

pair<int, vector<int>> solve(int *op, int *our, int m)
{
	vector<pair<int, int>> v;
	for(int i = 0; i < m; i++)
		v.emplace_back(op[i] - our[i], i);
	sort(v.begin(), v.end());
	int b = 0;
	vector<int> ans;
	for(auto p: v)
		if(b + p.first <= 0)
			b += p.first;
		else ans.push_back(p.second + 1);
	return { ans.size(), ans };
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &t[j][i]);
	pair<int, vector<int>> ans;
	ans.first = n + 1;
	for(int i = 0; i < n - 1; i++)
		ans = min(ans, solve(t[n-1], t[i], m));
	printf("%d\n", ans.first);
	for(auto x: ans.second)
		printf("%d ", x);
	puts("");
}