#include<bits/stdc++.h>
using namespace std;
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
int q,x,occ[400100],mn[1600100];
void pushup(int x){
	if(occ[mn[lson]]<=occ[mn[rson]])mn[x]=mn[lson];
	else mn[x]=mn[rson];
}
void build(int x,int l,int r){
	if(l==r){mn[x]=l;return;}
	build(lson,l,mid),build(rson,mid+1,r),pushup(x);
}
void modify(int x,int l,int r,int P){
	if(l>P||r<P)return;
	if(l==r){occ[l]++;return;}
	modify(lson,l,mid,P),modify(rson,mid+1,r,P),pushup(x);
}
int main(){
	scanf("%d%d",&q,&x),build(1,1,x);
	for(int i=1,t1;i<=q;i++){
		scanf("%d",&t1),t1=t1%x+1,modify(1,1,x,t1);
		printf("%d\n",(mn[1]-1+x)%x+occ[mn[1]]*x);
	}
	return 0;
}