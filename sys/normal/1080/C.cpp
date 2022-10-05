#include <bits/stdc++.h>
using namespace std;
int n,m,t,X1,X2,X3,X4,Y1,Y2,Y3,Y4;
long long tmp;
long long cal(int a,int b,int c,int d)
{
	if(a>b) return 0;
	if(c>d) return 0;
	long long ans=(b-a+1)*(long long)(d-c+1)/2;
	if((b-a+1)*(long long)(d-c+1)%2)
	{
		if((a+c)%2) return ans+1;
		else return ans;
	}
	return ans;
}
long long ans;
int main()
{
//	freopen("C.in","r",stdin);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		ans=0;
		scanf("%d%d",&n,&m);
		scanf("%d%d%d%d",&X1,&Y1,&X2,&Y2);
		scanf("%d%d%d%d",&X3,&Y3,&X4,&Y4);
		tmp=cal(max(X1,X3),min(X2,X4),max(Y1,Y3),min(Y2,Y4));
		ans+=(X4-X3+1)*(long long)(Y4-Y3+1)-cal(X3,X4,Y3,Y4);
		ans=cal(1,n,1,m)-cal(X1,X2,Y1,Y2)+tmp+ans;
		printf("%lld %lld\n",n*(long long)m-ans,ans);
	}
	return 0;
}