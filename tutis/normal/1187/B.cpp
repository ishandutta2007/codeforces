/*input
9
arrayhead
5
arya
harry
ray
r
areahydra
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int k[26];
int kk[26][202020];
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < s.size(); i++)
	{
		k[s[i] - 'a']++;
		kk[s[i] - 'a'][k[s[i] - 'a']] = i + 1;
	}
	int m;
	cin >> m;
	while (m--)
	{
		string x;
		cin >> x;
		vector<int>kiek(26, 0);
		int ans = 0;
		for (char c : x)
		{
			kiek[c - 'a']++;
			ans = max(ans, kk[c - 'a'][kiek[c - 'a']]);
		}
		cout << ans << "\n";
	}
}