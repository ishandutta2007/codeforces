#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,q;
int a[300005],lf[300005];

namespace sgt{
	int lazy[1100000],maxa[1100000];
	void pushdown(int id){
		if(lazy[id]){
			lazy[id<<1]+=lazy[id],maxa[id<<1]+=lazy[id];
			lazy[id<<1|1]+=lazy[id],maxa[id<<1|1]+=lazy[id];
			lazy[id]=0;
		}
	}
	int find(int id,int l,int r,int ql,int qr,int c){
		if(maxa[id]<c) return l-1;
		if(l==r) return maxa[id]>=c?l:l-1;
		pushdown(id);
		int mid=(l+r)/2;
		if(qr<=mid) return find(id<<1,l,mid,ql,qr,c);
		else if(ql>mid) return find(id<<1|1,mid+1,r,ql,qr,c);
		else if(maxa[id<<1|1]>=c) return find(id<<1|1,mid+1,r,mid+1,qr,c);
		else return find(id<<1,l,mid,ql,mid,c);
	}
	void change(int id,int l,int r,int ql,int qr,int c){
		if(ql>qr) return;
		if(l==ql&&r==qr) return (void)(lazy[id]+=c,maxa[id]+=c);
		pushdown(id);
		int mid=(l+r)/2;
		if(qr<=mid) change(id<<1,l,mid,ql,qr,c);
		else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,c);
		else change(id<<1,l,mid,ql,mid,c),change(id<<1|1,mid+1,r,mid+1,qr,c);
		maxa[id]=max(maxa[id<<1],maxa[id<<1|1]);
	}
}

namespace pst{
	int ncnt;
	int vs[300005],lch[10000005],rch[10000005],val[10000005];
	void build(int id,int l,int r){
		if(l==r) return;
		int mid=(l+r)/2;
		build(lch[id]=++ncnt,l,mid);
		build(rch[id]=++ncnt,mid+1,r);
	}
	int change(int id,int l,int r,int x){
		int rt=++ncnt;
		val[rt]=val[id]+1,lch[rt]=lch[id],rch[rt]=rch[id];
		if(l==r) return rt;
		int mid=(l+r)/2;
		if(x<=mid) lch[rt]=change(lch[rt],l,mid,x);
		else rch[rt]=change(rch[rt],mid+1,r,x);
		return rt;
	}
	int query(int id1,int id2,int l,int r,int ql,int qr){
		if(l==ql&&r==qr) return val[id2]-val[id1];
		int mid=(l+r)/2;
		if(qr<=mid) return query(lch[id1],lch[id2],l,mid,ql,qr);
		else if(ql>mid) return query(rch[id1],rch[id2],mid+1,r,ql,qr);
		else return query(lch[id1],lch[id2],l,mid,ql,mid)+query(rch[id1],rch[id2],mid+1,r,mid+1,qr);
	}
}

int main(){
	n=readint(); q=readint();
	for(int i=1;i<=n;i++) a[i]=readint()-i;
	for(int i=1;i<=n;i++){
		if(a[i]>0) lf[i]=0;
		else{
			int pl=sgt::find(1,1,n,1,i,-a[i]);
			lf[i]=pl;
			sgt::change(1,1,n,1,pl,1);
		}
	}
	pst::build(pst::vs[0]=1,0,n);
	for(int i=1;i<=n;i++) pst::vs[i]=pst::change(pst::vs[i-1],0,n,lf[i]);
	int x,y,l,r;
	while(q--){
		x=readint(); y=readint();
		l=x+1,r=n-y;
		printf("%d\n",pst::query(pst::vs[l-1],pst::vs[r],0,n,l,r));
	}
	return 0;
}