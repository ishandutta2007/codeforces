#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1) 
ll a[100100],mn[400100],mx[400100];
void build(int x,int l,int r){
	if(l==r){mn[x]=mx[x]=a[l];return;}
	build(lson,l,mid),build(rson,mid+1,r);
	mn[x]=min(mn[lson],mn[rson]);
	mx[x]=max(mx[lson],mx[rson]);
}
ll qmn(int x,int l,int r,int L,int R){
	if(l>R||r<L)return 0x3f3f3f3f3f3f3f3f;
	if(L<=l&&r<=R)return mn[x];
	return min(qmn(lson,l,mid,L,R),qmn(rson,mid+1,r,L,R));
}
ll qmx(int x,int l,int r,int L,int R){
	if(l>R||r<L)return -0x3f3f3f3f3f3f3f3f;
	if(L<=l&&r<=R)return mx[x];
	return max(qmx(lson,l,mid,L,R),qmx(rson,mid+1,r,L,R));
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=n;i++)scanf("%d",&x),a[i]+=x;
	for(int i=1,x;i<=n;i++)scanf("%d",&x),a[i]-=x;
	for(int i=1;i<=n;i++)a[i]+=a[i-1];
//	for(int i=1;i<=n;i++)printf("%lld ",a[i]);puts("");
	build(1,1,n);
	for(int i=1,l,r;i<=m;i++){
		scanf("%d%d",&l,&r);
		if(a[l-1]!=a[r]){puts("-1");continue;}
		if(qmx(1,1,n,l,r)>a[l-1]){puts("-1");continue;}
		printf("%lld\n",a[l-1]-qmn(1,1,n,l,r));
	}
	return 0;
}