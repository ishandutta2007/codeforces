#include<bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--)
	{
		string s1, s2;
		cin >> s1 >> s2;
		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());
		int ans1, ans2;
		for (int i = 0; i<s2.length(); i++)
			if (s2[i] == '1')
			{
			ans2 = i;
			break;
			}
		for (int i = 0; i<s1.length(); i++)
			if (s1[i] == '1'&&i >= ans2)
			{
			ans1 = i;
			break;
			}

		cout << ans1 - ans2 << endl;
	}
}