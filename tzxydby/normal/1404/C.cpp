#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n,m,a[N],b[N],s[N],ans[N],zh[N];
vector<pair<int,int>>q[N];
void add(int x)
{
	x+=2;
	for(int i=x;i<=n+2;i+=i&(-i))
		b[i]++;
}
int sum(int x)
{
	x+=2;
	int v=0;
	for(int i=x;i;i-=i&(-i))
		v+=b[i];
	return v;
}
void add2(int x)
{
	x+=2;
	for(int i=x;i<=n+2;i+=i&(-i))
		zh[i]++;
}
int sum2(int x)
{
	x+=2;
	int v=0;
	for(int i=x;i;i-=i&(-i))
		v+=zh[i];
	return v;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]=i-a[i];
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		q[n-y].emplace_back(x,i);
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]<0||sum(i)<a[i])
		{
			s[i]=n+1;
			continue;
		}
		int l=0,r=i;
		while(r-l>1)
		{
			int m=l+r>>1;
			if(sum(i)-sum(m-1)>=a[i])
				l=m;
			else
				r=m;
		}
		s[i]=l;
		add(s[i]);
	}
	for(int i=1;i<=n;i++)
	{
		add2(s[i]);
		for(auto j:q[i])
			ans[j.second]=sum2(i)-(j.first?sum2(j.first-1):0);
	}
	for(int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
	return 0;
}