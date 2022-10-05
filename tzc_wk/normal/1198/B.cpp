#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
struct node{
	int l,r,lazy;
} s[800020];
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;s[k].lazy=0;
	if(l==r){
		s[k].lazy=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
void change(int x){
	s[1].lazy=max(s[1].lazy,x);
}
void pushdown(int k){
	s[k<<1].lazy=max(s[k<<1].lazy,s[k].lazy);
	s[k<<1|1].lazy=max(s[k<<1|1].lazy,s[k].lazy);
	s[k].lazy=0;
}
void modify(int k,int ind,int x){
	if(s[k].l==s[k].r){
		s[k].lazy=x;
		return;
	}
	pushdown(k);
	int mid=(s[k].l+s[k].r)>>1;
	if(ind<=mid)	modify(k<<1,ind,x);
	else			modify(k<<1|1,ind,x);
}
int ask(int k,int ind){
	if(s[k].l==s[k].r){
		return s[k].lazy;
	}
	pushdown(k);
	int mid=(s[k].l+s[k].r)>>1;
	if(ind<=mid)	return ask(k<<1,ind);
	else			return ask(k<<1|1,ind);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	build(1,1,n);
	int T;cin>>T;
	while(T--){
		int type;cin>>type;
		if(type==1){
			int p,x;cin>>p>>x;
			modify(1,p,x);
		}
		else{
			int x;cin>>x;
			change(x);
		}
	}
	for(int i=1;i<=n;i++)	cout<<ask(1,i)<<" ";
}//