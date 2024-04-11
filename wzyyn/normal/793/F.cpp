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
const int N=100005;
vector<int> vc[N];
vector<pii> vQ[N];
int n,m,Q;
int ans[N],t[N*4];
void build(int k,int l,int r){
	t[k]=1ll<<30;
	if (l==r) return;
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
}
void pushdown(int k){
	t[k*2]=min(t[k*2],t[k]);
	t[k*2+1]=min(t[k*2+1],t[k]);
}
void change(int k,int l,int r,int x,int y,int v){
	if (l==x&&r==y){
		t[k]=min(t[k],v);
		return;
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) change(k*2,l,mid,x,y,v);
	else if (x>mid) change(k*2+1,mid+1,r,x,y,v);
	else{
		change(k*2,l,mid,x,mid,v);
		change(k*2+1,mid+1,r,mid+1,y,v);
	}
	t[k]=max(t[k*2],t[k*2+1]);
}
int ask(int k,int l,int r,int p,int v){
	if (l==r) return (t[k]>v?l:-1);
	int mid=(l+r)/2;
	pushdown(k);
	if (p<=l){
		if (t[k*2]>v) return ask(k*2,l,mid,p,v);
		return ask(k*2+1,mid+1,r,p,v);
	}
	int ans=(p<=mid?ask(k*2,l,mid,p,v):-1);
	return ans==-1?ask(k*2+1,mid+1,r,p,v):ans;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		if (x^y) vc[x].PB(y); 
	} 
	scanf("%d",&Q);
	For(i,1,Q){
		int x,y;
		scanf("%d%d",&x,&y);
		vQ[x].PB(pii(y,i));
	}
	build(1,1,n);
	Rep(i,n,1){
		for (auto j:vc[i])
			change(1,1,n,i,j-1,j);
		for (auto j:vQ[i])
			ans[j.se]=ask(1,1,n,i,j.fi);
	}
	For(i,1,Q)
		printf("%d\n",ans[i]);
}