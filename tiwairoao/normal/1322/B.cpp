#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 400000;

int a[MAXN + 5], n, ans;
int b[2][MAXN + 5], s[2];
int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &a[i]);
	for(int i=0;i<25;i++) {
		int t = (1 << i) - 1; s[0] = s[1] = 0;
		for(int j=1;j<=n;j++)
			b[(a[j] >> i) & 1][++s[(a[j] >> i) & 1]] = (a[j] & t);
		long long cnt = 0;
		sort(b[0], b[0] + s[0] + 1);
		sort(b[1], b[1] + s[1] + 1);
		for(int o=0;o<=1;o++) {
			for(int j=1;j<=s[o];j++) {
				long long p = upper_bound(b[!o], b[!o] + s[!o] + 1, t - b[o][j]) - b[!o] - 1;
				long long q = s[o] - (upper_bound(b[o], b[o] + s[o] + 1, t - b[o][j]) - b[o]) + 1;
				cnt += p + q;
			}
		}
		for(int j=1;j<=n;j++)
			if( ((a[j] + a[j]) >> i) & 1 ) cnt--;
		if( (cnt / 2) & 1 ) ans |= (1 << i);
	}
	printf("%d\n", ans);
}