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
const int N=300005;
const int M=10000005;
int n,Q,m,l[N],r[N],p[N],q[N];
int rt[N],nd,ls[M],rs[M],v[M];
vector<pii> vec[N];
void build(int &k,int l,int r){
	k=++nd; v[k]=-1;
	if (l==r) return;
	int mid=(l+r)/2;
	build(ls[k],l,mid);
	build(rs[k],mid+1,r);
}
void change(int &nk,int k,int l,int r,pii p){
	nk=++nd; v[nk]=v[k];
	ls[nk]=ls[k]; rs[nk]=rs[k];
	if (l==r){
		v[nk]=max(v[nk],p.se);
		return;
	}
	int mid=(l+r)/2;
	if (p.fi<=mid) change(ls[nk],ls[k],l,mid,p);
	else change(rs[nk],rs[k],mid+1,r,p);
	v[nk]=min(v[ls[nk]],v[rs[nk]]);
}
int ask(int k,int l,int r,int x,int y){
	if (l==x&&r==y) return v[k];
	int mid=(l+r)/2;
	if (y<=mid) return ask(ls[k],l,mid,x,y);
	if (x>mid) return ask(rs[k],mid+1,r,x,y);
	return min(ask(ls[k],l,mid,x,mid),ask(rs[k],mid+1,r,mid+1,y));
}
int main(){
	scanf("%d%d%d",&n,&Q,&m);
	For(i,1,m) scanf("%d%d%d",&l[i],&r[i],&p[i]);
	For(i,1,m) q[++*q]=r[i];
	sort(q+1,q+*q+1);
	*q=unique(q+1,q+*q+1)-q-1;
	For(i,1,m){
		int pos=lower_bound(q+1,q+*q+1,r[i])-q;
		vec[pos].PB(pii(p[i],l[i]));
	}
	build(rt[0],1,n);
	For(i,1,*q){
		rt[i]=rt[i-1];
		for (auto j:vec[i]) change(rt[i],rt[i],1,n,j);
	}
	while (Q--){
		int a,b,x,y;
		scanf("%d%d%d%d",&a,&b,&x,&y);
		y=upper_bound(q+1,q+*q+1,y)-q-1;
		puts(ask(rt[y],1,n,a,b)>=x?"yes":"no");
		fflush(stdout); 
	}
}