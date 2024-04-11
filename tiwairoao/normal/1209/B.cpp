#include<cstdio>
#include<algorithm>
using namespace std;
int cnt[12000 + 5];
int a[100 + 5], b[100 + 5], n;
char s[100 + 5];
int main() {
	scanf("%d%s", &n, s + 1);
	for(int i=1;i<=n;i++) {
		scanf("%d%d", &a[i], &b[i]);
		int p = b[i], q = s[i] - '0';
		for(int j=0;j<12000;j++) {
			if( j == p ) q ^= 1, p += a[i];
			cnt[j] += q;
		}
	}
	int ans = 0;
	for(int i=0;i<12000;i++)
		ans = max(ans, cnt[i]);
	printf("%d\n", ans);
}