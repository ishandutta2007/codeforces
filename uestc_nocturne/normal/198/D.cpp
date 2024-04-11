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
const int V=53;
int sqr(int x){return x*x;}
int a[V][V][V][V],te[V][V][V];
int n,i,j,k,nx,ny,nz,dr,d,ct;
int main()
{
	a[1][1][1][1]=1;
	a[2][1][1][1]=1;
	a[2][1][2][1]=4;
	a[2][2][1][1]=2;
	a[2][2][2][1]=3;
	a[2][1][1][2]=8;
	a[2][1][2][2]=5;
	a[2][2][1][2]=7;
	a[2][2][2][2]=6;
	for(n=2;n<=50;n++)
	{
		//printf("%d\n",n);
		d=sqr(n);
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		for(k=1;k<=n;k++)
		a[n+1][i][j][k+1]=a[n][i][j][k]+d;
		nx=1;ny=n;nz=1;dr=1;ct=1;
		if(n%2==0)
		{
			while(1)
			{
				if(ny<1)break;
				a[n+1][nx][ny][nz]=ct;
				ct++;
				if(nx+dr<1||nx+dr>n)
				dr*=-1,ny--;
				else nx+=dr;
			}
		}
		else
		{
			while(1)
			{
				if(ny==n-1)break;
				a[n+1][nx][ny][nz]=ct;
				ct++;
				if(nx+dr<1||nx+dr>n)
				dr*=-1,ny--;
				else nx+=dr;
			}
			while(1)
			{
				if(nx<1)break;
				a[n+1][nx][ny][nz]=ct;
				ct++;
				if(ny+dr<1||ny+dr>n-1)
				dr*=-1,nx--;
				else ny+=dr;
			}
		}
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		for(k=1;k<=n+1;k++)
		te[n+1-j][i][k]=a[n+1][i][j][k];
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		for(k=1;k<=n+1;k++)
		a[n+1][i][j][k]=te[i][j][k];
		ct=n*n*n+d+1;
		nx=n+1;ny=1;nz=n+1;dr=-1;
		while(1)
		{
			if(ny>n+1)break;
			a[n+1][nx][ny][nz]=ct;
			ct++;
			if(nz+dr<1||nz+dr>n+1)
			dr*=-1,ny++;
			else nz+=dr;
		}
		ny--;nx--;
		while(1)
		{
			if(nx<1)break;
			a[n+1][nx][ny][nz]=ct;
			ct++;
			if(nz+dr<1||nz+dr>n+1)
			dr*=-1,nx--;
			else nz+=dr;
		}
		for(i=1;i<=n+1;i++)
		for(j=1;j<=n+1;j++)
		for(k=1;k<=n+1;k++)
		te[i][k][j]=a[n+1][i][j][k];
		for(i=1;i<=n+1;i++)
		for(j=1;j<=n+1;j++)
		for(k=1;k<=n+1;k++)
		a[n+1][i][j][k]=te[i][j][k];
	}
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				for(k=1;k<=n;k++)
				{
					if(k!=1)printf(" ");
					printf("%d",a[n][j][k][i]);
				}puts("");
			}puts("");
		}
	}
}