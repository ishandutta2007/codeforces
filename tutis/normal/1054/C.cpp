/*input
3
0 0 0
0 0 0
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int l[n];
	int r[n];
	for (int i = 0; i < n; i++)
		cin >> l[i];
	for (int i = 0; i < n; i++)
		cin >> r[i];
	int a[n];
	set<int>X;
	for (int i = 0; i < n; i++)
	{
		a[i] = -l[i] - r[i];
		X.insert(a[i]);
	}
	map<int, int>Y;
	for (int i : X)
		Y[i] = Y.size() + 1;
	for (int i = 0; i < n; i++)
		a[i] = Y[a[i]];
	bool ok = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
			if (a[i] < a[j])
				l[i]--;
		for (int j = i + 1; j < n; j++)
			if (a[i] < a[j])
				r[i]--;
		ok &= (l[i] == 0);
		ok &= (r[i] == 0);
		ok &= (a[i] <= n);
		ok &= (a[i] >= 1);
	}
	if (ok)
	{
		cout << "YES\n";
		for (int i : a)
			cout << i << " ";
		cout << "\n";
	}
	else
	{
		cout << "NO\n";
	}
}