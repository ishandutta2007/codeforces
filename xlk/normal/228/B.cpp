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
int na,nb,ma,mb,x,y,z;
int a[60][60];
int b[60][60];
int C(int x,int y)
{
	int z=0;
	for(int i=max(0,-x);i<min(na,nb-x);i++)
		for(int j=max(0,-y);j<min(ma,mb-y);j++)
			z+=a[i][j]*b[i+x][j+y];
	return z;
}
int main()
{
	cin>>na>>ma;
	fr(i,na)
		fr(j,ma)
			scanf("%1d",a[i]+j);
	cin>>nb>>mb;
	fr(i,nb)
		fr(j,mb)
			scanf("%1d",b[i]+j);
	for(int ii=-na;ii<nb;ii++)
		for(int jj=-ma;jj<mb;jj++)
		{
			if(ii==-1&&jj==-1)
				ii=-1;
			int t=C(ii,jj);
			if(z<t)
			{
				z=t;
				x=ii,y=jj;
			}
		}
	cout<<x<<' ' <<y << endl;
	return 0;
}