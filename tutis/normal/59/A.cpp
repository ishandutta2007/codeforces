/*input
HoUse
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	string S;
	cin >> S;
	int k[2] = {0, 0};
	for (char x : S)
	{
		k[isupper(x)]++;
	}
	if (k[1] > k[0])
		for (char &x : S)
			x = toupper(x);
	else
		for (char &x : S)
			x = tolower(x);
	cout << S << "\n";
}