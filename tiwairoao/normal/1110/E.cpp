#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 100000;
int c[MAXN + 5], d[MAXN + 5];
int main() {
	int n; scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d", &c[i]);
	for(int i=1;i<=n;i++) scanf("%d", &d[i]);
	if( c[1] != d[1] ) {
		puts("No");
		return 0;
	}
	for(int i=1;i<n;i++)
		c[i] = c[i + 1] - c[i];
	for(int i=1;i<n;i++)
		d[i] = d[i + 1] - d[i];
	sort(c + 1, c + n);
	sort(d + 1, d + n);
	for(int i=1;i<n;i++)
		if( c[i] != d[i] ) {
			puts("No");
			return 0;
		}
	puts("Yes");
	return 0;
}