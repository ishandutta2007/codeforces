#include<map>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 100000;
int a[MAXN + 5];
map<int, int>Map;
int main() {
	int n, x;
	scanf("%d%d", &n, &x);
	int ans = 100, cnt = 0;
	for(int i=1;i<=n;i++) {
		scanf("%d", &a[i]);
		if( Map.count(a[i]) )
			ans = min(ans, Map[a[i]]);
		if( Map.count(a[i]&x))
			ans = min(ans, Map[a[i]&x] + 1);
		if( Map.count(a[i]) )
			Map[a[i]] = min(Map[a[i]], 0);
		else Map[a[i]] = 0;
		if( Map.count(a[i]&x))
			Map[a[i]&x] = min(Map[a[i]&x], 1);
		else Map[a[i]&x] = 1;
	}
	if( ans == 100 ) printf("-1\n");
	else printf("%d\n", ans);
}