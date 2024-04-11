#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005,inf=2000001;
struct seg
{
	int k,b;
	seg(){}
	seg(int _k,int _b):k(_k),b(_b){}
	int val(int x){x-=1000001;return k*x+b;}
}tr[N<<2];
int n,a[N],s[N],sum,ans;
struct lct
{
	int rt,c,lc[N<<2],rc[N<<2];
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
		if(!k) return -1e18;
		if(l==r) return tr[k].val(x);
		int mid=l+r>>1;
		if(x<=mid) return max(tr[k].val(x),query(lc[k],l,mid,x));
		else return max(tr[k].val(x),query(rc[k],mid+1,r,x));
	}
}s1,s2;
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
		sum+=a[i]*i;
	}
	for(int i=n;i>=1;i--)
	{
		s1.update(s1.rt,1,inf,seg(i,-s[i]));
		int x=s1.query(s1.rt,1,inf,a[i]+1000001)-a[i]*i+s[i];
		ans=max(ans,x);
	}
	for(int i=1;i<=n;i++)
	{
		s2.update(s2.rt,1,inf,seg(i,-s[i-1]));
		int x=s2.query(s2.rt,1,inf,a[i]+1000001)-a[i]*i+s[i-1];
		ans=max(ans,x);
	}
	ans+=sum;
	cout<<ans<<endl;
	return 0;
}