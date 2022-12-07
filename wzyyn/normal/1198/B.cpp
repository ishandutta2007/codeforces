#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=200005;
int n,Q,a[N],mx[N*4];
void build(int k,int l,int r){
	if (l==r){
		mx[k]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
}
void pushdown(int k){
	mx[k*2]=max(mx[k*2],mx[k]);
	mx[k*2+1]=max(mx[k*2+1],mx[k]);
	mx[k]=0;
}
void change(int k,int l,int r,int p,int v){
	if (l==r){
		mx[k]=v;
		return;
	}
	int mid=(l+r)/2;
	pushdown(k);
	if (p<=mid) change(k*2,l,mid,p,v);
	else change(k*2+1,mid+1,r,p,v);
}
void getans(int k,int l,int r){
	if (l==r){
		printf("%d ",mx[k]);
		return;
	}
	int mid=(l+r)/2;
	pushdown(k);
	getans(k*2,l,mid);
	getans(k*2+1,mid+1,r);
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	build(1,1,n);
	scanf("%d",&Q);
	while (Q--){
		int tp,x,y;
		scanf("%d%d",&tp,&x);
		if (tp==1){
			scanf("%d",&y);
			change(1,1,n,x,y);
		}
		else
			mx[1]=max(mx[1],x);
	}
	getans(1,1,n);
}