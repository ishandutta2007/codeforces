#include<bits/stdc++.h>
#define maxn 2005
using namespace std;
const int inf = 1000000000;
int gcd(int a,int b)
{
	if(!b)return a;
	return gcd(b,a%b);
}
int n;
int a[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	int ans=inf;
	for(int l=1;l<=n;++l)
	{
		int g=a[l];
		for(int r=l;r<=n;++r)
		{
			g=gcd(g,a[r]);
			if(g==1)
			{
				ans=min(ans,r-l);
				break;
			}
		}
	}
	int tot=0;
	for(int i=1;i<=n;++i)if(a[i]==1)tot++;
	if(!tot)tot++;
	ans+=n-tot;
	if(ans>=inf)puts("-1");
	else printf("%d\n",ans);
	return 0;
}