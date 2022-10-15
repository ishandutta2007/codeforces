/**
4 10
abcd
ebceabazcd
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	int mini = n + 1;
	int id = 0;
	for (int i = 0; i <= m - n; i++)
	{
		int k = 0;
		for (int l = 0; l < n; l++)
			if (s[l] != t[l + i])
				k++;
		if (k <= mini)
		{
			mini = k;
			id = i;
		}
	}
	cout << mini << '\n';
	for (int l = 0; l < n; l++)
		if (s[l] != t[l + id])
			cout << l + 1 << " ";
}