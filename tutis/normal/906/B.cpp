/***
3 3
***/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int A[n + 1][m + 1];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			A[i][j] = (i - 1) * m + j;
	if (n == 1 && m == 1)
	{
		cout << "YES\n1\n";
		return 0;
	}
	if (m == 4)
	{
		for (int i = 1; i <= n; i++)
		{
			if (i % 2 == 0)
			{
				deque<int>B[2];
				for (int j = 1; j <= m; j++)
				{
					B[j % 2].push_front(A[i][j]);
				}
				int id = 1;
				for (int a : B[1])
				{
					A[i][id] = a;
					id++;
				}
				for (int a : B[0])
				{
					A[i][id] = a;
					id++;
				}
			}
			if (i % 2 == 1)
			{
				deque<int>B[2];
				for (int j = 1; j <= m; j++)
				{
					B[j % 2].push_back(A[i][j]);
				}
				int id = 1;
				for (int a : B[0])
				{
					A[i][id] = a;
					id++;
				}
				for (int a : B[1])
				{
					A[i][id] = a;
					id++;
				}
			}
		}
	}
	else if (m > 4)
	{
		for (int i = 1; i <= n; i++)
		{
			deque<int>B[2];
			for (int j = 1; j <= m; j++)
			{
				B[(i + j) % 2].push_back(A[i][j]);
			}
			int id = 1;
			for (int a : B[0])
			{
				A[i][id] = a;
				id++;
			}
			for (int a : B[1])
			{
				A[i][id] = a;
				id++;
			}
		}
	}
	else if (n == 4)
	{
		for (int j = 1; j <= m; j++)
		{
			if (j % 2 == 0)
			{
				deque<int>B[2];
				for (int i = 1; i <= n; i++)
				{
					B[i % 2].push_front(A[i][j]);
				}
				int id = 1;
				for (int a : B[1])
				{
					A[id][j] = a;
					id++;
				}
				for (int a : B[0])
				{
					A[id][j] = a;
					id++;
				}
			}
			if (j % 2 == 1)
			{
				deque<int>B[2];
				for (int i = 1; i <= n; i++)
				{
					B[i % 2].push_back(A[i][j]);
				}
				int id = 1;
				for (int a : B[0])
				{
					A[id][j] = a;
					id++;
				}
				for (int a : B[1])
				{
					A[id][j] = a;
					id++;
				}
			}
		}
	}
	else if (n > 4)
	{
		for (int j = 1; j <= m; j++)
		{
			deque<int>B[2];
			for (int i = 1; i <= n; i++)
			{
				B[(i + j) % 2].push_front(A[i][j]);
			}
			int id = 1;
			for (int a : B[0])
			{
				A[id][j] = a;
				id++;
			}
			for (int a : B[1])
			{
				A[id][j] = a;
				id++;
			}
		}
	}
	else
	{
		if (n == 3 && m == 3)
		{
			cout << "YES\n";
			cout << "6 1 8 \n";
			cout << "7 5 3 \n";
			cout << "2 9 4 \n";
			return 0;
		}
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}
}