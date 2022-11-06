#include<stdio.h>
int a[100001], p[100001];
long long S[100001];
int P[100001], on[100001];
long long ans[100001];
int getR(int x){ return (P[x]==x)?(x):(P[x]=getR(P[x])); }
void uni(int a, int b){
	a=getR(a); b=getR(b);
	P[a] = b; S[b]+=S[a];
}
int main()
{
	int n, i;
	long long max = 0;
	scanf("%d", &n);
	for(i=1; i<=n; i++)scanf("%d", a+i);
	for(i=1; i<=n; i++)scanf("%d", p+i);
	for(int i=1; i<=n; i++) P[i] = i;
	for(i=n; i>=1; i--)
	{
		int x = p[i];
		on[x] = 1; S[x] = a[x];
		if(on[x+1] == 1) uni(x, x+1);
		if(on[x-1] == 1) uni(x, x-1);
		long long t = S[getR(x)];
		if(max < t) max = t;
		ans[i] = max;
	}
	for(int i=2; i<=n; i++)printf("%lld\n", ans[i]); printf("0");
	return 0;
}