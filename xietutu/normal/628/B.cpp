#include <bits/stdc++.h>
using namespace std;
const int maxn = 300010;
int n, sum[maxn];
char s[maxn];
long long ans;
int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; ++i) {
		sum[i] = (sum[i - 1] * 10 + s[i] - '0') % 4;
		if ((sum[i] - sum[i - 1] * 10) % 4 == 0) ++ans;
		if (!sum[i]) ans += i - 1;
	}
	cout << ans << endl;
}