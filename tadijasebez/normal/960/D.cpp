#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
const int L=62;
ll shift[62];
ll sz[62];
int main()
{
	int q,i,t;ll x,k;
	sz[0]=1;
	scanf("%i",&q);
	for(i=1;i<62;i++) sz[i]=sz[i-1]*2;
	while(q--)
	{
		scanf("%i",&t);
		if(t==1)
		{
			scanf("%lld %lld",&x,&k);
			if(x==1){ continue;}
			int lvl=0;
			for(i=1;i<L;i++) if((x>>i)&1) lvl=i;
			//printf("%i %lld\n",lvl,sz[lvl]);
			k%=sz[lvl];if(k<0) k+=sz[lvl];
			shift[lvl]+=k;if(shift[lvl]>=sz[lvl]) shift[lvl]-=sz[lvl];
		}
		else if(t==2)
		{
			scanf("%lld %lld",&x,&k);
			if(x==1){ continue;}
			int lvl=0;
			for(i=1;i<L;i++) if((x>>i)&1) lvl=i;
			for(i=lvl;i<L;i++)
			{
				k%=sz[i];if(k<0) k+=sz[i];
				shift[i]+=k;if(shift[i]>=sz[i]) shift[i]-=sz[i];
				k*=2;
			}
		}
		else
		{
			scanf("%lld",&x);
			if(x==1){ printf("1\n");continue;}
			int lvl=0;
			for(i=1;i<L;i++) if((x>>i)&1) lvl=i;
			ll y=x+shift[lvl];
			if(y>sz[lvl]+sz[lvl]-1) y-=sz[lvl];
			while(y!=1)
			{
				ll ret=y-shift[lvl];
				if(ret<=sz[lvl]-1) ret+=sz[lvl];
				printf("%lld ",ret);
				y/=2;
				lvl--;
			}
			printf("1\n");
		}
	}
	return 0;
}