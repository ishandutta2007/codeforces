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

int n;
pii a[100005];
ll d[300000],f[300000];

void build(int id,int l,int r){
	d[id]=f[id]=1ll<<60;
	if(l==r){
		if(l==1) d[id]=0;
		return;
	}
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
}

void pushdown(int id){
	if(d[id]<(1ll<<60)) chkmin(d[id<<1],d[id]),chkmin(d[id<<1|1],d[id]),d[id]=1ll<<60;
	if(f[id]<(1ll<<60)) chkmin(f[id<<1],f[id]),chkmin(f[id<<1|1],f[id]),f[id]=1ll<<60;
}

void change1(int id,int l,int r,int ql,int qr,ll c){
	if(l==ql&&r==qr){
		chkmin(d[id],c);
		return;
	}
	pushdown(id);
	int mid=(l+r)/2;
	if(qr<=mid) change1(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) change1(id<<1|1,mid+1,r,ql,qr,c);
	else change1(id<<1,l,mid,ql,mid,c),change1(id<<1|1,mid+1,r,mid+1,qr,c);
}

void change2(int id,int l,int r,int ql,int qr,ll c){
	if(l==ql&&r==qr){
		chkmin(f[id],c);
		return;
	}
	pushdown(id);
	int mid=(l+r)/2;
	if(qr<=mid) change2(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) change2(id<<1|1,mid+1,r,ql,qr,c);
	else change2(id<<1,l,mid,ql,mid,c),change2(id<<1|1,mid+1,r,mid+1,qr,c);
}

ll query(int id,int l,int r,int x){
	if(l==r) return min(d[id],f[id]+a[x].fi);
	pushdown(id);
	int mid=(l+r)/2;
	if(x<=mid) return query(id<<1,l,mid,x);
	else return query(id<<1|1,mid+1,r,x);
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i].fi=readint(),a[i].se=readint();
	sort(a+1,a+n+1);
	ll ans=0;
	for(int i=1;i<=n;i++) ans+=a[i].se;
	build(1,1,n);
	for(int i=1;i<=n;i++){
		ll tmp=query(1,1,n,i);
		int pl=lower_bound(a+1,a+n+1,mp(a[i].fi+a[i].se,1<<30))-a-1;
		if(i<pl) change1(1,1,n,i+1,pl,tmp);
		if(pl<n) change2(1,1,n,pl+1,n,tmp-a[i].fi-a[i].se);
		if(i==n) printf("%lld\n",ans+tmp);
	}
	return 0;
}