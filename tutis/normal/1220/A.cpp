/*input
10
nznooeeoer

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int z = count(s.begin(), s.end(), 'z');
	n -= z * 4;
	n /= 3;
	while (n > 0)
	{
		n--;
		cout << "1 ";
	}
	while (z > 0)
	{
		z--;
		cout << "0 ";
	}
}