#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
long long n;
int m, l, z;
long long d[100];
int a[100][100];
int b[100][100];
void mul(int a[100][100], int b[100][100]) {
	int w[100][100] = {};
	for (int i = 0; i < m; i++) {
		for (int k = 0; k < m; k++) {
			if (a[i][k] == 0) {
				continue;
			}
			for (int j = 0; j < m; j++) {
				w[i][j] = (w[i][j] + (long long)a[i][k] * b[k][j]) % p;
			}
		}
	}
	memcpy(a, w, sizeof w);
}
int main() {
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		cin >> d[i];
	}
	for (int i = 0; i < m; i++)
	{
		a[0][i] = 1;
		for (int j = 0; j < m; j++)
		{
			b[i][j] = __builtin_popcountll(d[i] ^ d[j]) % 3 == 0;
		}
	}
	for (n--; n > 0; n >>= 1) {
		if (n & 1) {
			mul(a, b);
		}
		mul(b, b);
	}
	for (int i = 0; i < m; i++)
	{
		z = (z + a[0][i]) % p;
	}
	cout << z << endl;
	return 0;
}