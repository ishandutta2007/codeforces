/*input
1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	queue<pair<int, string>>X;
	X.push({1, "Sheldon"});
	X.push({1, "Leonard"});
	X.push({1, "Penny"});
	X.push({1, "Rajesh"});
	X.push({1, "Howard"});
	while (true)
	{
		pair<int, string>a = X.front();
		X.pop();
		if (n - a.first <= 0)
		{
			cout << a.second << "\n";
			return 0;
		}
		n -= a.first;
		a.first *= 2;
		X.push(a);
	}
}