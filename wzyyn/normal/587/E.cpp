#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=200005;
int n,Q,a[N],b[N],v[N*4];
void change(int k,int v){
	for (;k<=n;k+=k&(-k)) b[k]^=v;
}
int ask(int k){
	int ans=0;
	for (;k;k-=k&(-k)) ans^=b[k];
	return ans;
}
struct node{
	int a[30],n;
	node(){
		memset(a,0,sizeof(a));
		n=0;
	}
	void insert(int x){
		Rep(i,29,0)
			if (x&(1<<i))
				if (a[i]) x^=a[i];
				else{
					a[i]=x;
					++n;
					break;
				}
	}
}t[N*4];
node merge(node a,node b){
	For(i,0,29) if (b.a[i]) a.insert(b.a[i]);
	return a;
}
void build(int k,int l,int r){
	if (l==r){
		t[k]=node();
		t[k].insert(v[k]=a[l]^a[l-1]);
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	t[k]=merge(t[k*2],t[k*2+1]);
}
void change(int k,int l,int r,int p,int v){
	if (l==r){
		t[k]=node();
		t[k].insert(::v[k]^=v);
		return;
	}
	int mid=(l+r)/2;
	if (p<=mid) change(k*2,l,mid,p,v);
	else change(k*2+1,mid+1,r,p,v);
	t[k]=merge(t[k*2],t[k*2+1]);
}
node ask(int k,int l,int r,int x,int y){
	if (l==x&&r==y) return t[k];
	int mid=(l+r)/2;
	if (y<=mid) return ask(k*2,l,mid,x,y);
	if (x>mid) return ask(k*2+1,mid+1,r,x,y);
	return merge(ask(k*2,l,mid,x,mid),ask(k*2+1,mid+1,r,mid+1,y));
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) change(i,a[i]^a[i-1]);
	build(1,1,n);
	while (Q--){
		int tp,x,y,v;
		scanf("%d%d%d",&tp,&x,&y);
		if (tp==1){
			scanf("%d",&v);
			change(1,1,n,x,v);
			if (y!=n) change(1,1,n,y+1,v);
			change(x,v); change(y+1,v);
		}
		else{
			node tmp; tmp=node();
			if (x!=y) tmp=ask(1,1,n,x+1,y);
			tmp.insert(ask(x));
			printf("%d\n",1<<tmp.n);
		}
	}
}