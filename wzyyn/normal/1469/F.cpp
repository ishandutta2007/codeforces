#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;

const int N=200005;
int n,k,a[N];
ll sz[N*8],s[N*8],tg[N*8];
void build(int k,int l,int r){
	sz[k]=r-l+1;
	if (l==r) return;
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
}
void add(int k,int v){
	//cout<<k<<' '<<v<<endl;
	tg[k]+=v;
	s[k]+=1ll*sz[k]*v;
}
void pushdown(int k){
	if (!tg[k]) return;
	add(k*2,tg[k]);
	add(k*2+1,tg[k]);
	tg[k]=0;
}
void change(int k,int l,int r,int x,int y,int v){
	if (x<=l&&r<=y)
		return add(k,v);
	pushdown(k);
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,y,v);
	if (y>mid) change(k*2+1,mid+1,r,x,y,v);
	s[k]=s[k*2]+s[k*2+1];
	//cout<<k<<' '<<s[k]<<' '<<s[k*2]<<' '<<s[k*2+1]<<' '<<x<<' '<<y<<' '<<l<<' '<<r<<endl;
}
int query(int k,int l,int r,int p){
	if (l==r) return tg[k];
	int mid=(l+r)/2;
	if (p<=mid) return query(k*2,l,mid,p)+tg[k];
	else return query(k*2+1,mid+1,r,p)+tg[k];
}
int find(int k,int l,int r,int v){
	if (l==r) return l;
	pushdown(k);
	int mid=(l+r)/2;
	if (s[k*2]>=v) return find(k*2,l,mid,v);
	return find(k*2+1,mid+1,r,v-s[k*2]);
}
int main(){
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+n+1,greater<int>());
	build(1,0,2*N);
	change(1,0,2*N,0,0,1);
	ll rem=1;
	int re=1<<30,p=0;
	For(i,1,n){
		for (;!query(1,0,2*N,p);++p);
		change(1,0,2*N,p,p,-1); --rem;
		int l1=(a[i]-1)/2,l2=a[i]-1-l1;
		change(1,0,2*N,p+2,p+l1+1,1); rem+=l1;
		change(1,0,2*N,p+2,p+l2+1,1); rem+=l2;
		if (rem>=k) re=min(re,find(1,0,2*N,k));
		//cout<<re<<' '<<find(1,0,2*N,k)<<' '<<s[1]<<endl;
	}
	if (re==1<<30) re=-1;
	cout<<re<<endl;
}