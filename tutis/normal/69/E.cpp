/*input
5 3
1
2
2
3
3
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
map<int, int>X;
set<int>po1;
void add(int x)
{
	X[x]++;
	if (X[x] == 1)
		po1.insert(x);
	if (X[x] == 2)
		po1.erase(x);
}
void del(int x)
{
	X[x]--;
	if (X[x] == 0)
		po1.erase(x);
	if (X[x] == 1)
		po1.insert(x);
}
int get()
{
	if (!po1.empty())
		return *(--po1.end());
	return -1;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cerr.tie(0);
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < k - 1; i++)
		add(a[i]);
	for (int i = 0; i + k - 1 < n; i++)
	{
		if (i != 0)
			del(a[i - 1]);
		add(a[i + k - 1]);
		int X = get();
		if (X == -1)
			cout << "Nothing\n";
		else
			cout << X << "\n";
	}
	return 0;
}