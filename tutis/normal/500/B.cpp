/*input
5
4 2 1 5 3
00100
00011
10010
01101
01010

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int pa[400];
int root(int x)
{
	if (x == pa[x])
		return x;
	return pa[x] = root(pa[x]);
}
void merge(int a, int b)
{
	a = root(a);
	b = root(b);
	pa[a] = b;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int p[n + 1];
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
		pa[i] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			char c;
			cin >> c;
			if (c == '1')
				merge(i, j);
		}
	}
	vector<int>c[n + 1];
	for (int i = 1; i <= n; i++)
	{
		c[root(i)].push_back(i);
	}
	for (int i = 1; i <= n; i++)
	{
		vector<int>id = c[i];
		vector<int>x;
		for (int i : id)
			x.push_back(p[i]);
		sort(x.begin(), x.end());
		for (int i = 0; i < (int)x.size(); i++)
			p[id[i]] = x[i];
	}
	for (int i = 1; i <= n; i++)
		cout << p[i] << " ";
}