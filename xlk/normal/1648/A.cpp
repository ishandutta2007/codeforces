#include<bits/stdc++.h>
using namespace std;
vector<int> a[100020];
vector<int> b[100020];
long long z;
void zhi(vector<int> &a)
{
	sort(a.begin(), a.end());
	int n = a.size();
	for (int i = 0; i < n; i++)
	{
		z += a[i] * (2 * i - n + 1LL);
	}
}
int n, m, c;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> c;
			a[c].push_back(i);
			b[c].push_back(j);
		}
	}
	for (int i = 1; i < 100010; i++)
	{
		zhi(a[i]);
		zhi(b[i]);
	}
	cout << z << endl;
	return 0;
}