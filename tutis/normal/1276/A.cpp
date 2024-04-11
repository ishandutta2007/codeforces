/*input
10
onetwonetwooneooonetwooo
two
one
twooooo
ttttwo
ttwwoo
ooone
onnne
oneeeee
oneeeeeeetwooooo

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		set<int>ans;
		for (int i = 2; i + 2 < (int)s.size(); i++)
		{
			if (s[i - 2] == 't' && s[i - 1] == 'w' && s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e')
				ans.insert(i);
		}
		for (int i = 2; i < (int)s.size(); i++)
		{
			if (ans.count(i) == 0)
				if (s[i - 2] == 't' && s[i - 1] == 'w' && s[i] == 'o')
					ans.insert(i - 1);
			if (ans.count(i - 2) == 0)
				if (s[i - 2] == 'o' && s[i - 1] == 'n' && s[i] == 'e')
					ans.insert(i - 1);
		}
		cout << ans.size() << "\n";
		for (int i : ans)
			cout << i + 1 << " ";
		cout << "\n";
	}
}