#include<bits/stdc++.h>
using namespace std;
const int max_n=1e6+5;
int a[max_n],L[max_n],R[max_n],st[max_n],tp;
long long v1[max_n],v2[max_n];
double ans[max_n];
int main()
{
	int n;
	scanf("%d",&n);
	st[++tp]=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		while(tp>0&&a[st[tp]]>a[i])
			--tp;
		L[i]=st[tp]+1;
		st[++tp]=i;
	}
	tp=0;
	st[++tp]=n+1;
	for(int i=n;i>=1;--i)
	{
		while(tp>0&&a[st[tp]]>=a[i])
			--tp;
		R[i]=st[tp]-1;
		st[++tp]=i;
	}
	for(int i=1;i<=n;++i)
	{
		int x=i-L[i];
		int y=R[i]-i;
		if(x>y)
			swap(x,y);
		int v=a[i];
		v2[1]+=v,v2[x+2]-=v;
		v1[x+2]+=(x+1ll)*v,v1[y+2]-=(x+1ll)*v;
		v1[y+2]+=(y+x+2ll)*v,v1[y+x+2]-=(y+x+2ll)*v;
		v2[y+2]-=v,v2[y+x+2]+=v;
	}
	for(int i=1;i<=n;++i)
	{
		v1[i]+=v1[i-1];
		v2[i]+=v2[i-1];
		ans[i]=(v1[i]+v2[i]*i)/(n-i+1.0);
	}
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int k;
		scanf("%d",&k);
		printf("%.11lf\n",ans[k]);
	}
	return 0;
}