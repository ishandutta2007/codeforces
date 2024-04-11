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
const int V=1200;
const int P=1000000007 ;
char s1[V],s2[V];
bool can[V];
int n,i,j,K;
int main()
{
	while(~scanf("%s%s",s1,s2))
	{
		scanf("%d",&K);
		n=strlen(s1);
		memset(can,0,sizeof(can));
		for(i=0;i<n;i++)
		{
			bool sm=true;
			for(j=0;j<n;j++)
			if(s1[(i+j)%n]!=s2[j])
			{sm=false;break;}
			if(sm)can[i]=1;
		}
		if(K==0){printf("%d\n",can[0]);continue;}
		int x=0,y=1;
		for(i=0;i<K-1;i++)
		{
			int tx=(LL)(n-1)*y%P;
			int ty=(x+(LL)(n-2)*y)%P;
			x=tx,y=ty;
		//printf("%d %d\n",x,y);
		}
		int ans=(LL)can[0]*x%P;
		for(i=1;i<n;i++)ans=(ans+(LL)can[i]*y)%P;
		cout<<ans<<endl;
	}
}