#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,q;
ll a[1005][1005];
int main()
{
	scanf("%d",&n);
	ll v=1;
	for(int i=0;i<=2*n-2;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(j&1)a[j][i-j]=v;
			else a[j][i-j]=0;
		}
		v*=2;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		  printf("%lld ",a[i][j]);
		printf("\n");
	}
	fflush(stdout);
	scanf("%d",&q);
	while(q--)
	{
		ll k;
		scanf("%lld",&k);
		ll v=1;
		int x=0,y=0;
		printf("%d %d\n",x+1,y+1);
		for(int i=1;i<=2*n-2;i++)
		{
			v*=2;
			if(v&k)
			{
				if(a[x+1][y])x++;
				else y++;
			}
			else
			{
				if(a[x+1][y])y++;
				else x++;
			}
			printf("%d %d\n",x+1,y+1);
		}
		fflush(stdout);
	}
	return 0;
}