#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	string a;
	cin >> a;
	a = "_" + a + "____";
	int i;
	for (i = 1; i < n + 1; i++)
	{
		if (!(a[i] == 'a' or a[i] == 'e' or a[i] == 'i' or a[i] == 'o' or a[i] == 'u' or a[i] == 'y'))
		{
			cout << a[i];
		}
		else
		{
			if (a[i] == 'a' or a[i] == 'i' or a[i] == 'u' or a[i] == 'y' or a[i] == 'o' or a[i] == 'e')
			{
				if (a[i - 1] != a[i])
					cout << a[i];
			}
			if (a[i] == 'e' or a[i] == 'o')
			{
				if (a[i - 1] != a[i] and a[i + 1] == a[i] and a[i + 2] != a[i])
					cout << a[i];
			}
		}
	}
	return 0;
}