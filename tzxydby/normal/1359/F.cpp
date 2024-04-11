#include<bits/stdc++.h>
using namespace std;
const int N=25005;
int x[N],dx[N],y[N],dy[N],n;
double v[N];
double sol(int a,int b)
{
	int kk=dx[b]*dy[a]-dy[b]*dx[a];
	if(kk!=0)
	{
		double r=0,rr=0;
		r=x[a]*dy[a]+y[b]*dx[a]-y[a]*dx[a]-x[b]*dy[a];
		rr=y[b]*dx[b]+x[a]*dy[b]-y[a]*dx[b]-x[b]*dy[b];
		r/=(1.0*kk*v[b]);rr/=(1.0*kk*v[a]);
		if(min(r,rr)<0) 
			return -1;
		else 
			return max(r,rr);
	}
	else
	{
		if((x[b]-x[a])*dy[a]!=(y[b]-y[a])*dx[a]) 
			return -1;
		else
		{
			double aa=(x[a]*dx[a]+y[a]*dy[a]),bb=(x[b]*dx[a]+y[b]*dy[a]),v1=(dx[a]*dx[a]+dy[a]*dy[a])*v[a],v2=(dx[b]*dx[a]+dy[b]*dy[a])*v[b];
			double t=-1;
			if(v1*(bb-aa)>0&&v2*(aa-bb)>0) 
				t=(bb-aa)/(v1-v2);
			else if(v1*(bb-aa)>0) 
				t=(bb-aa)/v1;
			else if (v2*(aa-bb)>0)
				t=(aa-bb)/v2;
			return t;
		}
	}
}
signed main()
{
	double ans=-1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
		scanf("%d%d%d%d%lf",&x[i],&y[i],&dx[i],&dy[i],&v[i]),v[i]/=sqrt(dx[i]*dx[i]+dy[i]*dy[i]);
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			double now=sol(i,j);
			if(now>=0)
			{
				if(ans<0) 
					ans=now;
				else 
					ans=min(ans,now);
			}
		}
	}
	if(ans<0) 
		puts("No show :(");
	else 
		printf("%0.12lf\n",ans);
	return 0;
}