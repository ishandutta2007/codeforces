#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,k;
int a[maxn];
int gcd(int a,int b)
{
	if(!b)return a;
	return gcd(b,a%b);
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
	}
	int t=k;
	for(int i=1;i<=n;++i)t=gcd(a[i],t);
	int tot=0;
	for(int i=1;i<=k;++i)
	{
		if(i%t==0)tot++;
	}
	printf("%d\n",tot);
	if(k%t==0)printf("0 ");
	for(int i=1;i<k;++i)
	{
		if(i%t==0)printf("%d ",i%k);
	}
	return 0;
}