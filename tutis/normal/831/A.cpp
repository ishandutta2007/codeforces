/***
4
1 2 1 2
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
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int b[n];
	for (int i = 1; i < n; i++)
		if (a[i] > a[i - 1])
			b[i] = 0;
		else if (a[i] == a[i - 1])
			b[i] = 1;
		else
			b[i] = 2;
	for (int i = 2; i < n; i++)
		if (b[i] < b[i - 1])
		{
			cout << "NO";
			return 0;
		}
	cout << "YES";
}