#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
int n,m,x,y,s,e,q,v,d[30];
double t[30][30],a[485][485],u;
int main()
{
	cin>>n>>m>>s>>e,--s,--e,q=n*n;
	fr(i,m)
		cin>>x>>y,d[--x]++,d[--y]++,t[x][y]=t[y][x]=1;
	fr(i,n)
		cin>>t[i][i];
	fr(i,n)
		fr(j,n)
			if(i!=j)
				t[i][j]*=(1-t[i][i])/d[i];
	fr(i,n)
		fr(j,n)
		{
			a[i*n+j][i*n+j]=-1;
			if(i!=j)
				fr(k,n)
					fr(l,n)
						a[k*n+l][i*n+j]+=t[i][k]*t[j][l];
		}
	a[s*n+e][q]=-1;
	fr(i,q)
	{
		for(int j=v=i;j<q;j++)
			if(fabs(a[j][i])>fabs(a[v][i]))
				v=j;
		fr(k,q+1)
			swap(a[v][k],a[i][k]);
		u=a[i][i];
		fr(k,q+1)
			a[i][k]/=u;
		fr(j,q)
			if(u=a[j][i],i!=j)
				fr(k,q+1)
					a[j][k]-=u*a[i][k];
	}
	fr(i,n)
		printf("%.9f ",a[i*n+i][q]);
}