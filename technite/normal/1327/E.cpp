#include <bits/stdc++.h>
using namespace std;
 const int mod = 998244353;
long long n, k, pw[200007];
int main()
{
	cin >> n;
	pw[0] = 1;
	for (long long i = 1; i <= n; ++i)	pw[i] = pw[i - 1] * 10 % mod;
	for (long long i = 1; i < n; ++i) cout << (180 * pw[n - i - 1] + 81 * (n - i - 1) * pw[n - i - 1]) % mod << " ";
	cout << 10;
}