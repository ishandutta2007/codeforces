#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005, p = 1e9 + 7;
int n, ct, P2[23], P3[4];
long long f[23][3];
int cal(int x)
{
	return n / x;
}
int main()
{
	P2[0] = 1;
	for (int i = 1; i <= 21; i++)
		P2[i] = P2[i - 1] * 2;
	P3[0] = 1, P3[1] = 3, P3[2] = 9;
	scanf("%d", &n);
	int now = 1;
	while ((now << 1) <= n) now <<= 1, ct++;
	f[ct][0] = 1;
	now >>= 1;
	if (now * 3 <= n) f[ct - 1][1] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 0; j <= ct; j++)
			for (int k = 0; k <= 1; k++)
			{
				(f[j][k] = f[j][k] * (cal(P2[j] * P3[k]) - i + 1) % p) %= p;
				(f[j][k] += f[j + 1][k] * (cal(P2[j] * P3[k]) - cal(P2[j + 1] * P3[k])) % p) %= p;
				(f[j][k] += f[j][k + 1] * (cal(P2[j] * P3[k]) - cal(P2[j] * P3[k + 1])) % p) %= p;
			}
	printf("%lld", f[0][0]);
	return 0;
}