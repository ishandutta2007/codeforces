#include <bits/stdc++.h>
using namespace std;

const int N = 8e3 + 5;

int ans = 1e9;
char s[N], t[N];

int main() {
	scanf("%s", s + 1);
	scanf("%s", t + 1);
	int n, m;
	n = strlen(s + 1);
	m = strlen(t + 1);
	for(int i = n + m; i >= m + 1; -- i) s[i] = s[i - m];
	for(int i = 1; i <= m; ++ i) s[i] = 0;
	for(int i = n + m; i >= 1; -- i) {
		int res = m;
		for(int j = i; j <= i + m - 1; ++ j) {
			if(s[j] == t[j - i + 1]) -- res;
		}
		ans = min(ans, res);
	}
	cout << ans << endl;
}