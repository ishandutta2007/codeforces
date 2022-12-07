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
int n,Q,a[N];

int mn[N*4],mx[N*4],sz[N*4];
ll s[N*4];
void pushdown(int k){
	if (mn[k]>=mx[k*2]){
		mx[k*2]=mn[k*2]=mn[k];
		s[k*2]=1ll*sz[k*2]*mn[k];
	}
	if (mn[k]>=mx[k*2+1]){
		mx[k*2+1]=mn[k*2+1]=mn[k];
		s[k*2+1]=1ll*sz[k*2+1]*mn[k];
	}
}
void pushup(int k){
	mn[k]=min(mn[k*2],mn[k*2+1]);
	mx[k]=max(mx[k*2],mx[k*2+1]);
	s[k]=s[k*2]+s[k*2+1];
}
void build(int k,int l,int r){
	sz[k]=r-l+1;
	if (l==r){
		mn[k]=mx[k]=s[k]=a[l];
		return;	
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	pushup(k);
}
void change(int k,int l,int r,int x,int y,int v){
	if (x<=l&&r<=y){
		if (v<=mn[k]) return;
		if (v>=mx[k]){
			mn[k]=mx[k]=v;
			s[k]=1ll*sz[k]*v;
			return;
		}
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,y,v);
	if (y>mid) change(k*2+1,mid+1,r,x,y,v);
	pushup(k); 
}
int query(int k,int l,int r,int x,int &y){
	//cout<<k<<' '<<l<<' '<<r<<' '<<x<<' '<<y<<endl;
	if (x<=l){
		if (s[k]<=y){
			y-=s[k];
			return r-l+1;
		}
		if (l==r||y<mn[k])
			return 0;
	}
	pushdown(k);
	int mid=(l+r)/2,ans=0;
	if (x<=mid) ans+=query(k*2,l,mid,x,y);
	return ans+query(k*2+1,mid+1,r,x,y);
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n) scanf("%d",&a[i]);
	build(1,1,n);
	while (Q--){
		int tp,x,y;
		scanf("%d%d%d",&tp,&x,&y);
		if (tp==1) change(1,1,n,1,x,y);
		else printf("%d\n",query(1,1,n,x,y));
	}
}