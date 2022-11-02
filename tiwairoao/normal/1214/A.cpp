#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int n, d, e;
	scanf("%d%d%d", &n, &d, &e); e *= 5;
	int ans = int(1E9);
	for(int i=0;i<=n/e;i++) {
		ans = min(ans, (n - i*e) % d);
	}
	printf("%d\n", ans);
}