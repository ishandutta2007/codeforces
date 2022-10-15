/*input
5
6 6 6 6 6
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	int a[n];
	set<int>X;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		X.insert(a[i]);
	}
	cout << X.size() << "\n";
	for (int i = 0; i < n; i++)
	{
		bool ok = true;
		for (int j = i + 1; j < n; j++)
			if (a[j] == a[i])
				ok = false;
		if (ok)
			cout << a[i] << " ";
	}


}