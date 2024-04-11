/*input
4 6
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	int D[100005];
	fill_n(D, 100005, 1000099);
	queue<int>Q;
	D[n] = 0;
	Q.push(n);
	while (!Q.empty())
	{
		int a = Q.front();
		Q.pop();
		if (2 * a < 100005 && D[2 * a] > D[a] + 1)
		{
			D[2 * a] = D[a] + 1;
			Q.push(2 * a);
		}
		if (a > 1 && D[a - 1] > D[a] + 1)
		{
			D[a - 1] = D[a] + 1;
			Q.push(a - 1);
		}
	}
	cout << D[m] << "\n";
}