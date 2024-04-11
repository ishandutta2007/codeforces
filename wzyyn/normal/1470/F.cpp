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
int n;
pii p[N];
ll ans,v[N];
void UPD1(){
	sort(p+1,p+n+1);
	For(i,0,n) v[i]=0;
	int mny=1e9,mxy=0;
	For(i,1,n){
		mny=min(mny,p[i].se);
		mxy=max(mxy,p[i].se);
		v[i]+=1ll*(p[i].fi-p[1].fi)*(mxy-mny);
	}
	mny=1e9; mxy=0;
	Rep(i,n,1){
		mny=min(mny,p[i].se);
		mxy=max(mxy,p[i].se);
		v[i-1]+=1ll*(p[n].fi-p[i].fi)*(mxy-mny);
	}
	For(i,0,n) ans=min(ans,v[i]);
}
ll L[N],R[N],V[N];
struct Tree1{
	ll t[N*4];
	ll tg[N*4];
	void build(int k,int l,int r){
		tg[k]=0;
		if (l==r){
			t[k]=V[l];
			return;
		}
		int mid=(l+r)/2;
		build(k*2,l,mid);
		build(k*2+1,mid+1,r);
		t[k]=min(t[k*2],t[k*2+1]);		
	}
	void add(int k,ll v){
		t[k]+=v;
		tg[k]+=v;
	}
	void pushdown(int k){
		if (!tg[k]) return;
		add(k*2,tg[k]);
		add(k*2+1,tg[k]);
		tg[k]=0;
	}
	void change(int k,int l,int r,int x,int y,ll v){
		//if (l==1&&r==n) cout<<"C "<<x<<' '<<y<<' '<<v<<endl;
		if (x<=l&&r<=y)
			return add(k,v);
		pushdown(k);
		int mid=(l+r)/2;
		if (x<=mid) change(k*2,l,mid,x,y,v);
		if (y>mid) change(k*2+1,mid+1,r,x,y,v);
		t[k]=min(t[k*2],t[k*2+1]);
	}
	ll query(int k,int l,int r,int x,int y){
		if (l==x&&r==y) return t[k];
		pushdown(k);
		int mid=(l+r)/2;
		if (y<=mid) return query(k*2,l,mid,x,y);
		if (x>mid) return query(k*2+1,mid+1,r,x,y);
		return min(query(k*2,l,mid,x,mid),query(k*2+1,mid+1,r,mid+1,y));
	}
}T;
void UPD2(){
	sort(p+1,p+n+1);
	int mnY=1e9,mxY=0;
	For(i,1,n){
		mnY=min(mnY,p[i].se);
		mxY=max(mxY,p[i].se);
	}
	int mny=p[1].se,mxy=p[1].se;
	Rep(i,n,1){
		L[i]=1ll*(p[n].fi-p[1].fi)*mny;
		R[i]=1ll*(p[n].fi-p[1].fi)*mxy;
		V[i]=1ll*(p[i].fi-p[1].fi)*(mxY-mnY)+R[i]-L[i];
		//cout<<L[i]<<' '<<R[i]<<' '<<V[i]<<endl;
		mny=min(mny,p[i].se);
		mxy=max(mxy,p[i].se);
	}
	T.build(1,1,n);
	int t1=n,t2=n;
	For(i,1,n){
		ans=min(ans,T.query(1,1,n,i,n)-1ll*(p[i].fi-p[1].fi)*(mxY-mnY));
		//cout<<T.query(1,1,n,i,n)<<endl;
		ll key=1ll*p[i].se*(p[n].fi-p[1].fi);
		if (L[t1]>key){
			T.change(1,1,n,t1,n,L[t1]-key);
			for (;t1!=1&&L[t1-1]>key;--t1)
				T.change(1,1,n,t1-1,t1-1,L[t1-1]-key);
			L[t1]=key;
			//T.change(1,1,n,t1,n,-key);
		}
		if (R[t2]<key){
			T.change(1,1,n,t2,n,-R[t2]+key);
			for (;t2!=1&&R[t2-1]<key;--t2)
				T.change(1,1,n,t2-1,t2-1,-R[t2-1]+key);
			R[t2]=key;
			//T.change(1,1,n,t2,n,key);
		}
	}
}
int q[N];
pii pq[N];
bool cmp(pii x,pii y){
	if (!x.se&&!y.se) return x.fi<y.fi;
	if ((!x.se)^(!y.se)) return !x.se;
	if (!x.fi&&!y.fi) return x.se<y.se;
	if (1ll*x.fi*y.se!=1ll*y.fi*x.se)
		return 1ll*x.fi*y.se>1ll*y.fi*x.se;
	return x.fi<y.fi;
}
//x.fi*y.se<y.fi*x.se
const int M=5000005;
ll F(pii x,pii y){
	return 1ll*x.fi*y.fi+1ll*x.se*y.se;
}
struct Lichao{
	int rt[N*4],nd;
	int ls[M],rs[M];
	pii t[M];
	void build(int k,int l,int r){
		rt[k]=0;
		if (l==r) return;
		int mid=(l+r)/2;
		build(k*2,l,mid);
		build(k*2+1,mid+1,r);
	}
	void init(int n){
		for (;nd;){
			ls[nd]=rs[nd]=0;
			t[nd]=pii(0,0);
			--nd;
		}
		build(1,1,n);
	}
	void insert(int &k,int l,int r,pii v){
		if (!k){
			k=++nd;
			t[k]=v;
			return;
		}
		int mid=(l+r)/2;
		if (F(t[k],pq[mid])>F(v,pq[mid])) swap(t[k],v);
		if (F(t[k],pq[l])>F(v,pq[l])) insert(ls[k],l,mid,v);
		if (F(t[k],pq[r])>F(v,pq[r])) insert(rs[k],mid+1,r,v);
	}
	void insert(int k,int l,int r,int p,pii v){
		insert(rt[k],1,n,v);
		if (l==r) return;
		int mid=(l+r)/2;
		if (p<=mid) insert(k*2,l,mid,p,v);
		else insert(k*2+1,mid+1,r,p,v);
	}
	void query(int k,int l,int r,int p){
		if (!k) return;
		ans=min(ans,F(t[k],pq[p]));
		int mid=(l+r)/2;
		if (p<=mid) query(ls[k],l,mid,p);
		if (p>mid) query(rs[k],mid+1,r,p);
	}
	void query(int k,int l,int r,int x,int y,int id){
		if (x<=l&&r<=y)
			return query(rt[k],1,n,id);
		int mid=(l+r)/2;
		if (x<=mid) query(k*2,l,mid,x,y,id);
		if (y>mid) query(k*2+1,mid+1,r,x,y,id);
	}
}TT;
int L1[N],L2[N];
int L3[N],L4[N];
void UPD3(){
	int mnY=1e9,mxY=0;
	sort(p+1,p+n+1);
	For(i,1,n){
		mnY=min(mnY,p[i].se);
		mxY=max(mxY,p[i].se);
	}
	int mxy=mnY;
	For(i,1,n){
		L1[i]=p[i].fi-p[1].fi;
		L2[i]=mxy-mnY;
		mxy=max(mxy,p[i].se);
	}
	int mny=mxY;
	Rep(i,n,1){
		L3[i]=p[n].fi-p[i].fi;
		L4[i]=mxY-mny;
		mny=min(mny,p[i].se);
	}
	//For(i,1,n) cout<<L1[i]<<' '<<L2[i]<<' '<<L3[i]<<' '<<L4[i]<<endl;
	*q=0;
	For(i,1,n) q[i]=L2[i];
	sort(q+1,q+n+1);
	For(i,1,n) pq[i]=(L1[i]+L4[i]?pii(L1[i],L4[i]):pii(1,1));
	sort(pq+1,pq+n+1,cmp);
	TT.init(n);
	For(i,1,n){
		int p=lower_bound(q+1,q+n+1,L2[i])-q;
		TT.insert(1,1,n,p,pii(L2[i],L3[i]));
		int p2=lower_bound(q+1,q+n+1,mxY-mnY-L4[i])-q;
		if (L1[i]||L4[i]){
			int id=lower_bound(pq+1,pq+n+1,pii(L1[i],L4[i]),cmp)-pq;
			assert(pq[id]==pii(L1[i],L4[i]));
			if (p2!=n+1) TT.query(1,1,n,p2,n,id);
		}
	}
}
/*
L4[r]+L2[l]>=mxY-mnY
L1[r]*L2[l]+L4[r]*L3[l]
*/
void solve(int T){
	ans=1ll<<60;
	scanf("%d",&n);
	For(i,1,n) scanf("%d%d",&p[i].fi,&p[i].se);
	UPD1();
	For(i,1,n) swap(p[i].fi,p[i].se);
	UPD1();
	For(i,1,n) swap(p[i].fi,p[i].se);
	//cout<<ans<<endl;
	UPD2();
	//cout<<ans<<endl;
	UPD3();
	For(i,1,n) p[i].se=1000000000-p[i].se;
	UPD3();
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve(T);
}
/*
Case2:
1
12
0 49
0 51
49 51
49 100
51 100
51 51
100 51
100 49
51 49
51 0
49 0
49 49
*/

/*
Case3:
a.x*b.y+b.x*a.y
 
1
16
0 49
0 51
49 51
49 100
51 100
51 51
100 51
100 49
51 49
51 0
49 0
49 49
0 0
25 25
75 75
100 100
*/