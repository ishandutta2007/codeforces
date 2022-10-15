/*input
3
1 1
3 1
1 3
L

*/
#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct point
{
	ll x, y;
	point(ll x = 0, ll y = 0): x(x), y(y)
	{

	}
} A[2222];
point operator-(point &a, point &b)
{
	return point(a.x - b.x, a.y - b.y);
}
ll cross(point a, point b)
{
	return a.x * b.y - a.y * b.x;
}
string s;
int P[2222];
int n;
int K[2222];
void check(int k)
{
	if (k >= n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << P[i] << "\n";
		}
		exit(0);
	}
	int j = -1;
	for (int i = 1; i <= n; i++)
	{
		if (K[i] == 0)
		{
			if (j == -1)
			{
				j = i;
			}
			else
			{
				if (k == 0)
				{
					if (A[i].x > A[j].x)
						j = i;
				}
				else
				{
					if (s[k] == 'L')
					{
						if (cross(A[i] - A[P[k - 1]], A[j] - A[P[k - 1]]) > 0)
							j = i;
					}
					else
					{
						if (cross(A[i] - A[P[k - 1]], A[j] - A[P[k - 1]]) < 0)
							j = i;
					}
				}
			}
		}
	}
	K[j]++;
	P[k] = j;
	check(k + 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> A[i].x >> A[i].y;
	}
	cin >> s;
	s = "R" + s + "RR";
	check(0);
}