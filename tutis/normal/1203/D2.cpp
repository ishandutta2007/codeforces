/*input
bbaba
bb

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	string s, t;
	cin >> s >> t;
	if (s.size() == t.size())
	{
		cout << "0\n";
		return 0;
	}
	int ans = 0;
	int kur[t.size() + 1];
	int i = 0;
	kur[0] = -1;
	for (int j = 0; j < (int)t.size(); j++)
	{
		while (s[i] != t[j])
			i++;
		kur[j + 1] = i;
		i++;
	}
	ans = max(ans, (int)s.size() - kur[t.size()] - 1);
	i = s.size() - 1;
	for (int j = (int)t.size() - 1; j >= 0; j--)
	{
		while (s[i] != t[j])
			i--;
		ans = max(ans, i - kur[j] - 1);
		i--;
	}
	cout << ans << "\n";
}