#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
using namespace std;

struct node{
	int l,r,dl,dr,d;
	long long sum;
};
node add(node a,node b){
	node c;
	c.l=a.l;
	c.r=b.r;
	c.d=a.d+b.d;
	if (a.r>b.l){
		c.dl=a.dl;
		c.dr=b.dr;
		c.sum=a.sum+b.sum;
	}
	else{
		c.dl=(a.dl==a.d?a.d+b.dl:a.dl);
		c.dr=(b.dr==b.d?b.d+a.dr:b.dr);
		c.sum=a.sum+b.sum+1ll*a.dr*b.dl;
	}
	return c; 
}
const int N=200005;
int a[N],n,Q;
node t[N*4];

void build(int k,int l,int r){
	if (l==r){
		t[k].l=t[k].r=a[l];
		t[k].dl=t[k].dr=t[k].d=t[k].sum=1;
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	t[k]=add(t[k*2],t[k*2+1]);
}
void change(int k,int l,int r,int x,int v){
	if (l==r){
		t[k].l=t[k].r=v;
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,v);
	else change(k*2+1,mid+1,r,x,v);
	
	t[k]=add(t[k*2],t[k*2+1]);
}
node ask(int k,int l,int r,int x,int y){
	if (x<=l&&r<=y) return t[k];
	int mid=(l+r)/2;
	if (y<=mid) return ask(k*2,l,mid,x,y);
	if (x>mid) return ask(k*2+1,mid+1,r,x,y);
	return add(ask(k*2,l,mid,x,mid),ask(k*2+1,mid+1,r,mid+1,y));
}
int main(){
	scanf("%d%d",&n,&Q);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,n);
	for (int i=1;i<=Q;i++){
		int tp,x,y;
		scanf("%d%d%d",&tp,&x,&y);
		if (tp==1) change(1,1,n,x,y);
		else printf("%lld\n",ask(1,1,n,x,y).sum);
	}
}