#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int arr[N],s[N],t[N],dfn[N],tr[N<<3],tag[N<<3],n,cnt;
vector<int>e[N];
void dfs(int u)
{
	cnt++;
	s[u]=cnt,dfn[cnt]=u;
	for(auto i:e[u])
		dfs(i);
	t[u]=cnt;
}
void build(int k,int l,int r)
{
	if(l==r)
	{
		tr[k]=arr[dfn[l]];
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	tr[k]=tr[k<<1]+tr[k<<1|1];
}
void pushdown(int k,int l,int r)
{
	int mid=l+r>>1;
	tr[k<<1]=mid-l+1-tr[k<<1];
	tr[k<<1|1]=r-mid-tr[k<<1|1];
	tag[k<<1]^=1;
	tag[k<<1|1]^=1;
	tag[k]=0;
}
int query(int k,int l,int r,int a,int b)
{
	if(tag[k])
		pushdown(k,l,r);
	if(l==a&&r==b)
		return tr[k];
	int mid=l+r>>1;
	if(b<=mid) return query(k<<1,l,mid,a,b);
	else if(a>mid) return query(k<<1|1,mid+1,r,a,b); 
	else return query(k<<1,l,mid,a,mid)+query(k<<1|1,mid+1,r,mid+1,b);
}
void update(int k,int l,int r,int a,int b)
{
	if(l==a&&r==b)
	{
		tr[k]=r-l+1-tr[k];
		tag[k]^=1;
		return;
	}
	if(tag[k])
		pushdown(k,l,r);
	int mid=l+r>>1;
	if(b<=mid) update(k<<1,l,mid,a,b);
	else if(a>mid) update(k<<1|1,mid+1,r,a,b);
	else update(k<<1,l,mid,a,mid),update(k<<1|1,mid+1,r,mid+1,b);
	tr[k]=tr[k<<1]+tr[k<<1|1];
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		int x;
		cin>>x;
		e[x].push_back(i);
	}
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	dfs(1);
	build(1,1,n);
	int q;
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		string ty;
		int x;
		cin>>ty>>x;
		if(ty=="get")
			cout<<query(1,1,n,s[x],t[x])<<endl;	
		else
			update(1,1,n,s[x],t[x]);
	}
	return 0;
}