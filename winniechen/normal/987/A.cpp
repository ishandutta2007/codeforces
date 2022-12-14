#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <cstdlib>
using namespace std;
char s[10];int n,vis[10];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		if(s[0]=='r')vis[1]=1;
		else if(s[0]=='p')vis[2]=1;
		else if(s[0]=='y')vis[3]=1;
		else if(s[0]=='o')vis[4]=1;
		else if(s[0]=='b')vis[5]=1;
		else vis[6]=1;
	}
	printf("%d\n",6-n);
	for(int i=1;i<=6;i++)
	{
		if(vis[i])continue;
		if(i==1)printf("Reality\n");
		else if(i==2)printf("Power\n");
		else if(i==3)printf("Mind\n");
		else if(i==4)printf("Soul\n");
		else if(i==5)printf("Space\n");
		else printf("Time\n");
	}
	return 0;
}