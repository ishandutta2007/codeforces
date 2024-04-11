#include <bits/stdc++.h>
using namespace std;
#define int long long
int N,n=1,w,l,a[1000005],ans[1000005],sum;
struct segTree{
	struct node{
		int l,r,val;
	} s[4000005];
	inline void clear(int k,int l,int r){
		s[k].val=0;
		if(l==r){
			return;
		}
		int mid=(l+r)>>1;
		clear(k<<1,l,mid);
		clear(k<<1|1,mid+1,r);
	}
	inline void build(int k,int l,int r){
		s[k].l=l;s[k].r=r;s[k].val=0;
		if(l==r){
			s[k].val=a[l];
			return;
		}
		int mid=(l+r)>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
		s[k].val=max(s[k<<1].val,s[k<<1|1].val);
	}
	inline int query(int k,int l,int r){
		if(l<=s[k].l&&s[k].r<=r){
			return s[k].val;
		}
		int mid=(s[k].l+s[k].r)>>1;
		if(r<=mid)		return query(k<<1,l,r);
		else if(l>mid)	return query(k<<1|1,l,r);
		else			return max(query(k<<1,l,mid),query(k<<1|1,mid+1,r));
	}
} st;
signed main(){
	cin>>N>>w;
	for(int i=1;i<=N;i++){
		st.clear(1,1,n);
		cin>>n;
//		memset(a,0,sizeof(a));
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		st.build(1,1,n);
		int mx=max(0ll,st.s[1].val);sum+=mx;
//		cout<<"mx="<<mx<<endl;
		for(int j=1;j<=min(n+2,w);j++){
			int cur=-LLONG_MAX;
			int l=j+n-w,r=j;
			if(l<1)	cur=0,l=1;
			if(r>n)	cur=0,r=n;
			cur=max(cur,st.query(1,l,r));
			ans[j]+=(cur-mx);
		}
		for(int j=w;j>=max(w-(n+1),n+3);j--){
			int cur=-LLONG_MAX;
			int l=j-w+n,r=j;
			if(l<1)	cur=0,l=1;
			if(r>n)	cur=0,r=n;
			cur=max(cur,st.query(1,l,r));
			ans[j]+=(cur-mx);
		}
	}
	for(int i=1;i<=w;i++){
		cout<<sum+ans[i]<<" ";
	}
	return 0;
}
/*
3 3
3 2 4 8
2 2 5
2 6 3
*/