#include<bits/stdc++.h>
using namespace std;
long long sum[410000];
int maxx[410000];
int a[410000];
void pushup(int p){
	sum[p]=sum[2*p]+sum[2*p+1];
	maxx[p]=max(maxx[2*p],maxx[2*p+1]);
}
void build(int l,int r,int p){
	if(l==r){
		maxx[p]=sum[p]=a[l];
		return;
	}
	build(l,(l+r)/2,2*p);
	build((l+r)/2+1,r,2*p+1);
	pushup(p);
}
long long query1(int l,int r,int p,int x,int y){
	if(l>=x&&r<=y)return sum[p];
	long long ans=0;
	int md=(l+r)/2;
	if(md>=x)ans=query1(l,md,2*p,x,y);
	if(md+1<=y)ans+=query1(md+1,r,2*p+1,x,y);
	return ans;
}
void query2(int l,int r,int p,int x,int y,int q){
	if(maxx[p]<q)return;
	if(l==r){
		maxx[p]%=q;
		sum[p]=maxx[p];
		return;
	}
	int md=(l+r)/2;
	if(x<=md) query2(l,md,2*p,x,y,q);
	if(md+1<=y) query2(md+1,r,2*p+1,x,y,q);
	pushup(p);
}
void query3(int l,int r,int p,int x,int y){
	if(l==r){
		sum[p]=maxx[p]=y;
		return;
	}
	int md=(l+r)/2;
	if(md>=x)query3(l,md,2*p,x,y);
	else query3(md+1,r,2*p+1,x,y);
	pushup(p);
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	build(1,n,1);
	while(m--){
		int op;
		scanf("%d",&op);
		if(op==1){
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%lld\n",query1(1,n,1,l,r));
		}
		if(op==2){
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			query2(1,n,1,l,r,x);
		}
		if(op==3){
			int k,x;
			scanf("%d%d",&k,&x);
			query3(1,n,1,k,x);
		}
	}
	return 0;
}