/***
3 3
1 2
1 3
3 2
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int A[100007];
struct comp
{
	bool operator()(pair<int, int>a, pair<int, int>b)
	{
		if (A[a.second] != A[b.second])
			return A[a.second] > A[b.second];
		if (a.first != b.first)
			return a.first > b.first;
		return a.second > b.second;
	}
};
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	set<int>out[n + 1];
	set<int>in[n + 1];
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		out[u].insert(v);
		in[v].insert(u);
	}
	int k = n;
	int label[n + 1];
	fill_n(label, n + 1, -1);
	priority_queue<int>lapai;
	for (int i = 1; i <= n; i++)
	{
		if (out[i].size() == 0)
		{
			lapai.push(i);
			label[i] = -2;
		}
	}
	while (!lapai.empty())
	{
		int a = lapai.top();
		lapai.pop();
		label[a] = k;
		k--;
		for (int b : in[a])
		{
			out[b].erase(a);
			if (out[b].size() == 0 && label[b] == -1)
			{
				lapai.push(b);
				label[b] = -2;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << label[i] << " ";
}