/*input
5
0 0 1 1

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int>c[101010];
int h[101010];
int p[101010];
int p_[101010];
void dfs1(int i)
{
	h[i] = 1;
	for (int j : c[i])
	{
		dfs1(j);
	}
	sort(c[i].begin(), c[i].end(), [&](int a, int b) {return h[a] < h[b];});
	if (!c[i].empty())
		h[i] = h[c[i].back()] + 1;
}
vector<int>A;
void dfs2(int i)
{
	A.push_back(i);
	for (int j : c[i])
	{
		dfs2(j);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	p[0] = 0;
	for (int i = 1; i < n; i++)
	{
		cin >> p[i];
		c[p[i]].push_back(i);
	}
	dfs1(0);
	dfs2(0);
	p_[0] = 0;
	for (int i = 1; i < n; i++)
		p_[A[i]] = A[i - 1];
	vector<int>ans;
	for (int i : A)
	{
		while (p_[i] != p[i])
		{
			p_[i] = p_[p_[i]];
			ans.push_back(i);
		}
	}
	for (int i : A)
		cout << i << " ";
	cout << "\n";
	cout << ans.size() << "\n";
	for (int i : ans)
		cout << i << " ";
}