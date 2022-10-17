#include<stdio.h>
#include<iostream>
int n,s,z;
int k[105];
int t[105][105];
int d[105][105];
int v[105][105];
int main()
{
	scanf("%d %d",&n,&s);
	for(int i=0;i<n;i++)
	{
		scanf("%d",k+i);
		for(int j=1;j<=k[i];j++)
		{
			scanf("%d %d",v[i]+j,t[i]+j);
			d[i][j]=v[i][j]*t[i][j];
			d[i][j]+=d[i][j-1];
			t[i][j]+=t[i][j-1];
		}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<i;j++)
			for(int ii=0,jj=0,s=0;ii<k[i]&&jj<k[j];)
			{
				if(t[i][ii+1]<t[j][jj+1])
					ii++;
				else
					jj++;
				int tt=std::max(t[i][ii],t[j][jj]);
				int si=d[i][ii]+(tt-t[i][ii])*v[i][ii+1];
				int sj=d[j][jj]+(tt-t[j][jj])*v[j][jj+1];
				if(si<sj)
				{
					if(s==1)
						z++;
					s=-1;
				}
				else if(si>sj)
				{
					if(s==-1)
						z++;
					s=1;
				}
			}
	printf("%d",z);
	return 0;
}