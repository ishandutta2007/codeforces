#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
char s[15];
int cnt=0;
bool ask(int x,int y)
{
	cnt++;
	printf("? %d %d\n",x,y);
	fflush(stdout);
	scanf("%s",s);
	if(s[0]=='x')return 1;
	else return 0;
}
int main()
{
	while(1)
	{
		scanf("%s",s);cnt=0;
		if(s[0]=='e'||s[0]=='m')return 0;
		int i;
		for(i=1;i<=1000000000;i<<=1)if(ask(i,i<<1))break;
		int l=i,r=i<<1,ans=-1;
		while(l<=r)
		{
			int m=(l+r)>>1;
			if(ask(m,i<<1))l=m+1;
			else r=m-1,ans=m;
		}
		if(ans!=-1)printf("! %d\n",ans);
		else 
		{
			if(ask(i<<1,i))printf("! %d\n",i);
			else printf("! %d\n",i<<1);
		}
	fflush(stdout);
	}
}