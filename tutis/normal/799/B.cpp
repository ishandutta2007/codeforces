#include <bits/stdc++.h>
using namespace std;
struct f
{
	bool operator()(pair<int, int>a, pair<int, int>b)const
	{
		return a.first < b.first;
	}
};
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int N;
	cin >> N;
	int p[N];
	int a[N];
	int b[N];
	for (int i = 0; i < N; i++)
		cin >> p[i];
	for (int i = 0; i < N; i++)
		cin >> a[i];
	for (int i = 0; i < N; i++)
		cin >> b[i];
	set<pair<int, int>, f>A[4];
	for (int i = 0; i < N; i++)
	{
		A[a[i]].insert(make_pair(p[i], b[i]));
		A[b[i]].insert(make_pair(p[i], a[i]));
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int c;
		cin >> c;
		if (A[c].size() == 0)
		{
			cout << "-1 ";
			continue;
		}
		pair<int, int>dab = *A[c].begin();
		A[c].erase(make_pair(dab.first, dab.second));
		A[dab.second].erase(make_pair(dab.first, c));
		cout << dab.first << " ";
	}
}