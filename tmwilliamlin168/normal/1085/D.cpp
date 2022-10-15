#include<bits/stdc++.h>
using namespace std;
int n;
long long s;
int vis[200006], x, y, cnt;
int main()
{
	scanf("%d%lld", &n, &s);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		vis[x]++;
		vis[y]++;
	}
	double ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (vis[i] == 1) {
			cnt++;
		}
	}
	printf("%.10lf\n", (s + 0.0) / cnt * 2.0);
}