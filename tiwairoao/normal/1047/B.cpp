#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int ans = 0, n;
	scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		ans = max(ans, x+y);
	}
	printf("%d\n", ans);
}