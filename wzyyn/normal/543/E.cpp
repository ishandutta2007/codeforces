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
struct node{
	ull mx:18,ls:23,rs:23;
}t[N*40];
int n,m,nd,rt[N];
pii v[N];
#define F(p) max(l==mid?t[p].ls:t[t[p].ls].mx,mid+1==r?t[p].rs:t[t[p].rs].mx)
int upd(int k,int l,int r,int x,int y){
	if (l==r) return k+1;
	int nk=++nd; t[nk]=t[k];
	if (x<=l&&r<=y) return ++t[nk].mx,nk;
	int mid=(l+r)/2,tg=t[k].mx-F(k);
	if (x<=mid) t[nk].ls=upd(t[k].ls,l,mid,x,y);
	if (y>mid) t[nk].rs=upd(t[k].rs,mid+1,r,x,y);
	t[nk].mx=F(nk)+tg;
	return nk;
}
int ask(int k,int l,int r,int x,int y){
	if (x<=l&&r<=y) return (l==r?k:t[k].mx);
	int mid=(l+r)/2,tg=t[k].mx-F(k);
	if (y<=mid) return ask(t[k].ls,l,mid,x,y)+tg;
	if (x>mid) return ask(t[k].rs,mid+1,r,x,y)+tg;
	return max(ask(t[k].ls,l,mid,x,mid),ask(t[k].rs,mid+1,r,mid+1,y))+tg;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d",&v[i].fi),v[i].se=i;
	sort(v+1,v+n+1,greater<pii>());
	For(i,1,n){
		int l=max(1,v[i].se-m+1);
		int r=min(n-m+1,v[i].se);
		//cout<<v[i].se<<' '<<l<<' '<<r<<endl;
		rt[i]=upd(rt[i-1],1,n-m+1,l,r);
	}
	int las=0,Q;
	scanf("%d",&Q);
	while (Q--){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		k=lower_bound(v+1,v+n+1,pii(k^las,0),greater<pii>())-v-1;
		//cout<<k<<endl; 
		printf("%d\n",las=m-ask(rt[k],1,n-m+1,l,r));
	}
}