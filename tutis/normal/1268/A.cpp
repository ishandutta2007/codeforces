/*input
12 2
871723889999

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	bool ok = true;
	for (int j = 0; j < n; j++)
	{
		if (s[j] < s[j % k])
			break;
		ok &= (s[j] <= s[j % k]);
	}
	if (ok == false)
	{
		int i = k - 1;
		while (i >= 0 && s[i] == '9')
			i--;
		if (i >= 0)
		{
			s[i]++;
			for (int j = i + 1; j < k; j++)
				s[j] = '0';
		}
		else
		{
			assert(false);
		}
	}
	for (int j = 0; j < n; j++)
		s[j] = s[j % k];
	cout << n << "\n" << s << "\n";
	return 0;
}