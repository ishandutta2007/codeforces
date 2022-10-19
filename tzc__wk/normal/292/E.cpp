#include <bits/stdc++.h>
using namespace std;
int n,m,a[100005],b[100005];
struct node{
	int l,r,lz;
} s[400020];
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;s[k].lz=0;
	if(l==r)	return;
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
void pushdown(int k){
	if(!s[k].lz)	return;
	s[k<<1].lz=s[k].lz;
	s[k<<1|1].lz=s[k<<1].r-s[k<<1].l+1+s[k].lz;
	s[k].lz=0;
}
void change(int k,int l,int r,int L,int R){
//	cout<<"We are now at ["<<s[k].l<<","<<s[k].r<<"].";
//	cout<<" We gonna replace b["<<l<<","<<r<<"]";
//	cout<<" with a["<<L<<","<<R<<"]."<<endl;
	if(l<=s[k].l&&s[k].r<=r){
		s[k].lz=L;
		return;
	}
	pushdown(k);
	int mid=(s[k].l+s[k].r)>>1;
	if(r<=mid)		change(k<<1,l,r,L,R);
	else if(l>mid)	change(k<<1|1,l,r,L,R);
	else			change(k<<1,l,mid,L,L+(mid-l)),
					change(k<<1|1,mid+1,r,R-(r-mid-1),R);
}
int query(int k,int ind){
	if(s[k].l==s[k].r){
		if(!s[k].lz)	return b[ind];
		else			return a[s[k].lz];
	}
	pushdown(k);
	int mid=(s[k].l+s[k].r)>>1;
	if(ind<=mid)	return query(k<<1,ind);
	else			return query(k<<1|1,ind);
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<=n;i++)	cin>>b[i];
	build(1,1,n);
	while(m--){
		int type;
		cin>>type;
		if(type==1){
			int x,y,k;cin>>x>>y>>k;
			change(1,y,y+k-1,x,x+k-1);
		}
		else{
			int i;cin>>i;
			cout<<query(1,i)<<endl;
		}
	}
}