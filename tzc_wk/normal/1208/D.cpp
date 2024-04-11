#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],ans[200005];
struct SegTree{
	struct node{
		int l,r,val,lz;
	} s[2000005];
	inline void build(int k,int l,int r){
		s[k].l=l;s[k].r=r;
		if(l==r){
			s[k].val=a[l];
			return;
		}
		int mid=(l+r)>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
		s[k].val=min(s[k<<1].val,s[k<<1|1].val);
	}
	inline void pushdown(int k){
		s[k<<1].val+=s[k].lz;
		s[k<<1].lz+=s[k].lz;
		s[k<<1|1].val+=s[k].lz;
		s[k<<1|1].lz+=s[k].lz;
		s[k].lz=0;
	}
	inline void modify(int k,int l,int r,int x){
		if(l>r)	return;
		if(l<=s[k].l&&s[k].r<=r){
			s[k].val+=x;
			s[k].lz+=x;
			return;
		}
		pushdown(k);
		int mid=(s[k].l+s[k].r)>>1;
		if(r<=mid)		modify(k<<1,l,r,x);
		else if(l>mid)	modify(k<<1|1,l,r,x);
		else			modify(k<<1,l,mid,x),modify(k<<1|1,mid+1,r,x);
		s[k].val=min(s[k<<1].val,s[k<<1|1].val);
	}
	inline int query(int k,int l,int r){
		if(l<=s[k].l&&s[k].r<=r){
			return s[k].val;
		}
		pushdown(k);
		int mid=(s[k].l+s[k].r)>>1;
		if(r<=mid)		return query(k<<1,l,r);
		else if(l>mid)	return query(k<<1|1,l,r);
		else			return min(query(k<<1,l,mid),query(k<<1|1,mid+1,r));
	}
	inline int last_zero(){
		int l=1,r=n,ans;
		while(l<=r){
			int mid=(l+r)>>1;
			if(query(1,mid,n)==0)	ans=mid,l=mid+1;
			else					r=mid-1;
		}
		return ans;
	}
} s;
int cnt=0;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	s.build(1,1,n);
	for(int i=1;i<=n;i++){
		int x=s.last_zero();
		ans[x]=++cnt;
		s.modify(1,x,x,1e12);
		s.modify(1,x+1,n,-cnt);
	}
	for(int i=1;i<=n;i++)	cout<<ans[i]<<" ";
	return 0;
}