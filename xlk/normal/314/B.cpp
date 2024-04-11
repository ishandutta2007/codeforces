#include <bits/stdc++.h>
using namespace std;
int n, b, d, z, f[233];
char a[233], c[233];
int main()
{
	cin >> b >> d >> a >> c;
	n = strlen(c);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; a[j]; j++)
		{
			if (a[j] == c[(i + f[i]) % n])
			{
				f[i]++;
			}
		}
	}
	for (int i = 0; i < b; i++)
	{
		z += f[z % n];
	}
	cout << z / n / d << endl;
	return 0;
}