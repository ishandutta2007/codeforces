/*input
3
80 60 60

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int kiek = 0;
	vector<int>ok;
	for (int i = 0; i < n; i++)
		if (a[i] * 2 <= a[0] || i == 0)
		{
			ok.push_back(i);
			kiek += a[i];
		}
		else
			kiek -= a[i];
	if (kiek <= 0)
		ok.clear();
	cout << ok.size() << "\n";
	for (int i : ok)
		cout << i + 1 << " ";
}