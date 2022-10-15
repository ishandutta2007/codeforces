/*input
10
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	vector<int>X;
	list<int>Y;
	for (int i = 1; i <= n; i++)
		Y.push_back(i);
	while (!Y.empty())
	{
		if (Y.size() == 3)
		{
			X.push_back(*Y.begin());
			Y.erase(Y.begin());
			X.push_back(*Y.begin());
			Y.erase(Y.begin());
			X.push_back(*Y.begin());
			Y.erase(Y.begin());
			continue;
		}
		{
			for (auto it = Y.begin(); it != Y.end();)
			{
				X.push_back(*it);
				auto itt = it;
				itt++;
				Y.erase(it);
				it = itt;
				if (it != Y.end())
					it++;
			}
		}
	}
	reverse(X.begin(), X.end());
	vector<int>ans;
	int G = 0;
	for (auto i : X)
	{
		G = __gcd(i, G);
		ans.push_back(G);
	}
	reverse(ans.begin(), ans.end());
	for (int i : ans)
		cout << i << " ";
}