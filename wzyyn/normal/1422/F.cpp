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
const int M=30000005;
const int mo=1000000007;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int mn[N];
void init(){
	For(i,2,N-1) if (!mn[i])
		For(j,1,(N-1)/i) if (!mn[i*j]) mn[i*j]=i;
}
int rt[N],n;
int ls[M],rs[M],tg[M],nd;
void build(int &k,int l,int r){
	k=++nd; tg[k]=1;
	if (l==r) return;
	int mid=(l+r)/2;
	build(ls[k],l,mid);
	build(rs[k],mid+1,r);
}
void change(int k,int &nk,int l,int r,int x,int y,int v){
	//if (l==1&&r==n) cout<<" C "<<x<<' '<<y<<' '<<v<<endl;
	nk=++nd; ls[nk]=ls[k]; rs[nk]=rs[k]; tg[nk]=tg[k];
	if (x<=l&&r<=y){
		tg[nk]=1ll*tg[nk]*v%mo;
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid) change(ls[k],ls[nk],l,mid,x,y,v);
	if (y>mid) change(rs[k],rs[nk],mid+1,r,x,y,v);
}
int ask(int k,int l,int r,int p){
	//cout<<k<<' '<<l<<' '<<r<<' '<<tg[k]<<endl;
	if (l==r) return tg[k];
	int mid=(l+r)/2;
	if (p<=mid) return 1ll*tg[k]*ask(ls[k],l,mid,p)%mo;
	return 1ll*tg[k]*ask(rs[k],mid+1,r,p)%mo;
}
vector<pii> v[N];
int main(){
	init();
	For(i,1,N-1)
		if (mn[i]==i)
			v[i].PB(pii(0,1<<30));
	scanf("%d",&n);
	build(rt[0],1,n);
	For(i,1,n){
		rt[i]=rt[i-1]; 
		int x;
		scanf("%d",&x);
		for (;x!=1;){
			int p=mn[x],q=1;
			for (;x%p==0;x/=p,q*=p);
			//cout<<x<<' '<<p<<' '<<q<<endl;
			for (;v[p].back().se<=q;){
				int key=v[p].back().se;
				int r=v[p].back().fi;
				v[p].pop_back();
				change(rt[i],rt[i],1,n,v[p].back().fi+1,r,power(key,mo-2));
			}
			change(rt[i],rt[i],1,n,v[p].back().fi+1,i,q);
			v[p].PB(pii(i,q));
		}
	}
	int Q,la=0;
	scanf("%d",&Q);
	while (Q--){
		int l,r;
		scanf("%d%d",&l,&r);
		l=(l+la)%n+1;
		r=(r+la)%n+1;
		if (l>r) swap(l,r);
		printf("%d\n",la=ask(rt[r],1,n,l));
	}
}