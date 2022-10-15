/***
3
& 1
& 3
& 5
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
	int A[12];
	int B[12];
	for (int i = 0; i < 10; i++)
		A[i] = true;
	for (int i = 0; i < 10; i++)
		B[i] = false;
	for (int i = 0; i < n; i++)
	{
		char x;
		int c;
		cin >> x >> c;
		for (int j = 0; j < 10; j++)
		{
			if (x == '&')
			{
				A[j] &= (c % 2);
				B[j] &= (c % 2);
			}
			if (x == '|')
			{
				A[j] |= (c % 2);
				B[j] |= (c % 2);
			}
			if (x == '^')
			{
				A[j] ^= (c % 2);
				B[j] ^= (c % 2);
			}
			c /= 2;
		}
	}
	int AAA = 0;
	int BBB = 0;
	for (int i = 0; i < 10; i++)
	{
		int a_ = 0, b_ = 0;
		for (int a = 0; a < 2; a++)
		{
			for (int b = 0; b < 2; b++)
			{
				int AA = (((true | a) ^ b));
				int BB = (((false | a) ^ b));
				if (AA == A[i] && BB == B[i])
				{
					a_ = a;
					b_ = b;
				}
			}
		}
		AAA += a_ * (1ll << i);
		BBB += b_ * (1ll << i);
	}
	cout << 2 << "\n";
	cout << "| " << AAA << '\n';
	cout << "^ " << BBB << '\n';
}