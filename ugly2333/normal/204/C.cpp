//CF 204C
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
char a[222222],b[222222],c;
LL p[222222];
int main()
{
	int n,i,j,k;
	LL s;
	double ans;
	cin>>n;
	cin>>a>>b;
	s=0;
	for(i=1;i<=n;i=i+1)
		s+=(LL)i*i;
	ans=0;
	for(k=1;k<=26;k=k+1)
	{
		c=char(k+64);
		p[0]=0;
		if(a[0]==c)
			p[0]=1;
		for(i=1;i<n;i=i+1)
		{
			if(a[i]==c)
				p[i]=p[i-1]+i+1;
			else
				p[i]=p[i-1];
		}
		for(i=0;i<n;i=i+1)
		{
			if(b[i]==c){
				ans+=(double)p[i]*(n-i)/s;
			}
		}
		p[0]=0;
		if(b[0]==c)
			p[0]=1;
		for(i=1;i<n;i=i+1)
		{
			if(b[i]==c)
				p[i]=p[i-1]+i+1;
			else
				p[i]=p[i-1];
		}
		for(i=1;i<n;i=i+1)
		{
			if(a[i]==c){
				ans+=(double)p[i-1]*(n-i)/s;
			}
		}
	}
	printf("%.9f",ans);
	return 0;
}