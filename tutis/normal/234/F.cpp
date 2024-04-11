/***
3
3 3
2 2 2
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int K[2][200][40007];
#define INF 9000000
int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int n;
	cin >> n;
	int h[n];
	int a, b;
	cin >> a >> b;
	for (int i = 0; i < n; i++)
		cin >> h[i];
	for (int z = 0; z <= a; z++)
		K[0][0][z] = INF;
	for (int z = 0; z <= a; z++)
		K[1][0][z] = INF;
	K[1][0][h[0]] = 0;
	K[0][0][0] = 0;
	for (int i = 1; i < n; i++)
	{
		for (int z = 0; z <= a; z++)
			K[0][i][z] = INF;
		for (int z = 0; z <= a; z++)
			K[1][i][z] = INF;
		for (int z = 0; z <= a; z++)
			if (z - h[i] >= 0)
				K[1][i][z] = min(K[1][i - 1][z - h[i]], K[0][i - 1][z - h[i]] + min(h[i], h[i - 1]));
		for (int z = 0; z <= a; z++)
			K[0][i][z] = min(K[0][i - 1][z], K[1][i - 1][z] + min(h[i], h[i - 1]));
	}
	int suma = 0;
	for (int i = 0; i < n; i++)
		suma += h[i];
	int ans = INF;
	for (int z = 0; z <= a; z++)
	{
		int r = suma - z;
		if (z <= a && r <= b && r >= 0)
		{
			ans = min(ans, K[1][n - 1][z]);
			ans = min(ans, K[0][n - 1][z]);
		}
	}
	if (ans < INF)
		cout << ans;
	else
		cout << "-1";
}