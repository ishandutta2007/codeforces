/*input
4 3
4 3 2 2 1
3 1 1 3
3 2 3 3
2 3 1

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int>adj[202020];
int n, m;
int timer = 2;
int v[202020];
int mn[202020];
stack<int>S;
bool stake[202020];
vector<vector<int>>comp;
void dfs(int i)
{
	if (v[i] > 0)
		return;
	v[i] = timer++;
	mn[i] = v[i];
	stake[i] = true;
	S.push(i);
	for (int j : adj[i])
	{
		if (stake[j])
		{
			mn[i] = min(mn[i], v[j]);
		}
		else if (v[j] == 0)
		{
			dfs(j);
			mn[i] = min(mn[i], mn[j]);
		}
	}
	if (mn[i] == v[i])
	{
		comp.push_back({});
		while (true)
		{
			int j = S.top();
			S.pop();
			stake[j] = false;
			comp.back().push_back(j);
			if (j == i)
				break;
		}
	}
}
vector<int>cap;
int kitas(int x)
{
	if (x <= m)
		return x + m;
	else
		return x - m;
}
bool nustatyta[202020];
bool val[202020];
bool sat2()
{
	for (int i = 1; i <= 2 * m; i++)
	{
		dfs(i);
	}
	for (vector<int>i : comp)
	{
		int a[2] = {0, 0};
		for (int j : i)
		{
			if (nustatyta[j])
			{
				a[val[j]] = 1;
			}
		}
		if (a[0] + a[1] == 2)
			return false;
		int x;
		if (a[0] == 1)
			x = 0;
		else
			x = 1;
		for (int j : i)
		{
			if (nustatyta[j] && val[j] != x)
				return false;
			nustatyta[j] = true;
			val[j] = x;
			if (nustatyta[kitas(j)] && val[kitas(j)] == x)
				return false;
			nustatyta[kitas(j)] = true;
			val[kitas(j)] = 1 - x;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		if (val[i + m] == 1)
			cap.push_back(i);
	}
	return true;
}
int main()
{
	cin >> n >> m;
	vector<vector<int>>a(n);
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		while (x--)
		{
			int c;
			cin >> c;
			a[i].push_back(c);
		}
	}
	for (int i = 1; i < n; i++)
	{
		vector<int> &A = a[i - 1];
		vector<int> &B = a[i];
		for (int j = 0;; j++)
		{
			if (j == (int)A.size() || j == (int)B.size())
			{
				if (A.size() > B.size())
				{
					cout << "No\n";
					return 0;
				}
				break;
			}
			if (A[j] == B[j])
				continue;
			if (A[j] < B[j])
			{
				adj[A[j]].push_back(B[j]);
				adj[m + B[j]].push_back(m + A[j]);
			}
			else
			{
				adj[A[j]].push_back(m + A[j]);
				adj[m + B[j]].push_back(B[j]);
			}
			break;
		}
	}
	if (sat2())
	{
		cout << "Yes\n";
		cout << cap.size() << "\n";
		for (int i : cap)
			cout << i << " ";
		cout << "\n";
	}
	else
	{
		cout << "No\n";
	}
}