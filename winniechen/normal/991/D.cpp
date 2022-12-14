#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
using namespace std;
#define N 105
int f[N][4],cur[N],n;char s[N];
int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<=n;i++)cur[i]=(s[i]!='0');
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)cur[i]|=((s[i]!='0')<<1);
	for(int i=2;i<=n+1;i++)
	{
		for(int S=0;S<4;S++)f[i][0]=max(f[i-1][S],f[i][0]);if(i==n+1)break;
		for(int S=0;S<4;S++)
		{
			if(S&cur[i])continue;
			int u=S|cur[i];
			for(int s=0;s<4;s++)
			{
				if(s&cur[i-1])continue;
				int t=s|cur[i-1];
				if(t==3)continue;
				if((t==1||t==0||t==2)&&(!u))f[i][3]=max(f[i-1][s]+1,f[i][3]);
				if(t==0)
				{
					if(u==1)f[i][2]=max(f[i-1][0]+1,f[i][2]);
					if(u==2)f[i][1]=max(f[i-1][0]+1,f[i][1]);
				}
			}
		}
	}
	printf("%d\n",f[n+1][0]);
}