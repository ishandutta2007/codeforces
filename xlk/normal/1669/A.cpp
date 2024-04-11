#include <bits/stdc++.h>
using namespace std;
int t, r;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> r;
		if (r < 1400)
		{
			cout << "Division 4" << endl;
		}
		else if (r < 1600)
		{
			cout << "Division 3" << endl;
		}
		else if (r < 1900)
		{
			cout << "Division 2" << endl;
		}
		else
		{
			cout << "Division 1" << endl;
		}
	}
	return 0;
}