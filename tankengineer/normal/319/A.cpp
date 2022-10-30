#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const long long MOD = 1000000007;

char s[205];
long long f[205];

int main() {
	f[0] = 1;
	for (int i = 1; i <= 200; ++i) {
		f[i] = f[i - 1] * 2 % MOD;
	}
	scanf("%s", s);
	int l = strlen(s);
	long long ans = 0, multi = 1;
	for (int i = 0; i < l; ++i) {
		if (s[i] == '1') {
		  ans = (ans + multi * f[2 * (l - i - 1)] % MOD) % MOD;
		}
		multi = multi * 2 % MOD;
	}
	cout << ans << endl;
	return 0;
}