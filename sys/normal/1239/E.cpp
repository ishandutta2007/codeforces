#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2500005;
int n, pos1, pos2, pos, mini1 = 0x3f3f3f3f, mini2 = 0x3f3f3f3f, sum, a[Maxn];
char from[55][Maxn];
vector <int> A, B;
bool f[55][Maxn], vis[Maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] < mini1) mini2 = mini1, pos2 = pos1, mini1 = a[i], pos1 = i;
		else if (a[i] < mini2) mini2 = a[i], pos2 = i;
	}
	for (int i = 1; i <= 2 * n; i++)
		if (i != pos1 && i != pos2) sum += a[i];
	f[0][0] = true;
	for (int i = 1; i <= 2 * n; i++)
		if (i != pos1 && i != pos2)
			for (int j = i; j >= 1; j--)
				for (int k = sum; k >= a[i]; k--)
					if (f[j - 1][k - a[i]] && !f[j][k])
					{
						from[j][k] = i;
						f[j][k] = true;
					}
	for (int i = sum / 2; i <= sum; i++)
		if (f[n - 1][i])
		{
			pos = i;
			break;
		}
	for (int i = n - 1; i >= 1; i--)
	{
		A.push_back(a[(int) from[i][pos]]);
		vis[(int) from[i][pos]] = true;
		pos -= a[(int) from[i][pos]];
	}
	for (int i = 1; i <= 2 * n; i++)
		if (!vis[i] && i != pos1 && i != pos2) B.push_back(a[i]);
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater <int> ());
	printf("%d ", mini1);
	for (vector <int> :: iterator it = A.begin(); it != A.end(); it++)
		printf("%d ", *it);
	puts("");
	for (vector <int> :: iterator it = B.begin(); it != B.end(); it++)
		printf("%d ", *it);
	printf("%d ", mini2);
	return 0;
}