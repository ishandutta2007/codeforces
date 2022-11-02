#include<cstdio>
const int MAXN = 300000;
char s[MAXN + 5];
bool tag[2*MAXN + 5];
int a[2*MAXN + 5], n;
int stk[2*MAXN + 5], tp;
int dep[2*MAXN + 5], sum[2*MAXN + 5], key[2*MAXN + 5];
int mat[2*MAXN + 5];
int main() {
	scanf("%d%s", &n, s + 1);
	for(int i=1;i<=n;i++)
		a[i] = (s[i] == '(') ? 1 : -1;
	int cnt = 0;
	for(int i=1;i<=n;i++)
		cnt += a[i];
	if( cnt ) {
		puts("0\n1 1");
		return 0;
	}
	for(int i=1;i<=n;i++)
		a[i+n] = a[i];
	int pos = 1;
	for(int i=1;i<=2*n;i++) {
		tp += a[i];
		if( tp < 0 )
			pos = i + 1, tp = 0;
		else if( i - pos + 1 >= n )
			break;
	}
	for(int i=pos;i<=pos+n-1;i++) {
		if( a[i] == -1 ) {
			if( tp ) {
				int x = stk[tp--];
				dep[i] = tp;
				sum[tp]++;
				key[i] = sum[tp + 1];
				sum[tp + 1] = 0;
				mat[i] = x;
			}
		}
		else stk[++tp] = i;
	}
	int ans = sum[0], p = 1, q = 1;
	for(int i=pos;i<=pos+n-1;i++) {
		if( a[i] == -1 ) {
			if( dep[i] == 0 ) {
				if( key[i] + 1 > ans )
					p = mat[i], q = i, ans = key[i] + 1;
			}
			else if( dep[i] == 1 ) {
				if( sum[0] + key[i] + 1 > ans )
					p = mat[i], q = i, ans = sum[0] + key[i] + 1;
			}
		}
	}
	printf("%d\n%d %d\n", ans, p > n ? p - n : p, q > n ? q - n : q);
}