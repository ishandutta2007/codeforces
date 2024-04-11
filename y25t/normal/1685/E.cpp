#include<bits/stdc++.h>
#define N 200005

int n,q,a[N],b[N];

struct node{
	int sum,mn,pos;
	node(){
		sum=mn=pos=0;
	}
}t[N<<2];
node operator + (node x,node y){
	if(!x.pos||!y.pos)
		return x.pos?x:y;
	if(x.sum+y.mn<x.mn)
		x.mn=x.sum+y.mn,x.pos=y.pos;
	x.sum+=y.sum;
	return x;
}
inline void ins(int p,int L,int R,int x){
	if(L==R)
		return t[p].sum=t[p].mn=(a[x]>n+1)-(a[x]<n+1),t[p].pos=L,void();
	int mid=(L+R)>>1;
	x<=mid?ins(p<<1,L,mid,x):ins(p<<1|1,mid+1,R,x);
	t[p]=t[p<<1]+t[p<<1|1];
}
inline node sch(int p,int L,int R,int l,int r){
	if(L>r||R<l||l>r)
		return node();
	if(l<=L&&R<=r)
		return t[p];
	int mid=(L+R)>>1;
	return sch(p<<1,L,mid,l,r)+sch(p<<1|1,mid+1,R,l,r);
}

long long A,B;
inline int dis(int i,int j){
	return (b[j]-b[i]+n+n+1)%(n+n+1);
}
inline void upd(int i,int d){
	if(i<=n+1)
		A+=d*(dis(i==1?n+1:i-1,i)+dis(i,i==n+1?1:i+1));
	if(i>=n+1)
		B+=d*(dis(i==n+1?n+n+1:i-1,i)+dis(i,i==n+n+1?n+1:i+1));
}

int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n+n+1;i++)
		scanf("%d",&a[i]),b[a[i]]=i;
	for(int i=1;i<=n+n+1;i++)
		ins(1,1,n+n+1,i),upd(i,1);
	while(q--){
		int u,v;
		scanf("%d%d",&u,&v);
		std::swap(a[u],a[v]);
		ins(1,1,n+n+1,u),ins(1,1,n+n+1,v);
		upd(a[u],-1),b[a[u]]=u,upd(a[u],1);
		upd(a[v],-1),b[a[v]]=v,upd(a[v],1);
		node x=sch(1,1,n+n+1,b[n+1],n+n+1)+sch(1,1,n+n+1,1,b[n+1]-1);
		if(x.mn)
			printf("%d\n",x.pos==n+n+1?0:x.pos);
		else if(A!=2*(n+n+1))
			printf("%d\n",b[n+1]==n+n+1?0:b[n+1]);
		else if(B!=2*(n+n+1))
			printf("%d\n",b[n+1]-1);
		else
			puts("-1");
	}
}