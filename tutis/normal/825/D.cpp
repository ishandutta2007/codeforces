/***
?aa?
ab
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	string s, t;
	cin >> s >> t;
	int A[26];
	fill_n(A, 26, 0);
	for (char i : t)
	{
		A[i - 'a']++;
	}
	int B[26];
	fill_n(B, 26, 0);
	for (char i : s)
	{
		if (i != '?')
			B[i - 'a']++;
	}
	for (char &i : s)
	{
		if (i == '?')
		{
			ld an = DBL_MAX;
			int k = 0;
			for (int j = 0; j < 26; j++)
			{
				if (A[j] && ld(B[j] + 1) / ld(A[j]) < an)
				{
					an = ld(B[j] + 1) / ld(A[j]);
					k = j;
				}
			}
			B[k]++;
			i = k + 'a';
		}
	}
	cout << s;
}