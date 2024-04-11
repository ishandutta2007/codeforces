#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=1050;
char s[N];
int main()
{
	int n,m,i,j,xl=N,xr=0,yl=N,yr=0;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(j=1;j<=m;j++)
		{
			if(s[j]=='B')
			{
				xl=min(xl,i);
				xr=max(xr,i);
				yl=min(yl,j);
				yr=max(yr,j);
			}
		}
	}
	printf("%i %i\n",xl+xr>>1,yl+yr>>1);
	return 0;
}