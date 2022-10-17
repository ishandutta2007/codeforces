#include <bits/stdc++.h>
using namespace std;
int t, n;
long long s, x;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		s = 0;
		for(int i = 0; i < n + 2; i++)
		{
			cin >> x;
			s ^= x;
		}
		cout << (s & 1 ? "Bob" : "Alice") << endl;
	}
	return 0;
}