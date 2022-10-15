/*input
3 3
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	if (min(n, m) % 2 == 0)
		cout << "Malvika\n";
	else
		cout << "Akshat\n";
}