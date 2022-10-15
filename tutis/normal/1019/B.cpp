/*input
8
3
4
5
6
7
8
8
2
4
6
5
2
4
5

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
map<int, int>X;
int ask(int i)
{
	if (X.count(i))
		return X[i];
	if (X.size() >= 30)
	{
		cout << "! -1" << endl;
		exit(0);
	}
	cout << "? " << i << endl << flush;
	int a;
	cin >> a;
	ll x = i + n / 2;
	if (x > n)
		x -= n;
	cout << "? " << x << endl << flush;
	int b;
	cin >> b;
	if (a == b)
	{
		cout << "! " << i << "\n";
		exit(0);
	}
	return X[i] = a - b;
}
int main()
{
	srand(time(NULL));
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	vector<int>a[2];
	while (a[0].empty() || a[1].empty() && X.size() < 30)
	{
		int x = rand() % (n / 2) + 1;
		if (ask(x) > 0)
			a[0].push_back(x);
		else
			a[1].push_back(x);
		int y = x + n / 2;
		if (ask(y) > 0)
			a[0].push_back(y);
		else
			a[1].push_back(y);
	}
	int lo = min(a[0].front(), a[1].front());
	int hi = max(a[0].front(), a[1].front());
	while (abs(lo - hi) > 2)
	{
		int m = (lo + hi) / 2;
		if ((ask(lo) > 0) != (ask(m) > 0))
			hi = m;
		else
			lo = m;
	}
	for (int t = lo; t <= hi; t++)
	{
		ask(t);
	}
	cout << "! -1" << endl;
}