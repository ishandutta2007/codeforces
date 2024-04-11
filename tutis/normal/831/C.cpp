/***
4 1
-5 5 0 20
10
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
	int k, n;
	cin >> k >> n;
	int a[k];
	for (int i = 0; i < k; i++)
	{
		cin >> a[i];
	}
	set<int>B;
	int b[n];
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
		B.insert(b[i]);
	}
	int st = 0;
	vector<int>kel;
	kel.push_back(0);
	for (int i = 0; i < k; i++)
		kel.push_back(kel.back() + a[i]);
	set<int>ans;
	for (int j = 0; j < kel.size(); j++)
	{
		st = kel[j] - b[0];
		set<int>BB;
		for (int i = 1; i < kel.size(); i++)
		{
			BB.insert(kel[i] - st);
		}
		bool ok = true;
		for (int i : B)
			if (BB.count(i) == 0)
				ok = false;
		if (ok)
			ans.insert(st);
	}
	cout << ans.size();
}