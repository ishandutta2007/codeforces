#include<bits/stdc++.h>
using namespace std;
const int N=12005,inf=2e9;
int n,q,a,b,k,m;
double x[N],y[N],ans[N],p[N],t,s;
int main()
{
	scanf("%d%d%d%d",&n,&q,&a,&b);
	for(int i=1;i<=n;i++)
		scanf("%lf",&p[i]);
	x[m]=1,y[m]=2.0*(1-p[1]),m++;
	x[m]=inf,y[m]=2.0*(inf-p[1]),m++;
	t=x[0]-y[0]/(y[1]-y[0])*(x[1]-x[0]);
	ans[1]=t;
	for(int i=2;i<=n;i++)
	{
		for(int j=m-1;j>k;j--)
			x[j+2]=x[j],y[j+2]=y[j];
		m+=2;
		x[k+1]=t,y[k+1]=0;
		x[k+2]=t,y[k+2]=0;
		k++;
		for(int j=0;j<=k;j++)
			x[j]+=a;
		for(int j=k+1;j<m;j++)
			x[j]+=b;
		for(int j=0;j<m;j++)
			y[j]+=2*(x[j]-p[i]);
		if(y[0]>=0)
		{
			k=-1;
			t=x[0];
		}
		else
		{
			for(k=0;k<m;k++)
				if(y[k]<=0&&y[k+1]>0)
					break;
			t=x[k]-y[k]/(y[k+1]-y[k])*(x[k+1]-x[k]);
		}
		ans[i]=t;
	}
	ans[n]=min(ans[n],1.0*q);
	for(int i=n;i>=2;i--)
		ans[i-1]=min(ans[i]-a,max(ans[i-1],ans[i]-b));
	for(int i=1;i<=n;i++)
	{
		printf("%.6lf ",ans[i]);
		s+=(ans[i]-p[i])*(ans[i]-p[i]);
	}
	printf("\n%.6lf\n",s);
	return 0;
}