/**
5 2
1 2
2 3
3 4
2 5
**/
#define MOD (1000000007ll)
#define mod(x) (x%MOD)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, x;
	cin >> n >> x;
	int A[n + 1];
	int B[n + 1];
	vector<int>adj[n + 1];
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	fill_n(B, n + 1, n + 7);
	fill_n(A, n + 1, n + 7);
	B[x] = 0;
	A[1] = 0;
	queue<int>BFS;
	BFS.push(x);
	while (!BFS.empty())
	{
		int a = BFS.front();
		BFS.pop();
		for (int b : adj[a])
		{
			if (B[b] > B[a] + 1)
			{
				B[b] = B[a] + 1;
				BFS.push(b);
			}
		}
	}
	BFS.push(1);
	while (!BFS.empty())
	{
		int a = BFS.front();
		BFS.pop();
		for (int b : adj[a])
		{
			if (A[b] > A[a] + 1)
			{
				A[b] = A[a] + 1;
				BFS.push(b);
			}
		}
	}
	int ats = 0;
	for (int i = 1; i <= n; i++)
	{
		if (B[i] < A[i])
		{
			ats = max(ats, A[i] * 2);
		}
	}
	int ats1 = 2 * n + 7;
	for (int i = 1; i <= n; i++)
	{
		if (B[i] == A[i])
		{
			ats1 = max(ats, A[i] * 2);
		}
	}
	ats = min(ats, ats1);
	cout << ats << endl;
}