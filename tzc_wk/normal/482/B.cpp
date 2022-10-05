#include <bits/stdc++.h>
using namespace std;
int n,m;
struct segTree{
	struct node{
		int l,r,val,lz;
	} s[400005];
	void build(int k,int l,int r){
		s[k].l=l;s[k].r=r;
		if(l==r)	return;
		int mid=(l+r)>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
	}
	void pushdown(int k){
		s[k<<1].val|=s[k].lz;
		s[k<<1].lz|=s[k].lz;
		s[k<<1|1].val|=s[k].lz;
		s[k<<1|1].lz|=s[k].lz;
		s[k].lz=0;
	}
	void change(int k,int l,int r,int x){
		if(l<=s[k].l&&s[k].r<=r){
			s[k].val|=x;
			s[k].lz|=x;
			return;
		}
		pushdown(k);
		int mid=(s[k].l+s[k].r)>>1;
		if(r<=mid)		change(k<<1,l,r,x);
		else if(l>mid)	change(k<<1|1,l,r,x);
		else			change(k<<1,l,mid,x),change(k<<1|1,mid+1,r,x);
		s[k].val=s[k<<1].val&s[k<<1|1].val;
	}
	int query(int k,int l,int r){
		if(l<=s[k].l&&s[k].r<=r){
			return s[k].val;
		}
		pushdown(k);
		int mid=(s[k].l+s[k].r)>>1;
		if(r<=mid)		return query(k<<1,l,r);
		else if(l>mid)	return query(k<<1|1,l,r);
		else			return query(k<<1,l,mid)&query(k<<1|1,mid+1,r);
	}
} st;
int l[100005],r[100005],x[100005];
int main(){
	cin>>n>>m;
	st.build(1,1,n);
	for(int i=1;i<=m;i++){
		cin>>l[i]>>r[i]>>x[i];
		st.change(1,l[i],r[i],x[i]);
	}
	for(int i=1;i<=m;i++)
		if(st.query(1,l[i],r[i])!=x[i])
			return puts("NO"),0;
	puts("YES");
	for(int i=1;i<=n;i++)
		cout<<st.query(1,i,i)<<" ";
}