/*input
30409
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ll n;
	cin >> n;
	map<ll, ll>A;
	A[0] = 0;
	queue<pair<ll, ll>>Q;
	Q.push({0, 0});
	set<ll>X;
	bool galima = false;
	while (!Q.empty())
	{
		ll a = Q.front().first;
		ll b = Q.front().second;
		Q.pop();
		if (b > n)
			continue;
		if (a > 1000000)
		{
			break;
		}
		X.insert(a);
		if (A.count(49 + a) == 0 || A[49 + a] > b + 1)
		{
			A[49 + a] = b + 1;
			Q.push({49 + a, b + 1});
		}
		if (A.count(45 + a) == 0 || A[45 + a] > b + 1)
		{
			A[45 + a] = b + 1;
			Q.push({45 + a, b + 1});
		}
		if (A.count(40 + a) == 0 || A[40 + a] > b + 1)
		{
			A[40 + a] = b + 1;
			Q.push({40 + a, b + 1});
		}
	}
	if (49 * n <= 1000000)
	{
		cout << X.size() << "\n";
		return 0;
	}
	const int Y = 400000;
	while (*(--X.end()) > Y)
	{
		X.erase(--X.end());
	}
	cout << 49 * n + 1 - (2 * (Y + 1)) + 2 * X.size() + 224 << "\n";
}