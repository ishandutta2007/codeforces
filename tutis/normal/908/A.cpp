/***
0ay1
***/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	string s;
	cin >> s;
	int ans = 0;
	set<char>x = {'1', '3', '5', '7', '9', 'a', 'e', 'i', 'o', 'u'};
	for (char i : s)
	{
		ans += x.count(i);
	}
	cout << ans;
}