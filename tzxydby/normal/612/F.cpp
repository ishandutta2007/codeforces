#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n,s,a[N],r[N],dp[N],p[N],t[N],ans1=INT_MAX,ans2;
vector<int>v,d[N],ans;
int mn(int x,int y)
{
	int k=abs(x-y);
	return min(k,n-k);
}
int pre(int x)
{
	int l=a[x];
	return d[l][(r[x]+d[l].size()-1)%d[l].size()];
}
int suf(int x)
{
	int l=a[x];
	return d[l][(r[x]+1)%d[l].size()];
}
int l0(int x,int y)
{
	if(x>y)
		return x-y;
	else
		return x+(n-y);
}
int r0(int x,int y)
{
	if(x<y)
		return y-x;
	else
		return y+(n-x);
}
void pmn(int x,int y)
{
	int dl=l0(x,y),dr=r0(x,y);
	if(dl<dr)
		ans.push_back(-dl);
	else
		ans.push_back(dr);
}
void pl0(int x,int y)
{
	int z=suf(y),w=y;
	while(1)
	{
		ans.push_back(-((z-w+n)%n));
		if(z==x)
			break;
		z=suf(z);
		w=suf(w);
	}
}
void pr0(int x,int y)
{
	int z=pre(y),w=y;
	while(1)
	{
		ans.push_back((w-z+n)%n);
		if(z==x)
			break;
		z=pre(z);
		w=pre(w);
	}
}
void dis(int f,int v,int x)
{
	int l=a[x],pr=pre(x),sf=suf(x);
	if(pr==x)
	{
		int v1=mn(f,x)+v;
		if(v1<dp[x])
		{
			dp[x]=v1;
			p[x]=f;
			t[x]=1;
		}
	}
	int v1=v+mn(f,pr),v2=v+mn(f,sf);
	v1+=l0(pr,x);
	if(v1<dp[x])
	{
		dp[x]=v1;
		p[x]=f;
		t[x]=1;
	}
	v2+=r0(sf,x);
	if(v2<dp[x])
	{
		dp[x]=v2;
		p[x]=f;
		t[x]=2;
	}
}
int main()
{
	scanf("%d%d",&n,&s);
	s--;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		v.push_back(a[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=0;i<n;i++)
	{
		a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
		r[i]=d[a[i]].size();
		d[a[i]].push_back(i);
	}
	for(int i=0;i<n;i++)
		dp[i]=INT_MAX;
	for(auto i:d[1])
		dis(s,0,i);
	for(int i=1;i<=v.size();i++)
	{
		for(auto u:d[i])
			for(auto v:d[i+1])
				dis(u,dp[u],v);
	}
	for(auto i:d[v.size()])
	{
		if(dp[i]<ans1)
		{
			ans1=dp[i];
			ans2=i;
		}
	}
	printf("%d\n",ans1);
	for(int i=0;i<v.size();i++)
	{
		if(d[a[ans2]].size()==1)
		{
			pmn(p[ans2],ans2);
			ans2=p[ans2];
			continue;
		}
		if(t[ans2]==1)
		{
			int pr=pre(ans2);
			pl0(pr,ans2);
			pmn(p[ans2],pr);
			ans2=p[ans2];
		}
		else
		{
			int sf=suf(ans2);
			pr0(sf,ans2);
			pmn(p[ans2],sf);
			ans2=p[ans2];
		}
	}
	reverse(ans.begin(),ans.end());
	for(auto i:ans)
	{
		if(i>=0)
			printf("+%d\n",i%n);
		else
			printf("%d\n",i%n);
	}
	return 0;
}