#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long
const int N=55;
ll r[N],c[N];
char Base[N][N];
int main()
{
	int n,m,i,j,k;
	scanf("%i %i",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%s",Base[i]);
		for(j=0;j<m;j++)
		{
			if(Base[i][j]=='#')
			{
				r[i]+=((ll)1)<<j;
				c[j]+=((ll)1)<<i;
			}
		}
	}
	bool bad=0;
	for(k=0;k<m;k++)
	{
		ll x=0;
		for(i=0;i<n;i++)
		{
			if((r[i]>>k)&1)
			{
				if(!x) x=r[i];
				if(r[i]!=x) bad=1;
			}
		}
	}
	for(k=0;k<n;k++)
	{
		ll x=0;
		for(j=0;j<m;j++)
		{
			if((c[j]>>k)&1)
			{
				if(!x) x=c[j];
				if(c[j]!=x) bad=1;
			}
		}
	}
	if(bad) printf("No\n");
	else printf("Yes\n");
	return 0;
}