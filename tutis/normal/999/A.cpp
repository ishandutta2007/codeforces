/*input
8 4
4 2 3 1 5 1 6 4
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	deque<int>A;
	while (n--) {
		int a;
		cin >> a;
		A.push_back(a);
	}
	int ans = 0;
	while (!A.empty())
	{
		if (A.front() <= k)
		{
			A.pop_front();
			ans++;
		}
		else if (A.back() <= k)
		{
			A.pop_back();
			ans++;
		}
		else
			break;
	}
	cout << ans << "\n";



}