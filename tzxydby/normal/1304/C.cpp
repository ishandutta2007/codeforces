#include<bits/stdc++.h>
using namespace std;
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n,m,l,r,tim=0;
		scanf("%d%d",&n,&m);
		l=r=m;
		int can=1;
		for(int i=1;i<=n;i++)
		{
			int t,x,y;
			scanf("%d%d%d",&t,&x,&y);
			l-=t-tim;
			r+=t-tim;
			tim=t;
			if(r<x||l>y)
				can=0;
			l=max(l,x);
			r=min(r,y);
		}
		puts(can?"YES":"NO");
	}
	return 0;
}