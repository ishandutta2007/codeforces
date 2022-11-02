#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
char col[]={"ROYGBV"},ch[120];
int nu[120],i,j,ans;
int main()
{
	while(~scanf("%s",ch))
	{
		memset(nu,0,sizeof(nu));
		for(i=0;i<6;i++)
		{
			for(j=0;j<6;j++)
			{
				if(ch[i]==col[j])
				nu[j]++;
			}
		}
		sort(nu,nu+6);
		if(nu[5]>=5)ans=1;
		else if(nu[5]==4)ans=2;
		else if(nu[5]==3)
		{
			if(nu[4]==3)ans=2;
			else if(nu[4]==2)ans=3;
			else ans=5;
		}
		else if(nu[5]==2)
		{
			if(nu[4]==2)
			{
				if(nu[3]==2)ans=6;
				else ans=8;
			}
			else ans=15;
		}
		else ans=30;
		printf("%d\n",ans);
	}
}