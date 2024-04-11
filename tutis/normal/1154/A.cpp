/*input
3 6 5 4

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int a[4];
	for (int &i : a)
		cin >> i;
	sort(a, a + 4);
	for (int i = 0; i < 3; i++)
		cout << a[3] - a[i] << " ";
}