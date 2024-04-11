#include<bits/stdc++.h>
using namespace std;
int a[200010],ans[4];
int n;
bool find(int x)
{
	int l=1,r=n;
	while(l<=r)
	  {
	  	int m=(l+r)/2;
	  	if(a[m]==x)
	  	  return true;
	  	if(a[m]<x)
	  	  l=m+1;
	  	else
	  	  r=m-1;
	  }
	return false;
}
int ksm(int b)
{
	int a=2,s=1;
	while(b>0)
	  {
	  	if(b&1)
	  	  s*=a;
	  	a*=a;
	  	b/=2;
	  }
	return s;
}
int main()
{
	int tot=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	ans[1]=a[1];
	for(int i=1;i<=n;i++)
	  {
	  	for(int j=0;j<=30;j++)
	  	  {
			if(find(a[i]-ksm(j))&&find(a[i]+ksm(j))&&tot<3)
			  {
			  	tot=3;
			  	ans[1]=a[i]-ksm(j);
			  	ans[2]=a[i];
			  	ans[3]=a[i]+ksm(j);
			  }
			if(find(a[i]-ksm(j))&&tot<2)
			  {
			  	tot=2;
			  	ans[1]=a[i]-ksm(j);
			  	ans[2]=a[i];
			  }
			if(find(a[i]+ksm(j))&&tot<2)
			  {
			  	tot=2;
			  	ans[1]=a[i];
			  	ans[2]=a[i]+ksm(j);
			  }
		  }
	  }
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++)
	  printf("%d ",ans[i]);
	return 0;
}