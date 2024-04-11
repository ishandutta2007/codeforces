#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 100000;
int a[MAXN + 5], b[MAXN + 5];
int main() {
	int n, x; scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &x), a[x] = i;
	for(int i=1;i<=n;i++)
		scanf("%d", &x), b[a[x]] = i;
	int mx = 0, ans = 0;
	for(int i=1;i<=n;i++) {
		if( mx > b[i] ) ans++;
		mx = max(mx, b[i]);
	}
	printf("%d", ans);
}