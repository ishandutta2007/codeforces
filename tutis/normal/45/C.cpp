/*input
4
BGBG
4 2 4 3
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll modulo = 1000 * 1000 * 1000 + 7;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	set<int>X;
	set<pair<int, pair<int, int>>>Y;
	string S;
	cin >> S;
	int A[n];
	for (int i = 0; i < n; i++)
		cin >> A[i];
	for (int i = 0; i < n; i++)
	{
		X.insert(i);
	}
	for (int i = 1; i < n; i++)
	{
		if (S[i] != S[i - 1])
			Y.insert({abs(A[i] - A[i - 1]), {i - 1, i}});
	}
	vector<pair<int, int>>ans;
	while (!Y.empty())
	{
		auto i = *Y.begin();
		Y.erase(Y.begin());
		int a = i.second.first;
		int b = i.second.second;
		ans.push_back({a, b});
		X.erase(a);
		X.erase(b);
		int x = -1;
		int y = -1;
		{
			auto it = X.lower_bound(a);
			if (it != X.begin())
			{
				it--;
				x = *it;
			}
		}
		{
			auto it = X.lower_bound(b);
			if (it != X.end())
			{
				y = *it;
			}
		}
		if (x != -1 && S[x] != S[a])
		{
			Y.erase({abs(A[x] - A[a]), {x, a}});
		}
		if (y != -1 && S[y] != S[b])
		{
			Y.erase({abs(A[y] - A[b]), {b, y}});
		}
		if (x != -1 && y != -1 && S[x] != S[y])
		{
			Y.insert({abs(A[x] - A[y]), {x, y}});
		}
	}
	cout << ans.size() << "\n";
	for (auto i : ans)
		cout << i.first + 1 << " " << i.second + 1 << "\n";
}