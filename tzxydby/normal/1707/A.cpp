#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a[N],q,p[N],t,v,h,z;
int chk(int x)
{
	t=h=0;
	for(int i=1;i<=n;i++)
		p[i]=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=q)
		{
			p[i]=1;
			t++;
		}
	}
	if(t>=x)
		return 1;
	v=x-t;
	for(int i=n;i>=1;i--)
	{
		if(a[i]<=q)
			continue;
		v--;
		if(!v)
		{
			h=i;
			break;
		}
	}
	z=q;
	for(int i=h;i<=n;i++)
	{
		if(a[i]<=z)
			continue;
		if(!z)
			return 0;
		z--;
	}
	for(int i=1;i<h;i++)
		p[i]=(a[i]<=q);
	for(int i=h;i<=n;i++)
		p[i]=1;
	return 1;
}
void sol()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int l=0,r=n+1;
	while(r-l>1)
	{
		int md=l+r>>1;
		if(chk(md))
			l=md;
		else
			r=md;
	}
	chk(l);
	for(int i=1;i<=n;i++)
		printf("%d",p[i]);
	puts("");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();	
	return 0;
}