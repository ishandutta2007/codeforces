#include <bits/stdc++.h>
using namespace std;
int t;
long long d, k;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> d >> k;
		int s = sqrt(0.5 * d * d / k / k);
		if ((s * k) * (s * k) + (s * k + k) * (s * k + k) > d * d)
		{
			cout << "Utkarsh" << endl;
		}
		else
		{
			cout << "Ashish" << endl;
		}
	}
	return 0;
}