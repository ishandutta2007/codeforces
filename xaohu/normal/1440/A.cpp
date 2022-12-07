#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, h, c[2];
char s[1005];

void solve() {
	scanf("%d%d%d%d%s", &n, c + 0, c + 1, &h, s);
	int t[2];
	memset(t, 0, sizeof t);
	for(int i = 0; i < n; ++i) t[s[i] - '0']++;
	int sum = 0;
	for (int i = 0; i < 2; ++i)
		sum += min(c[i], (h + c[!i])) * t[i];
	printf("%d\n", sum);
}

int main() {	
	int cases;
	scanf("%d", &cases);
	while(cases--)
		solve();
	return 0;
}