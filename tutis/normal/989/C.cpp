/*input
100 3 2 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << "50 50\n";
	char A[50][50];
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 50; j++)
			A[i][j] = 'B';
	for (int i = 9; i < 50; i++)
		for (int j = 0; j < 50; j++)
			A[i][j] = 'A';
	b--;
	for (int t = 1; t < 9; t += 2)
	{
		int j = 0;
		while (a > 1 && j < 50)
		{
			A[t][j] = 'A';
			j += 2;
			a--;
		}
	}
	for (int t = 10; t < 50; t += 2)
	{
		int j = 0;
		while (b > 0 && j < 50)
		{
			A[t][j] = 'B';
			j += 2;
			b--;
		}
		while (c > 0 && j < 50)
		{
			A[t][j] = 'C';
			j += 2;
			c--;
		}
		while (d > 0 && j < 50)
		{
			A[t][j] = 'D';
			j += 2;
			d--;
		}
	}
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
			cout << A[i][j];
		cout << "\n";
	}


}