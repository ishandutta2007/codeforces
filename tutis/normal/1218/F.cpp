/*input
5 10000
10000 30000 30000 40000 20000
20000
5 2 8 3 6

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	pair<int, int>X[N];
	for (int i = 0; i < N; i++)
		cin >> X[i].first;
	int A;
	cin >> A;
	for (int i = 0; i < N; i++)
		cin >> X[i].second;
	ll ans = 0;
	priority_queue<int>D;
	for (pair<int, int>a : X)
	{
		D.push(-a.second);
		while (K < a.first)
		{
			if (D.empty())
			{
				cout << "-1\n";
				return 0;
			}
			K += A;
			ans -= D.top();
			D.pop();
		}
	}
	cout << ans << "\n";
}