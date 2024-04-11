#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,k,t[N],a[N],b[N],le[N],ri[N],f[N];
vector<int>tr[N<<2],v;
int rt(int x){return x==f[x]?x:f[x]=rt(f[x]);}
void upd1(int k,int l,int r,int x,int v)
{
	if(tr[k].size())
	{
		for(auto u:tr[k])
		{
			u=rt(u);
			f[u]=v;
			le[v]=min(le[v],le[u]);
			ri[v]=max(ri[v],ri[u]);
		}
		tr[k].assign(1,v);
	}
	if(l==r)
		return;
	int mid=l+r>>1;
	if(x<=mid) upd1(k<<1,l,mid,x,v);
	else upd1(k<<1|1,mid+1,r,x,v);
}
void upd2(int k,int l,int r,int a,int b,int v)
{
	if(l==a&&r==b)
	{
		tr[k].push_back(v);
		return;
	}
	int mid=l+r>>1;
	if(b<=mid) upd2(k<<1,l,mid,a,b,v);
	else if(a>mid) upd2(k<<1|1,mid+1,r,a,b,v);
	else upd2(k<<1,l,mid,a,mid,v),upd2(k<<1|1,mid+1,r,mid+1,b,v);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&t[i],&a[i],&b[i]);
		if(t[i]==1)
		{
			v.push_back(a[i]);
			v.push_back(b[i]);
		}
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	m=v.size();
	for(int i=1;i<=n;i++)
	{
		if(t[i]==1)
		{
			a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
			b[i]=lower_bound(v.begin(),v.end(),b[i])-v.begin()+1;
			k++;
			f[k]=k,le[k]=a[i],ri[k]=b[i];
			upd1(1,1,m,a[i],k);
			upd1(1,1,m,b[i],k);
			if(b[i]-a[i]>1)
				upd2(1,1,m,a[i]+1,b[i]-1,k);
		}
		else
		{
			a[i]=rt(a[i]),b[i]=rt(b[i]);
			if(a[i]==b[i]||(le[b[i]]<le[a[i]]&&le[a[i]]<ri[b[i]])||(le[b[i]]<ri[a[i]]&&ri[a[i]]<ri[b[i]]))
				puts("YES");
			else
				puts("NO");
		}
	}
	return 0;
}