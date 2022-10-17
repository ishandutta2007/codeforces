#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
double e[120][120],w[120],db;
int a[120][120],d[120],n,m;
int x[100020],y[100020],z[100020];
int f[120];
int F(int x)
{
	return f[x]!=x?f[x]=F(f[x]):x;
}
int U(int x,int y)
{
	f[F(x)]=F(y);
}
int main()
{
	cin>>n>>m;
	fr(i,n)
		f[i]=i;
	for(int i=0;i<m;i++)
	{
		cin>>x[i]>>y[i]>>z[i];
		x[i]--,y[i]--;
		a[x[i]][y[i]]++;
		a[y[i]][x[i]]++;
		d[x[i]]++;
		d[y[i]]++;
		U(x[i],y[i]);
	}
	if(F(0)!=F(n-1))
	{
		for(int i=0;i<=m;i++)
			printf("0.00000000000000000000000000000000000000\n");
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			e[i][j]=a[i][j];
		e[i][i]=-d[i];
	}
	for(int i=0;i<n;i++)
	{
		e[0][i]=0;
		e[n-1][i]=0;
	}
	e[0][0]=1;
	e[n-1][n-1]=1;
	e[0][n]=0;
	e[n-1][n]=1;
	for(int i=0;i<n;i++)
	{
		int p=i;
		for(int j=i;j<n;j++)
			if(fabs(e[j][i])>fabs(e[p][i]))
				p=j;
		if(fabs(e[i][i])<1e-6)
		{
			continue;
		}
		for(int j=0;j<=n;j++)
			swap(e[p][j],e[i][j]);
		for(int j=0;j<n;j++)
			if(j!=i)
			{
				double u=e[j][i]/e[i][i];
				for(int k=0;k<=n;k++)
					e[j][k]-=e[i][k]*u;
			}
	}
	for(int i=0;i<n;i++)
		w[i]=e[i][n]/e[i][i];
	db=1e30;
	for(int i=0;i<m;i++)
	{
		db=min(db,(double)z[i]/fabs(w[x[i]]-w[y[i]]));
	}
	for(int i=0;i<n;i++)
	{
		w[i]*=db;
	}
	double s=0;
	for(int i=0;i<m;i++)
		if(x[i]==0)
			s+=w[y[i]]-w[x[i]];
		else if(y[i]==0)
			s+=w[x[i]]-w[y[i]];
	printf("%.9f\n",s);
	for(int i=0;i<m;i++)
		printf("%.9f\n",w[y[i]]-w[x[i]]);
	return 0;
}