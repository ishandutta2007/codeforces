#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long ll;

const int N = 2020;
const int C = 204;

int gcd(int x, int y)
{
	return (y == 0 ? x : gcd(y, x % y));
}

int x[N], y[N];
int a[C][2 * C];

int n;
ll ans;

void solve(int id)
{
	memset(a, 0, sizeof a);
	for (int i = id + 1; i < n; i++)
	{
		int xx = x[i] - x[id];
		int yy = y[i] - y[id];
		if (xx < 0)
		{
			xx *= -1;
			yy *= -1;
		}
		if (xx == 0 && yy < 0)
			yy *= -1;
		int g = gcd(xx, abs(yy));
		xx /= g;
		yy /= g;
		yy += C;
		ans -= a[xx][yy];
		a[xx][yy]++;
	}
	return;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	ans = (ll)n * (n - 1) * (n - 2) / 6LL;

	for (int i = 0; i < n; i++)
		solve(i);

	cout << ans << endl;

	return 0;
}