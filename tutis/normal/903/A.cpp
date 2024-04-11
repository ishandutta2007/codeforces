/***
2
6
5
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	bool ans[101];
	ans[0] = true;
	ans[1] = false;
	ans[2] = false;
	for (int i = 3; i <= 100; i++)
	{
		ans[i] = false;
		if (i >= 3 && ans[i - 3])
			ans[i] = true;
		if (i >= 7 && ans[i - 7])
			ans[i] = true;
	}
	while (n--)
	{
		int x;
		cin >> x;
		cout << (ans[x] ? "YES\n" : "NO\n");
	}
}