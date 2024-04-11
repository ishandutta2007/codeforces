/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=120;
int a[V][V],r[V],c[V],sr[V],sc[V],n,m;
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		scanf("%d",&a[i][j]);
		for(int i=0;i<n;i++)
		{
			sr[i]=0;
			for(int j=0;j<m;j++)
			sr[i]+=a[i][j];
		}
		for(int j=0;j<m;j++)
		{
			sc[j]=0;
			for(int i=0;i<n;i++)
			sc[j]+=a[i][j];
		}
		memset(r,0,sizeof(r));
		memset(c,0,sizeof(c));
		while(1)
		{
			int id=-1;
			for(int i=0;i<n;i++)
			if(sr[i]<0){id=i;break;}
			if(id!=-1)
			{
                sr[id]*=-1;r[id]^=1;
                for(int j=0;j<m;j++)
                sc[j]-=2*a[id][j],a[id][j]*=-1;
                continue;
			}
			for(int j=0;j<m;j++)
			if(sc[j]<0){id=j;break;}
			if(id!=-1)
			{
                sc[id]*=-1;c[id]^=1;
                for(int i=0;i<n;i++)
                sr[i]-=2*a[i][id],a[i][id]*=-1;
                continue;
			}
			break;
		}
		int rn=0,cn=0;
		for(int i=0;i<n;i++)rn+=r[i];
		for(int j=0;j<m;j++)cn+=c[j];
		printf("%d",rn);
		for(int i=0;i<n;i++)
		if(r[i])printf(" %d",i+1);puts("");
		printf("%d",cn);
		for(int j=0;j<m;j++)
		if(c[j])printf(" %d",j+1);puts("");
	}
}