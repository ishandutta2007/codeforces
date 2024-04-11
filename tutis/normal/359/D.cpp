/*input
5
1 3 5 7 9

*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int l[n];
	int r[n];
	iota(l, l + n, 0);
	iota(r, r + n, 0);
	deque<int>k;
	for (int i = 0; i < n; i++)
	{
		int g = a[i];
		deque<int>geras = {i};
		for (int j = (int)k.size() - 1; j >= 0; j--)
		{
			if (__gcd(a[k[j]], g) != g)
			{
				geras.push_front(k[j]);
				g = __gcd(a[k[j]], g);
			}
		}
		k = geras;
		if (k.size() == 1)
			l[i] = 0;
		else
			l[i] = k[k.size() - 2] + 1;
	}
	k.clear();
	for (int i = n - 1; i >= 0; i--)
	{
		int g = a[i];
		deque<int>geras = {i};
		for (int j = (int)k.size() - 1; j >= 0; j--)
		{
			if (__gcd(a[k[j]], g) != g)
			{
				geras.push_front(k[j]);
				g = __gcd(a[k[j]], g);
			}
		}
		k = geras;
		if (k.size() == 1)
			r[i] = n - 1;
		else
			r[i] = k[k.size() - 2] - 1;
	}
	int maxi = 0;
	vector<int>ans;
	for (int i = 0; i < n; i++)
	{
		if (r[i] - l[i] > maxi)
		{
			maxi = r[i] - l[i];
			ans = {l[i] + 1};
		}
		else if (r[i] - l[i] == maxi)
		{
			ans.push_back(l[i] + 1);
		}
	}
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	cout << ans.size() << " " << maxi << "\n";
	for (int i : ans)
		cout << i << " ";
}