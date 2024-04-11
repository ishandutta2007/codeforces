/*input
6
1 1 1
3 6 0
0 0 0
0 1 1
10 1 10
4 4 1

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int t = min(a, b);
		t = min(t, (a + b + c) / 3);
		cout << t << "\n";
	}


}