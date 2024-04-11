/*input
100210
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string s;
	cin >> s;
	deque<int>X[257];
	for (int i = 0; i < s.size(); i++)
	{
		X[s[i]].push_back(i);
	}
	while (X['0'].size() + X['1'].size() + X['2'].size() > 0)
	{
		bool ok = true;
		for (char t : {'0', '1', '2'})
		{
			if (t == '0')
			{
				if (!X[t].empty() && (X['2'].empty() || X['2'].front() > X[t].front()))
				{
					cout << t;
					X[t].pop_front();
					break;
				}
			}
			if (t == '1')
			{
				if (!X[t].empty())
				{
					cout << t;
					X[t].pop_front();
					break;
				}
			}
			if (t == '2')
			{
				if (!X[t].empty() && (X['0'].empty() || X['0'].front() > X[t].front()))
				{
					cout << t;
					X[t].pop_front();
					break;
				}
			}
		}
	}
}