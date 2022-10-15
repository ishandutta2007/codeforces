/*input
6
603
006
205
228
1053
0000000000000000000000000000000000000000000000
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
	int n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		int x = 0;
		for (char c : s)
			x += c - '0';
		if (s[0] != '0' || x % 3 != 0)
		{
			cout << "cyan\n";
			continue;
		}
		s.erase(s.begin());
		bool ok = s.empty();
		for (char c : s)
			if ((c - '0') % 2 == 0)
				ok = true;
		if (ok)
			cout << "red\n";
		else
			cout << "cyan\n";
	}
}