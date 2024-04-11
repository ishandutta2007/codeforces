#include<bits/stdc++.h>
using namespace std;
int nf,ne,ns,n;
double rf,re,rs,df,de;
int next_bit(int x)
{
	int b=x&(-x);
	int t=x+b;
	int c=x^t;
	int m=(c>>2)/b;
	return t|m;
}
double x[21],dp[21][21];
double sum(double X,bool f)
{
	if(f)
	{
		double ret=2*rf;
		for(int i=0;i<ns;i++)
			ret+=max(0.0,min(X+rf,x[i]+rs)-max(X-rf,x[i]-rs));
		return ret*df;
	}
	double ret=2*re;
	for(int i=0;i<ns;i++)
		ret+=max(0.0,min(X+re,x[i]+rs)-max(X-re,x[i]-rs));
	return ret*de;
}
double w[29][2];
double work(int s)
{
	for(int i=0,j=0;i<n;i++)
	{
		if(s&(1<<i))
			x[j++]=i/2;
	}
	for(int i=0;i<n;i++)
	{
		if(s&(1<<i)) 
			continue;
		w[i][0]=sum(i/2,0);
		w[i][1]=sum(i/2,1);
	}
	for(int i=0;i<=nf;i++)
		for(int j=0;j<=ne;j++)
			dp[i][j]=0;
	for(int k=0;k<n;k++)
	{
		if(s&(1<<k))
			continue;
		for(int i=nf;i>=0;i--)
		{
			for(int j=ne;j>=0;j--)
			{
				if(i) dp[i][j]=max(dp[i-1][j]+w[k][1],dp[i][j]);
				if(j) dp[i][j]=max(dp[i][j-1]+w[k][0],dp[i][j]);
			}
		}
	}
	return dp[nf][ne];
}
int main()
{
	scanf("%d%d%d",&nf,&ne,&ns);
	scanf("%lf%lf%lf",&rf,&re,&rs);
	scanf("%lf%lf",&df,&de);
	rf=sqrt(rf*rf-1);
	re=sqrt(re*re-1);
	rs=sqrt(rs*rs-1);
	n=ns+nf+ne;
	int f=(1<<ns)-1;
	int e=f<<(n-ns);
	double ret=0,cnt=0;
	for(int i=f;i<=e;i=next_bit(i))
	{
		ret=max(ret,work(i));
		if(f==0) 
			break;
	}
	printf("%.11f\n",ret);
	return 0;
}