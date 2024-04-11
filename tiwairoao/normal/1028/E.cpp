#include<cstdio>
const int MAXN = 140582;
typedef long long ll;
int b[MAXN + 5], n;
int lst(int x) {return (x == 0) ? n - 1 : x - 1;}
int nxt(int x) {return (x == n - 1) ? 0 : x + 1;}
ll a[MAXN + 5];
int main() {
	scanf("%d", &n);
	for(int i=0;i<n;i++) scanf("%d", &b[i]);
	for(int i=0;i<n;i++)
		if( b[lst(i)] < b[i] ) {
			puts("YES"), a[i] = b[i];
			for(int p=lst(i);p!=i;p=lst(p)) {
				if( b[lst(p)] < b[p] )
					a[p] = b[p];
				else {
					a[p] = ((b[lst(p)] - b[p])/a[nxt(p)] + 1)*a[nxt(p)] + b[p];
				}
			}
			for(int j=0;j<n;j++)
				printf("%lld%c", a[j], (j == n - 1) ? '\n' : ' ');
			return 0;
		}
	if( b[0] == 0 ) {
		puts("YES");
		for(int j=0;j<n;j++)
			printf("1%c", (j == n - 1) ? '\n' : ' ');
	}
	else puts("NO");
}