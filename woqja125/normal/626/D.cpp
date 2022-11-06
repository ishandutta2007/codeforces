#include<stdio.h>
#include<algorithm>
int a[5001];
int c[5001];
int cs[5010];
int main()
{
	int n, i, j, k;
	long long cnt = 0;
	scanf("%d", &n);
	for(i=1; i<=n; i++)scanf("%d", a+i);
	std::sort(a+1, a+1+n);
	for(i=1; i<n; i++)for(j=i+1; j<=n; j++) c[a[j]-a[i]]++;
	for(i=1; i<=5000; i++)cs[i] = cs[i-1]+c[i];
	int t = n*(n-1)/2; 
	for(i=5000; i>=1; i--)
	{
		for(j=1; j<i; j++) cnt += 1ll*c[i]*c[j]*cs[i-j-1];
	}
	printf("%.10lf", (double)cnt/t/t/t);
	return 0;
}