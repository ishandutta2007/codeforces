#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 300005
int n,pri[N<<1],cnt,vis[N<<1],b[3];
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=500000;i++)if(!vis[i])
	{
		pri[++cnt]=i;
		for(int j=i+i;j<=500000;j+=i)vis[j]=1;
	}
	for(int i=1,x;i<=n;i++)scanf("%d",&x),b[x]++;
	int now=0;
	for(int i=1;i<=cnt;i++)
	{
		while(b[2]&&now+2<=pri[i])now+=2,b[2]--,printf("%d ",2);
		while(b[1]&&now+1<=pri[i])now++,b[1]--,printf("%d ",1);
		if(now!=pri[i])
		{
			if(b[2])now+=2,b[2]--,printf("%d ",2);
			else break;
		}
	}puts("");
}