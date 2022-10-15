#include<bits/stdc++.h>
using namespace std;
struct number
{
	int s;
	int x;
	int y;
}a[200010];
int b[200010];
int t;
bool cmp(number a,number b)
{
	return a.s<b.s;
}
int main()
{
	int k,n;
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
	  {
	  	int sum=0;
		scanf("%d",&n);
	  	for(int j=1;j<=n;j++)
	  	  {
	  	  	scanf("%d",&b[j]);
	  	  	sum+=b[j];
		  }
		for(int j=1;j<=n;j++)
		  {
		  	a[++t].s=sum-b[j];
		  	a[t].x=i;
		  	a[t].y=j;
		  }
	  }
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<t;i++)
	  if(a[i].s==a[i+1].s&&a[i].x!=a[i+1].x)
	  	{
	  	  printf("YES\n");
	  	  printf("%d %d\n",a[i].x,a[i].y);
	  	  printf("%d %d",a[i+1].x,a[i+1].y);
	  	  return 0;
		}
	printf("NO");
	return 0;
}