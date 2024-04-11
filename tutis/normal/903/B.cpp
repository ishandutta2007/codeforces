/***
11 6 100
12 5
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int h1, a1, c1;
	cin >> h1 >> a1 >> c1;
	int h2, a2;
	cin >> h2 >> a2;
	vector<string>ans;
	while (h2 > 0)
	{
		if (h2 - a1 <= 0)
		{
			ans.push_back("STRIKE\n");
			break;
		}
		if (h1 <= a2)
		{
			h1 += c1;
			ans.push_back("HEAL\n");
		}
		else
		{
			h2 -= a1;
			ans.push_back("STRIKE\n");
		}
		h1 -= a2;
	}
	cout << ans.size() << "\n";
	for (string i : ans)
		cout << i;
}