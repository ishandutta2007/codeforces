#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005,inf=1e9;
struct seg
{
	int k,b;
	seg(){}
	seg(int _k,int _b):k(_k),b(_b){}
	int val(int x){return k*x+b;}
}tr[N<<2];
int n,c,rt,lc[N<<2],rc[N<<2],a[N],b[N],dp[N];
void update(int &k,int l,int r,seg v)
{
	if(!k)
	{
		k=++c;
		tr[k]=v;
		return;
	}
	int mid=l+r>>1,f1=tr[k].val(l)>v.val(l),f2=tr[k].val(mid)>v.val(mid);
	if(f2) swap(tr[k],v);
	if(l==r) return;
	if(f1!=f2) update(lc[k],l,mid,v);
	else update(rc[k],mid+1,r,v);
}
int query(int k,int l,int r,int x)
{
	if(!k) return 1e18;
	if(l==r) return tr[k].val(x);
	int mid=l+r>>1;
	if(x<=mid) return min(tr[k].val(x),query(lc[k],l,mid,x));
	else return min(tr[k].val(x),query(rc[k],mid+1,r,x));
}
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	update(rt,1,inf,seg(b[1],0));
	for(int i=2;i<=n;i++)
	{
		dp[i]=query(rt,1,inf,a[i]);
		update(rt,1,inf,seg(b[i],dp[i]));
	}
	cout<<dp[n]<<endl;
	return 0;
}