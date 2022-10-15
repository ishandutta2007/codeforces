/***
24
Harbour Space University
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	string x;
	int ans = 0;
	while (cin >> x)
	{
		int v = 0;
		for (char i : x)
			if (isupper(i))
				v++;
		ans = max(ans, v);
	}
	cout << ans;
}