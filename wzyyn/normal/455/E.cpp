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
const int M=2000005;
const int N=100005;
int n,Q,nd,a[N],rt[N*4];
int ls[M],rs[M];
pll t[M];
ll S[N];
ll F(pll x,int y){
	return x.fi*y+x.se;
}
void insert(int &k,int l,int r,pll p){
	if (!k) return t[k=++nd]=p,void(0);
	int mid=(l+r)/2;
	if (F(t[k],mid)>F(p,mid)) swap(t[k],p);
	if (F(t[k],l)>F(p,l)) insert(ls[k],l,mid,p);
	if (F(t[k],r)>F(p,r)) insert(rs[k],mid+1,r,p);
} 
ll ask(int k,int l,int r,int p){
	if (!k) return 1ll<<60;
	ll ans=F(t[k],p);
	int mid=(l+r)/2;
	if (p<=mid) ans=min(ans,ask(ls[k],l,mid,p));
	if (p>mid) ans=min(ans,ask(rs[k],mid+1,r,p));
	return ans;
}
void insert(int k,int l,int r,int p,pll v){
	insert(rt[k],0,2*N,pll(v.fi,v.se-N*v.fi));
	if (l==r) return;
	int mid=(l+r)/2;
	if (p<=mid) insert(k*2,l,mid,p,v);
	else insert(k*2+1,mid+1,r,p,v);
}
ll ask(int k,int l,int r,int x,int y,int p){
	//cout<<k<<' '<<l<<' '<<r<<' '<<x<<' '<<y<<endl;
	if (l==x&&r==y)
		return ask(rt[k],0,2*N,p+N);
	int mid=(l+r)/2;
	if (y<=mid) return ask(k*2,l,mid,x,y,p);
	if (x>mid) return ask(k*2+1,mid+1,r,x,y,p);
	return min(ask(k*2,l,mid,x,mid,p),ask(k*2+1,mid+1,r,mid+1,y,p));
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) S[i]=S[i-1]+a[i];
	For(i,1,n) insert(1,1,n,i,pll(a[i],-S[i]+1ll*i*a[i]));
	scanf("%d",&Q);
	while (Q--){
		int k,x;
		scanf("%d%d",&k,&x);
		printf("%lld\n",ask(1,1,n,x-k+1,x,k-x)+S[x]);
	}
}
/*
S[y]-S[x]+(k+x-y)*a[x]
*/