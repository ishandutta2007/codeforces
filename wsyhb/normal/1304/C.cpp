#include<stdio.h>
#include<bits/stdc++.h>
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
using namespace std;
typedef long long ll;
const int N=100+5;
int t[N],l[N],r[N];
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		ll x=m,y=m;
		for(int i=1;i<=n;i++) scanf("%d%d%d",t+i,l+i,r+i);
		bool f=true;
		for(int i=1;i<=n;i++)
		{
			x-=t[i]-t[i-1];
			y+=t[i]-t[i-1];
			if(x<=r[i]&&y>=l[i])
			{
				x=max(x,l[i]);
				y=min(y,r[i]);
			}
			else
			{
				f=false;
				break;
			}
		}
		if(f) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}