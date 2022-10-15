/*input
4
8 2
()(())()
10 3
))()()()((
2 1
()
2 1
)(

*/
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
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		vector<pair<int, int>>ans;
		auto suk = [&](int l, int r)
		{
			int x = l;
			int y = r;
			while (x < y)
			{
				swap(s[x], s[y]);
				x++;
				y--;
			}
			ans.push_back({l + 1, r + 1});
		};
		string s_ = "";
		for (int i = 1; i < k; i++)
			s_ += "()";
		int liko = n - s_.size();
		liko /= 2;
		for (int i = 0; i < liko; i++)
			s_ += "(";
		for (int i = 0; i < liko; i++)
			s_ += ")";
		for (int l = 0; l < n; l++)
		{
			if (s_[l] != s[l])
			{
				for (int r = l + 1; r < n; r++)
				{
					if (s[r] == s_[l])
					{
						suk(l, r);
						break;
					}
				}
			}
		}
		cout << ans.size() << "\n";
		for (auto i : ans)
			cout << i.first << " " << i.second << "\n";
	}
}