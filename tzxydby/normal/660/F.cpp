#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005,inf=4e12+1;
struct seg
{
	int k,b;
	seg(){}
	seg(int _k,int _b):k(_k),b(_b){}
	int val(int x){x-=2e12+1;return k*x+b;}
}tr[N<<5];
int n,c,rt,lc[N<<5],rc[N<<5],a[N],s1[N],s2[N],ans;
void update(int &k,int l,int r,seg v)
{
	if(!k)
	{
		k=++c;
		tr[k]=v;
		return;
	}
	int mid=l+r>>1,f1=tr[k].val(l)<v.val(l),f2=tr[k].val(mid)<v.val(mid);
	if(f2) swap(tr[k],v);
	if(l==r) return;
	if(f1!=f2) update(lc[k],l,mid,v);
	else update(rc[k],mid+1,r,v);
}
int query(int k,int l,int r,int x)
{
	if(!k) return -1e15;
	if(l==r) return tr[k].val(x);
	int mid=l+r>>1;
	if(x<=mid) return max(tr[k].val(x),query(lc[k],l,mid,x));
	else return max(tr[k].val(x),query(rc[k],mid+1,r,x));
}
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s1[i]=s1[i-1]+a[i];
		s2[i]=s2[i-1]+a[i]*i;
	}
	update(rt,1,inf,seg(0,0));
	for(int i=1;i<=n;i++)
	{
		int x=query(rt,1,inf,s1[i]+2e12+1);
		ans=max(ans,x+s2[i]);
		update(rt,1,inf,seg(-i,i*s1[i]-s2[i]));
	}
	cout<<ans<<endl;
	return 0;
}