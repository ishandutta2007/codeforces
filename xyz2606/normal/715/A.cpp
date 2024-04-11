#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	long long x(2);
	for(int i(1); i <= n; i++) {
		long long ans(1ll * (i + 1) * (i + 1) * i - (x / i));
		cout << ans << endl;
		x = (long long)i * (i + 1);
	}
}