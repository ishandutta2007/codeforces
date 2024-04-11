#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	char ch=getchar();
	while(!isdigit(ch))
	{
		ch=getchar();
	}
	int ans=0;
	while(isdigit(ch))
	{
		ans=ans*10+ch-48;
		ch=getchar();
	}
	return ans;
}
struct Island
{
	int l,r;
	bool operator < (const Island &x) const
	{
		return l<x.l;
	}
};
struct Bridge
{
	int length;
	int idx;
	bool operator < (const Bridge &x) const
	{
		return length<x.length;
	}
};
struct Jian
{
	int l,r;
	int idx;
	bool operator < (const Jian &x) const
	{
		return r>x.r;
	}
};
Island a[200005];
Bridge b[200005];
Jian c[200005];
int ans[200005];
bool cmp(Jian x,Jian y)
{
	return x.l<y.l;
}
signed main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		a[i].l=read();
		a[i].r=read();
	}
	for(int i=1;i<=m;i++)
	{
		b[i].length=read();
		b[i].idx=i;
	}
	for(int i=1;i<n;i++)
	{
		c[i].l=a[i+1].l-a[i].r;
		c[i].r=a[i+1].r-a[i].l;
		c[i].idx=i;
	}
	sort(c+1,c+n,cmp);
	sort(b+1,b+m+1);
	priority_queue<Jian> p;
	int j=1;
	for(int i=1;i<=m;i++)
	{
		while(b[i].length>=c[j].l&&j<n)
		{
			p.push(c[j]);
			j++;
		}
		if(p.empty())
		{
			continue;
		}
		if(p.top().r<b[i].length)
		{
			cout<<"No\n";
			return 0;
		}
		Jian t=p.top();
		p.pop();
		ans[t.idx]=b[i].idx;
	}
	for(int i=1;i<n;i++)
	{
		if(ans[i]==0)
		{
			cout<<"No\n";
			return 0;
		}
	}
	cout<<"Yes\n";
	for(int i=1;i<n;i++)
	{
		printf("%lld ",ans[i]);
	}
	cout<<"\n";
	return 0;
}