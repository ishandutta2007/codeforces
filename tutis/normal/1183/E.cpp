/*input
5 6
aaaaa

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, k;
	string s;
	cin >> n >> k >> s;
	queue<string>Q;
	Q.push(s);
	set<string>buvo;
	ll ans = 0;
	while (!Q.empty())
	{
		string a = Q.front();
		Q.pop();
		if (buvo.count(a))
			continue;
		buvo.insert(a);
		k--;
		ans += n - a.size();
		if (k == 0)
		{
			cout << ans << "\n";
			return 0;
		}
		for (int c = 0; c < (int)a.size(); c++)
		{
			string b = a;
			b.erase(b.begin() + c);
			Q.push(b);
		}
	}
	cout << "-1\n";
}