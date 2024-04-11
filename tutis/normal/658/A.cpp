/*input
3 6
50 85 250
10 15 25

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int ceiling(int a, int b)
{
	if (a % b == 0)
		return a / b;
	return a / b + 1;
}
int main()
{
	int ans = 0;
	ios_base::sync_with_stdio(false);
	int n, c;
	cin >> n >> c;
	int p[n];
	for (int i = 0; i < n; i++)
		cin >> p[i];
	int t[n];
	for (int i = 0; i < n; i++)
		cin >> t[i];
	int t1 = 0;
	int t2 = 0;
	int p1 = 0;
	int p2 = 0;
	for (int i = 0; i < n; i++)
	{
		t1 += t[i];
		p1 += max(0, p[i] - t1 * c);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		t2 += t[i];
		p2 += max(0, p[i] - t2 * c);
	}
	if (p1 > p2)
	{
		cout << "Limak\n";
	}
	if (p1 < p2)
	{
		cout << "Radewoosh\n";
	}
	if (p1 == p2)
	{
		cout << "Tie\n";
	}
}