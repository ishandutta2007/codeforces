/*input
b
ab
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string s, t;
	cin >> s >> t;
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	int kiek = 0;
	for (int i = 0; i < s.size() && i < t.size(); i++)
	{
		if (s[i] != t[i])
			break;
		else
			kiek++;
	}
	cout << s.size() + t.size() - 2 * kiek << "\n";
}