/*input
30
black
black
white
white
black
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	int lo = 1;
	int hi = 1000000000 - 1;
	cout << 0 << " " << 2 << "\n" << flush;
	string x;
	cin >> x;
	int t = 1;
	int l = lo;
	int h = hi;
	while (t < n)
	{
		int m = (lo + hi) / 2;
		cout << m << " " << 2 << "\n" << flush;
		t++;
		string y = "black";
		cin >> y;
		if (x == y)
		{
			l = m;
			h = hi + 1;
			lo = m + 1;
		}
		else
		{
			l = lo - 1;
			h = m;
			hi = m - 1;
		}
	}
	cout << l << " 1 " << h << " 3\n" << flush;
}