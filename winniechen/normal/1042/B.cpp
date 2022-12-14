#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 105
int n,f[8];char s[5];
int main()
{
	scanf("%d",&n);memset(f,0x3f,sizeof(f));f[0]=0;
	for(int i=1,x;i<=n;i++)
	{
		scanf("%d%s",&x,s+1);int y=0;
		for(int j=1;j<=strlen(s+1);j++)y|=1<<(s[j]-'A');
		for(int j=0;j<8;j++)f[j|y]=min(f[j]+x,f[j|y]);
	}
	printf("%d\n",f[7]==0x3f3f3f3f?-1:f[7]);
}