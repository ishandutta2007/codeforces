/*input
90 100
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct comp
{
	bool operator()(pair<int, int>a, pair<int, int>b)const
	{
		if (a.first + a.second != b.first + b.second)
			return a.first + a.second > b.first + b.second;
		if (a.second != b.second)
			return a.second < b.second;
		return a.first > b.first;
	}
};
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	char A[100][100];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			A[i][j] = '0';
		}
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, comp>Q;
	Q.push({0, 0});
	while (!Q.empty())
	{
		int x = Q.top().first;
		int y = Q.top().second;
		Q.pop();/*
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << A[i][j];
			}
			cout << "\n";
		}
		cout << x << " " << y << endl;*/
		if (x >= n || y >= m)
			continue;
		for (char ch = 'A'; ch <= 'Z'; ch++)
		{
			int sz = min(n - x, m - y);
			while (sz > 0)
			{
				bool ok = true;
				if (x > 0)
				{
					for (int j = 0; j < sz; j++)
						if (A[x - 1][y + j] == ch)
							ok = false;
				}
				if (y > 0)
				{
					for (int j = 0; j < sz; j++)
						if (A[x + j][y - 1] == ch)
							ok = false;
				}
				if (x + sz < n)
					for (int j = 0; j < sz; j++)
						if (A[x + sz][y + j] == ch)
							ok = false;
				if (y + sz < m)
					for (int j = 0; j < sz; j++)
						if (A[x + j][y + sz] == ch)
							ok = false;
				if (y != 0 && A[x][y - 1] < ch && sz > 1)
				{
					bool gal = true;
					for (int t = 1; t < sz; t++)
						if (x != 0 && A[x - 1][t + y] == A[x][y - 1])
							gal = false;
					if (gal)
						ok = false;
				}
				if (x != 0 && A[x - 1][y] < ch && sz > 1)
				{
					if (y + 1 < m && A[x - 1][y + 1] != A[x - 1][y])
						ok = false;
				}
				for (int i = 0; i < sz; i++)
				{
					for (int j = 0; j < sz; j++)
					{
						if (A[x + i][y + j] != '0')
							ok = false;
					}
				}
				if (!ok)
					sz--;
				else
					break;
			}
			if (sz == 0)
				continue;
			for (int i = 0; i < sz; i++)
			{
				for (int j = 0; j < sz; j++)
				{
					A[x + i][y + j] = ch;
				}
			}
			Q.push({x, y + sz});
			Q.push({x + sz, y});
			break;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << A[i][j];
		}
		cout << "\n";
	}

}