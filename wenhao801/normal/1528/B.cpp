#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}
const int mod = 998244353;
int f[1001000], d[1000100];

int main () {
	int n = read();
	f[0] = f[1] = 1; int s = 2;
	for (int i = 1; i <= n; i++) for (int j = i; j <= n; j += i) ++d[j];
	for (int i = 2; i <= n; i++) f[i] = (s + d[i] - 1) % mod, s = (s + f[i]) % mod;
	cout << f[n] << endl;
	return 0;
}