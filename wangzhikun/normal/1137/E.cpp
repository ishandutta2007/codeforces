#include <stdio.h>
const int N=3e5;
int x[N];
long long y[N];
int main()
{
	int n, m, cnt=0;
	long long bsum=0, ssum=0;
	scanf("%d%d", &n, &m);
	while(m--) {
		int op;
		scanf("%d", &op);
		if(op==1) {
			int k;
			scanf("%d", &k);
			cnt=0;
			n+=k;
			bsum=ssum=0;
		}
		if(op==2) {
			int k;
			scanf("%d", &k);
			while(cnt>=1 && (long double)(y[cnt]-y[cnt-1])*(n-x[cnt])>=(long double)(x[cnt]-x[cnt-1])*(-ssum*n-bsum-y[cnt])) --cnt;
			x[++cnt]=n;
			y[cnt]=-ssum*n-bsum;
			n+=k;
		}
		if(op==3) {
			int b, s;
			scanf("%d%d", &b, &s);
			bsum+=b;
			ssum+=s;
		}
		while(cnt && ssum*x[cnt-1]+y[cnt-1]<=ssum*x[cnt]+y[cnt]) --cnt;
		printf("%d %I64d\n", x[cnt]+1, ssum*x[cnt]+y[cnt]+bsum);
	}
	return 0;
}