#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
string s;
int n, len[Maxn];
pair <int, int> fir[Maxn];
pair <string, string> f[Maxn];
void work(pair <string, string> & t)
{
	if (t.first.size() > 10) t.first = t.first.substr(0, 10);
	if (t.second.size() < 2) t.second = t.first.substr(max(0, (int) t.first.size() - 2), 2);
}
int main()
{
	cin >> s;
	n = s.size();
	for (int i = n - 1; i >= 0; i--)
	{
		if (i == n - 1) f[i] = make_pair(s[i], s[i]), len[i] = 1, fir[i].first = s[i] - 'a';
		else if (i == n - 2)
		{
			if (s[n - 2] != s[n - 1]) f[i] = make_pair(s[n - 2], s[n - 2]), f[i].first += s[n - 1], f[i].second += s[n - 1], fir[i].first = s[n - 2] - 'a', fir[i].second = s[n - 1] - 'a';
			len[i] = f[i].first.size();
		}
		else
		{
			if (s[i] != s[i + 1])
			{
				f[i].first = s[i] + f[i + 1].first;
				f[i].second = f[i + 1].second;
				len[i] = len[i + 1] + 1;
				fir[i] = fir[i + 1];
				if (s[i] - 'a' != fir[i].first) fir[i].second = fir[i].first, fir[i].first = s[i] - 'a';
			}
			else
			{
				if (s[i] - 'a' < fir[i + 2].first)
				{
					f[i].first = s[i] + (s[i] + f[i + 2].first), f[i].second = f[i + 2].second;
					fir[i].first = s[i] - 'a', fir[i].second = fir[i + 2].first;
					len[i] = len[i + 2] + 2;
				}
				else if (s[i] - 'a' > fir[i + 2].first)
					f[i] = f[i + 2], fir[i] = fir[i + 2], len[i] = len[i + 2];
				else
				{
					if (fir[i + 2].first < fir[i + 2].second)
						f[i].first = s[i] + (s[i] + f[i + 2].first), f[i].second = f[i + 2].second, len[i] = len[i + 2] + 2;
					else
						f[i] = f[i + 2], len[i] = len[i + 2];
					fir[i] = fir[i + 2];
				}
			}
			work(f[i]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << len[i] << ' ';
		if (len[i] <= 10) cout << f[i].first << endl;
		else cout << f[i].first.substr(0, 5) << "..." << f[i].second << endl;
	}
	return 0;
}