#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<map>
using namespace std;
string s;
map<string,int>g;
int n,m,z,zt,l,a[500020],p[500020][15],f[32780][110];
void mnn(int &x,int y)
{
	if(x>y)
		x=y;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		cin>>s,g[s]=i;
	scanf("%d",&m),z=n*(n-1)/2+1;
	for(int _=0;_<m;_++)
	{
		scanf("%d",&l);
		for(int i=0;i<l;i++)
			cin>>s,a[i]=g.count(s)?g[s]:-1;
		for(int i=0;i<n;i++)
			p[l][i]=l;
		for(int i=l;i--;)
		{
			for(int j=0;j<n;j++)
				p[i][j]=p[i+1][j];
			if(~a[i])
				p[i][a[i]]=i;
		}
		memset(f,0x3f,sizeof f);
		f[0][0]=-1;
		for(int i=0;i<1<<n;i++)
			for(int j=0;j<z;j++)
				if(f[i][j]<l)
					for(int k=0;k<n;k++)
						if(~i>>k&1)
							mnn(f[i+(1<<k)][j+__builtin_popcount(i>>k)],p[f[i][j]+1][k]);
		for(int i=0;i<z;i++)
			if(f[(1<<n)-1][i]<l)
				z=i,zt=_;
	}
	z=n*(n-1)/2+1-z;
	if(z)
	{
		printf("%d\n[:",zt+1);
		for(;z--;)
			printf("|");
		puts(":]");
	}
	else
		puts("Brand new problem!"); 
}