#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int t,v[100],vc;
long long f[100],g[100][2],n;
int main()
{
	int i;
	f[1]=1,f[2]=2;
	for(int i=3;i<90;i++)
		f[i]=f[i-1]+f[i-2];
	for(scanf("%d",&t);t--;)
	{
		vc=0;
		cin>>n;
		for(int i=89;i;i--)
			if(n>=f[i])
				n-=f[i],v[++vc]=i;
		reverse(v+1,v+1+vc);
		g[0][0]=1;
		g[0][1]=0;
		for(int i=1;i<=vc;i++)
		{
			g[i][0]=g[i-1][0]+g[i-1][1];
			g[i][1]=g[i-1][0]*((v[i]-v[i-1]-1)/2)+g[i-1][1]*((v[i]-v[i-1])/2);
		}
		cout<<g[vc][0]+g[vc][1]<<endl;
	}
	return 0;
}