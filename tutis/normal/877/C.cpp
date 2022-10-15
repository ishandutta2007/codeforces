/***
3
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	vector<int>ans;
	for (int i = 2; i <= n; i += 2)
		ans.push_back(i);
	for (int i = 1; i <= n; i += 2)
		ans.push_back(i);
	for (int i = 2; i <= n; i += 2)
		ans.push_back(i);
	cout << ans.size() << "\n";
	for (int i : ans)
		cout << i << " ";
}