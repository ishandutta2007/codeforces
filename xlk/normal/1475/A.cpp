#include <bits/stdc++.h>
using namespace std;
int t;
long long n;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		cout << (n & n - 1 ? "Yes" : "No") << endl;
	}
	return 0;
}