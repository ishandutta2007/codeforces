/*input
3
8
1 0
4 1
2 0
4 1
5 1
6 1
3 0
2 0
4
1 1
1 1
2 1
2 1
9
2 0
2 0
4 1
4 1
4 1
7 0
7 1
7 0
7 1

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int a, b, c;
	cin >> a >> b >> c;
	if ((a <= min(b, c)))
		cout << "Yes\n";
	else
		cout << "No\n";
}