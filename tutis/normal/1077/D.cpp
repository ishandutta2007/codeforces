/*input
7 3
1 2 3 2 4 3 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int A[200009];
int main()
{
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		A[a]++;
	}
	int lo = 1;
	int hi = n;
	while (lo < hi)
	{
		int m = (lo + hi + 1) / 2;
		vector<int>gal;
		for (int i = 1; i <= 200000; i++)
		{
			int c = A[i] / m;
			while (c > 0)
			{
				gal.push_back(i);
				c--;
			}
		}
		if (gal.size() >= k)
			lo = m;
		else
			hi = m - 1;
	}
	int m = (lo + hi) / 2;
	vector<int>gal;
	for (int i = 1; i <= 200000; i++)
	{
		int c = A[i] / m;
		while (c > 0)
		{
			gal.push_back(i);
			c--;
		}
	}
	while (gal.size() > k)
		gal.pop_back();
	while (gal.size() < k)
		gal.push_back(1);
	for (int i : gal)
		cout << i << " ";


}