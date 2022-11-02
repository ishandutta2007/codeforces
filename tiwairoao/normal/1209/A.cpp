#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 100;
bool vis[MAXN + 5];
int a[MAXN + 5], n;
int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	int ans = 0;
	for(int i=1;i<=n;i++) {
		if( !vis[i] ) {
			vis[i] = true, ans++;
			for(int j=i;j<=n;j++)
				if( a[j] % a[i] == 0 )
					vis[j] = true;
		}
	}
	printf("%d\n", ans);
}