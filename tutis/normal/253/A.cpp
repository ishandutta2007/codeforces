/*input
3 100

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int n, m;
	cin >> n >> m;
	int s = 1;
	if (n >= m)
		s = 0;
	int b = n;
	int g = m;
	for (int i = 0; i < n + m; i++)
		if ((i % 2 == s && b > 0) || g == 0)
		{
			cout << 'B';
			b--;
		}
		else
		{
			cout << 'G';
			g--;
		}
	cout << "\n";
	return 0;
}