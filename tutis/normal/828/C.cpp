/***
3
ab 1 1
aba 1 3
ab 2 3 5
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	set<int>X;
	for (int x = 1; x <= 2000003; x++)
		X.insert(x);
	map<int, char>A;
	int maxx = 0;
	for (int i = 0; i < n; i++)
	{
		string t;
		cin >> t;
		int k;
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			int st;
			cin >> st;
			maxx = max(ll(maxx), ll(st + t.size()));
			while (X.upper_bound(st) != X.end() && *X.upper_bound(st) <= st + t.size())
			{
				int tt = *X.upper_bound(st);
				X.erase(X.upper_bound(st));
				A[tt] = t[tt - st - 1];
			}
		}
	}
	for (int i = 2; i <= maxx; i++)
	{
		if (A.count(i) == 0)
			cout << 'a';
		else
			cout << A[i];
	}
}