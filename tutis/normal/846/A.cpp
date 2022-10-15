/***
4
1 1 0 1
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	bool a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int ats = 0;
	int vienetu = 0;
	for (int i = 0; i < n; i++)
		if (a[i] == 1)
			vienetu++;
	int nuliu = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0)
		{
			nuliu++;
		}
		ats = max(ats, nuliu + vienetu);
		if (a[i] == 1)
		{
			vienetu--;
		}
	}
	cout << ats;
}