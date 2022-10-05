#include <bits/stdc++.h>
using namespace std;

const int Maxn = 400005;
int n, b[Maxn];
map <int, long long> Ma;
long long ans;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &b[i]);
		Ma[i - b[i]] += b[i];
	}
	for (map <int, long long> :: iterator it = Ma.begin(); it != Ma.end(); it++)
		ans = max(ans, it -> second);
	printf("%lld", ans);
	return 0;
}