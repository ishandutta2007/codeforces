#include<bits/stdc++.h>
using namespace std;
const int N=600005;
int n,m,s[N],ans[N];
void modify(int x,int v)
{
	while(x<=n)
	{
		s[x]+=v;
		x=(x|(x-1))+1;
	}
}
int findsum(int x)
{
	int v=0;
	while(x>0)
	{
		v+=s[x];
		x&=x-1;
	}
	return v;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		s[i]=0;
	for(int i=1;i<=n;i++)
		modify(i,1);
	for(int i=1;i<=n;i++)
		ans[i]=0;
	while(m--)
	{
		int from,to,win;
		scanf("%d%d%d",&from,&to,&win);
		int dec=findsum(from-1);
		int add=findsum(to);
		while(add>dec)
		{
			int l=from,r=to;
			while(l<r)
			{
				int mid=(l+r)>>1;
				if(findsum(mid)==dec)
					l=mid+1;
				else
					r=mid;
			}
			ans[l]=win;
			modify(l,-1);
			add--; 
		}
		ans[win]=0;
		modify(win,1);
	}
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}