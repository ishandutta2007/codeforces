#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
long long k;
int a[100020],b[100020];
int c1[100020],c2[100020];
void R(int *a,int x,int y)
{
	for(;x<=m;x+=x&-x)
		a[x]+=y;
}
int G(int *a,int x){
	int _=0;
	for(;x;x-=x&-x)
		_+=a[x];
	return _;
}
long long s,z;
int main()
{
	scanf("%d%I64d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i),b[m++]=a[i];
	sort(b,b+m);
	m=unique(b,b+m)-b;
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(b,b+m,a[i])-b+1;
	for(int i=1;i<=n;i++)
	{
		R(c1,a[i],1);
		s+=i-G(c1,a[i]);
	}
	if(s<=k)
		return cout<<(long long)n*(n-1)/2,0;
	R(c1,a[n],-1);
	R(c2,a[n],1);
	cerr << s << endl;
	for(int r=n,l=n-1;;)
	{
		while(l>0&&s>k)
		{
			s-=l-G(c1,a[l]);
			s-=G(c2,a[l]-1);
			R(c1,a[l],-1);
			l--;
		}
		if(l==0)
			break;
		z+=l;
		r--;
		s+=l-G(c1,a[r]);
		s+=G(c2,a[r]-1);
		R(c2,a[r],1);
	}
	printf("%I64d",z);
	return 0;
}