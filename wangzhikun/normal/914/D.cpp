//  Created by Zhikun on 2018/10/3.
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int a[500050],gv[2000020];
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
void build(int id,int l,int r){
int mid = ((l+r)/2);
	if(r==l){
		gv[id] = a[l];
		return;
	}
	build(id*2, l, mid);
	build(id*2+1,1+mid,r);
	gv[id] = gcd(gv[id*2],gv[id*2+1]);
}
void cng(int id,int l,int r,int po,int x){
	int mid = ((l+r)/2);
	if(l == r){
		gv[id] = x;
		return;
	}
	if(po<=(l+r)/2)
		cng(id*2,l,mid,po,x);
	else
		cng(id*2+1,1+mid,r,po,x);
	gv[id] = gcd(gv[id*2],gv[id*2+1]);
}
int query(int id,int l,int r,int ql,int qr,int v){
	int mid = ((l+r)/2);
	if(l == ql && r == qr){
		if(gv[id]%v == 0)return 0;
		if(l == r)return 1;
		if(gv[id*2]%v == 0) return query(id*2+1,1+mid,r,1+mid,r,v);
		if(gv[id*2+1]%v == 0) return query(id*2,l,mid,l,mid,v);
		return 2;
	}
	if(ql>mid)return query(id*2+1,1+mid,r,ql,qr,v);
	if(qr<=mid)return query(id*2,l,mid,ql,qr,v);
	int ans = query(id*2+1,1+mid,r,1+mid,qr,v);
	if(ans>=2)return ans;
	return ans+query(id*2,l,mid,ql,mid,v);
}
ll upd;
int n,q,op,p,v,ccl,ccr,ccs;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	build(1,1,n);
	cin>>q;
	while(q--){
		cin>>op;
		if(op == 1){
			cin>>ccl>>ccr>>ccs;
			if(query(1,1,n,ccl,ccr,ccs)<2){
			cout<<"YES"<<endl;
			}else{
			cout<<"NO"<<endl;
			}
		}else{
			cin>>p>>v;
			cng(1,1,n,p,v);
		}
	}
	return 0;
}