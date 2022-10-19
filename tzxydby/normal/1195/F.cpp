#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n,m[N],b[N],t,l[N],ans[N],k;
vector<pair<int,int>>x[N],y[N],v,q[N];
vector<int>a[N];
pair<int,int>operator-(pair<int,int>a,pair<int,int>b){return {a.first-b.first,a.second-b.second};}
void add(int x,int v)
{
	for(int i=x;i<=n;i+=i&(-i))
		b[i]+=v;
}
int sum(int x)
{
	int v=0;
	for(int i=x;i;i-=i&(-i))
		v+=b[i];
	return v;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m[i]);
		x[i].resize(m[i]);
		y[i].resize(m[i]);
		a[i].resize(m[i]);
		for(int j=0;j<m[i];j++)
			scanf("%d%d",&x[i][j].first,&x[i][j].second);
		for(int j=0;j<m[i];j++)
		{
			y[i][j]=x[i][j]-x[i][(j-1+m[i])%m[i]];
			int g=__gcd(abs(y[i][j].first),abs(y[i][j].second));
			y[i][j].first/=g,y[i][j].second/=g;
			v.push_back(y[i][j]);
		}
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	t=v.size();
	for(int i=1;i<=n;i++)
		for(int j=0;j<m[i];j++)
			a[i][j]=lower_bound(v.begin(),v.end(),y[i][j])-v.begin()+1;
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		q[r].emplace_back(l,i);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m[i];j++)
		{
			int x=a[i][j];
			if(l[x])
			{
				add(l[x],-1);
				add(i,1);
				l[x]=i;
			}
			else
			{
				add(i,1);
				l[x]=i;
			}
		}
		for(auto j:q[i])
		{
			int l=j.first,id=j.second;
			ans[id]=sum(i)-sum(l-1);
		}
	}
	for(int i=1;i<=k;i++)
		printf("%d\n",ans[i]);
	return 0;
}