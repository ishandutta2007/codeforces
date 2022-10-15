#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
long long n,m,k,a[200001];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	long long sum=m/(k+1),mod=m%(k+1);
	printf("%lld",sum*(a[1]*k+a[2])+mod*a[1]);
	return 0;
}