#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, m, a[105];
int color[105], cnt[105];
bool flag;
void dfs(int x, int st) {
	color[x] = m; ++cnt[m];
	if (!color[a[x]]) dfs(a[x], st);
	else if (a[x] != st) flag = false;
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	flag = true;
	for (int i = 1; i <= n; ++i)
		if (!color[i]) {
			++m;
			dfs(i, i);
		}
	if (!flag) printf("%d\n", -1);	
	else {
		LL ans = 1;
		for (int i = 1; i <= m; ++i) {
			if (cnt[i] % 2 == 0) cnt[i] /= 2;
			ans = ans * cnt[i] / __gcd(ans, (LL)cnt[i]);
		}
		cout << ans << endl;
	}
}