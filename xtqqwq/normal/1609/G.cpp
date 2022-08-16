// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,q;
ll a[105],ca[105],b[100005],cb[100005];

namespace sgt2{
	ll maxa[300000],lazy[300000];
	void build(int id,int l,int r){
		if(l==r) return (void)(maxa[id]=cb[l]);
		int mid=(l+r)/2;
		build(id<<1,l,mid);
		build(id<<1|1,mid+1,r);
		maxa[id]=max(maxa[id<<1],maxa[id<<1|1]);
	}
	void pushdown(int id){
		if(lazy[id]){
			lazy[id<<1]+=lazy[id],maxa[id<<1]+=lazy[id];
			lazy[id<<1|1]+=lazy[id],maxa[id<<1|1]+=lazy[id];
			lazy[id]=0;
		}
	}
	void change(int id,int l,int r,int ql,int qr,int c){
		if(l==ql&&r==qr) return (void)(maxa[id]+=c,lazy[id]+=c);
		pushdown(id);
		int mid=(l+r)/2;
		if(qr<=mid) change(id<<1,l,mid,ql,qr,c);
		else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,c);
		else change(id<<1,l,mid,ql,mid,c),change(id<<1|1,mid+1,r,mid+1,qr,c);
		maxa[id]=max(maxa[id<<1],maxa[id<<1|1]);
	}
	int query(int id,int l,int r,int x){
		if(maxa[id]<=x) return r+1;
		if(l==r) return r;
		pushdown(id);
		int mid=(l+r)/2;
		int tmp=query(id<<1,l,mid,x);
		if(tmp<=mid) return tmp;
		return query(id<<1|1,mid+1,r,x);
	}
}

namespace sgt1{
	int M,blo;
	int bl[100005];
	ll val[100005],lf[1005],rg[1005],pre[1005],preb[100005],sum[1005],tk[1005],tb[1005];
	void build(){
		for(int i=1;i<=m;i++) val[i]=b[i];
		blo=sqrt(m);
		for(int i=1;i<=m;i+=blo) lf[++M]=i,rg[M]=min(i+blo-1,m);
		for(int i=1;i<=M;i++) for(int j=lf[i];j<=rg[i];j++) bl[j]=i;
		for(int i=M;i>=1;i--) for(int j=lf[i];j<=rg[i];j++) preb[j]=preb[j-1]+val[j];
		for(int i=1;i<=M;i++) sum[i]=preb[rg[i]];
		for(int i=1;i<=M;i++) pre[i]=pre[i-1]+sum[i];
	}
	void rebuild(int b){
		for(int i=lf[b];i<=rg[b];i++) val[i]+=tk[b]*(i-lf[b])+tb[b];
		tk[b]=tb[b]=0;
		preb[lf[b]]=val[lf[b]];
		for(int i=lf[b]+1;i<=rg[b];i++) preb[i]=preb[i-1]+val[i];
		sum[b]=preb[rg[b]];
	}
	void change(int x,int d,int k){
//		cout<<"change "<<x<<' '<<d<<' '<<k<<endl;
//		for(int i=x;i<=m;i++) val[i]+=(i-x)*k+d,cout<<"??? "<<i<<' '<<val[i]<<endl;
		int b=bl[x];
		for(int i=x;i<=rg[b];i++) val[i]+=k*(i-x)+d;
		rebuild(b);
		d+=k*(rg[b]-x+1);
		for(int i=b+1;i<=M;i++){
			ll ak=k,ab=(lf[i]-rg[b]-1)*k+d;
			tk[i]+=k,tb[i]+=(lf[i]-rg[b]-1)*k+d;
			sum[i]+=(ab+ab+(rg[i]-lf[i])*ak)*(rg[i]-lf[i]+1)/2;
		}
		for(int i=1;i<=M;i++) pre[i]=pre[i-1]+sum[i];
	}
	ll ask(int x){
//		ll ret=0;
//		for(int i=1;i<=x;i++) ret+=val[i];
//		return ret;
		int b=bl[x];
		return pre[b-1]+preb[x]+((x-lf[b])*tk[b]+tb[b]*2)*(x-lf[b]+1)/2;
	}
	ll query(int l,int r){
		return ask(r)-ask(l-1);
	}
}

ll getans(){
	ll ret=0;
	int lst=1;
	for(int i=1;i<n;i++){
		int pl=sgt2::query(1,1,m,ca[i]);
//		cout<<"test "<<i<<' '<<pl<<' '<<a[i]<<' '<<sgt1::query(lst,pl)<<endl;
		ret+=a[i]*(pl-lst+1)+sgt1::query(lst,pl);
		lst=pl;
	}
//	cout<<"test "<<n<<' '<<m<<' '<<a[n]<<' '<<sgt1::query(lst,m)<<endl;
	return ret+a[n]*(m-lst+1)+sgt1::query(lst,m);
}

int main(){
	n=readint(); m=readint(); q=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=m;i++) b[i]=readint();
	a[n+1]=b[m+1]=1ll<<60;
	for(int i=1;i<=n;i++) ca[i]=a[i+1]-a[i];
	for(int i=1;i<=m;i++) cb[i]=b[i+1]-b[i];
	sgt1::build();
	sgt2::build(1,1,m);
	ll tp,k,d;
	while(q--){
		tp=readint(); k=readint(); d=readint();
		if(tp==1){
			for(int i=n-k+1;i<=n;i++) a[i]+=d*(i-n+k);
			for(int i=n-k;i<=n-1;i++) ca[i]+=d;
		}
		else{
			sgt1::change(m-k+1,d,d);
			sgt2::change(1,1,m,max(1ll,m-k),m-1,d);
		}
		printf("%lld\n",getans());
	}
	return 0;
}