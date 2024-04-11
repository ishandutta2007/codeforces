#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
char a[500005],b[500005],s[1000005],ss[1500005];
int n,m,z[1500005],pre[500005],suf[500005],c2[1500005];
ll c[1500005],ans;
void add(int p,ll v)
{
	p++;
	while(p<=m+1)
	{
		c[p]+=v;
		c2[p]++;
		p+=p^(p&(p-1));
	}
}
pair<ll,int>sum(int p)
{
	p++;
	ll ans1=0;
	int ans2=0;
	while(p)
	{
		ans1+=c[p];
		ans2+=c2[p];
		p&=p-1;
	}
	return make_pair(ans1,ans2);
}
pair<ll,int>sum(int l,int r)
{
	l=max(1,l);
	r=min(m,r);
	if(l>r)return make_pair(0,0);
	pair<ll,int>s1=sum(r);
	pair<ll,int>s2=sum(l-1);
	return make_pair(s1.first-s2.first,s1.second-s2.second);
}
void Z(char*s,int n)
{
	z[1]=n;
	int l=1,r=1;
	for(int i=2;i<=n;i++)
	{
		if(r<i)
		{
			l=r=i;
			while(r<=n&&s[r]==s[r-l+1])r++;
			z[i]=r-l;
			r--;
		}
		else
		{
			if(z[i-l+1]<r-i+1)z[i]=z[i-l+1];
			else
			{
				l=i;
				while(r<=n&&s[r]==s[r-l+1])r++;
				z[i]=r-l;
				r--;
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s%s%s",a+1,b+1,s+1);
	for(int i=1;i<=m;i++)ss[i]=s[i];
	for(int i=1;i<=n;i++)ss[i+m]=a[i];
	Z(ss,n+m);
	for(int i=1;i<=n;i++)pre[i]=min(m-1,z[i+m]);
	for(int i=1;i<=m;i++)ss[i]=s[m-i+1];
	for(int i=1;i<=n;i++)ss[i+m]=b[n-i+1];
	Z(ss,n+m);
	for(int i=1;i<=n;i++)suf[n-i+1]=min(m-1,z[i+m]);
	for(int i=n;i>=1;i--)
	{
		add(suf[i],suf[i]);
		if(pre[i]==0)continue;
		pair<ll,int>res=sum(m-pre[i],m);
		ans+=res.first+(pre[i]-m+1ll)*res.second;
	}
	memset(c,0,sizeof(c));
	memset(c2,0,sizeof(c2));
	for(int i=n;i>=1;i--)
	{
		if(i+m-2<=n)add(suf[i+m-1],suf[i+m-1]);
		if(pre[i]==0)continue;
		pair<ll,int>res=sum(m-pre[i],m);
		ans-=res.first+(pre[i]-m+1ll)*res.second;
	}
	printf("%lld\n",ans);
	return 0;
}