/*input
2
M
XS
XS
M
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	int n;
	cin >> n;
	multiset<string> a[5];
	multiset<string> b[5];
	int kiek = n;
	while (kiek--)
	{
		string s;
		cin >> s;
		a[s.size()].insert(s);
	}
	kiek = n;
	while (kiek--)
	{
		string s;
		cin >> s;
		b[s.size()].insert(s);
	}
	int ans = 0;
	for (int t = 0; t < 5; t++)
	{
		for (string i : a[t])
		{
			if (b[t].count(i))
			{
				b[t].erase(b[t].find(i));
			}
			else
			{
				ans++;
			}
		}
	}
	cout << ans << "\n";


}