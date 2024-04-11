/***
bbaabaabbb
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	string s;
	cin >> s;
	int n = s.size();
	vector<string>X[26];
	for (int k = 0; k < n; k++)
	{
		string t = s;
		for (int i = 0; i < n; i++)
			t[i] = s[(i + k) % n];
		X[t[0] - 'a'].push_back(t);
	}
	ld ans = 0;
	for (int i = 0; i < 26; i++)
	{
		if (X[i].empty())
			continue;
		ld p = ld(X[i].size()) / ld(n);
		int mx = 0;
		for (int c = 1; c < n; c++)
		{
			int kiek = 0;
			int K[26];
			fill_n(K, 26, 0);
			for (string &a : X[i])
			{
				K[a[c] - 'a']++;
			}
			for (int c = 0; c < 26; c++)
				if (K[c] == 1)
					kiek++;
			mx = max(kiek, mx);
		}
		ans += p * (ld(mx) / X[i].size());
	}
	cout << fixed << setprecision(30) << ans << "\n";
}