#include<bits/stdc++.h>
using namespace std;
struct segtree{
	int num[410000];
	int lazy[410000];
	void push_down(int l,int r,int p){
		if(lazy[p]){
			lazy[2*p]^=1;
			lazy[2*p+1]^=1;
			int mid=(l+r)/2;
			num[2*p]=mid-l+1-num[2*p];
			num[2*p+1]=r-mid-num[2*p+1];
			lazy[p]=0;
		}
	}
	void rev(int x,int y,int l,int r,int p){
		if((x<=l)&&(y>=r)){
			lazy[p]^=1;
			num[p]=r-l+1-num[p];
			return;
		}
		int mid=(l+r)/2;
		push_down(l,r,p);
		if(x<=mid) rev(x,y,l,mid,2*p);
		if(y>=mid+1) rev(x,y,mid+1,r,2*p+1);
		num[p]=num[2*p]+num[2*p+1];
	}
	int getnum(int x,int y,int l,int r,int p){
		if((x<=l)&&(y>=r)) return num[p];
		int mid=(l+r)/2;
		push_down(l,r,p);
		int ans=0;
		if(x<=mid) ans+=getnum(x,y,l,mid,2*p);
		if(y>=mid+1) ans+=getnum(x,y,mid+1,r,2*p+1);
		return ans;
	}
}seg[20];
int n,m;
int a[110000];
void build(int l,int r,int p){
	for(int i=0;i<20;i++) seg[i].lazy[p]=0;
	if(l==r){
		for(int i=0;i<20;i++) seg[i].num[p]=(a[l]>>i)&1;
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,2*p);
	build(mid+1,r,2*p+1);
	for(int i=0;i<20;i++) seg[i].num[p]=seg[i].num[2*p]+seg[i].num[2*p+1];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	build(1,n,1);
	for(int i=1;i<=m;i++){
		int t,l,r;
		scanf("%d%d%d",&t,&l,&r);
		if(t==1){
			long long ans=0;
			for(int i=0;i<20;i++) ans+=(1ll*seg[i].getnum(l,r,1,n,1))<<i;
			printf("%I64d\n",ans);
		}
		else{
			int x;
			scanf("%d",&x);
			for(int i=0;i<20;i++)
			 if((x>>i)&1) seg[i].rev(l,r,1,n,1);
		}
	}
	return 0;
}