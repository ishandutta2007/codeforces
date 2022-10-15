/*input
3 2
1 2 3
1 3 2
*/
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	int p[n];
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
		p[i]--;
	}
	int q[n];
	for (int i = 0; i < n; i++)
	{
		cin >> q[i];
		q[i]--;
	}
	string s(n, 'a');
	int l = 0;
	int kiek = 0;
	int K[n];
	fill_n(K, n, 0);
	int bal = 0;
	for (int i = 0; i < n; i++)
	{
		if (p[i] == q[i])
		{
			bal -= abs(K[p[i]]);
		}
		else
		{
			bal -= abs(K[p[i]]);
			bal -= abs(K[q[i]]);
		}
		K[p[i]]++;
		K[q[i]]--;
		if (p[i] == q[i])
		{
			bal += abs(K[p[i]]);
		}
		else
		{
			bal += abs(K[p[i]]);
			bal += abs(K[q[i]]);
		}
		if (bal == 0)
		{
			kiek = min(kiek, 25);
			for (int j = l; j <= i; j++)
			{
				s[p[j]] = 'a' + kiek;
			}
			l = i + 1;
			kiek++;
		}
	}
	if (kiek >= k)
	{
		cout << "YES\n";
		cout << s << "\n";
	}
	else
		cout << "NO\n";
}