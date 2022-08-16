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

int n,m,k;
ll val[600000],lazy[600000],p[200005];
pll a[200005],b[200005];
pair<pll,ll> c[200005];

void build(int id,int l,int r){
	if(l==r) return (void)(val[id]=-b[l].se);
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	val[id]=max(val[id<<1],val[id<<1|1]);
}

void add(int id,ll c){val[id]+=c,lazy[id]+=c;}
void pushdown(int id){if(lazy[id]) add(id<<1,lazy[id]),add(id<<1|1,lazy[id]),lazy[id]=0;}

void change(int id,int l,int r,int ql,int qr,int c){
	if(ql>qr) return;
	if(l==ql&&r==qr) return add(id,c);
	pushdown(id);
	int mid=(l+r)/2;
	if(qr<=mid) change(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,c);
	else change(id<<1,l,mid,ql,mid,c),change(id<<1|1,mid+1,r,mid+1,qr,c);
	val[id]=max(val[id<<1],val[id<<1|1]);
}

int main(){
	n=readint(); m=readint(); k=readint();
	for(int i=1;i<=n;i++) a[i].fi=readint(),a[i].se=readint();
	for(int i=1;i<=m;i++) p[i]=b[i].fi=readint(),b[i].se=readint();
	for(int i=1;i<=k;i++) c[i].fi.fi=readint(),c[i].fi.se=readint(),c[i].se=readint();
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	sort(c+1,c+k+1);
	sort(p+1,p+m+1);
	for(int i=1;i<=m;i++) b[i].fi=lower_bound(p+1,p+m+1,b[i].fi)-p;
	build(1,1,m);
	int nowc=1; ll ans=-(1ll<<60);
	for(int i=1;i<=n;i++){
		while(nowc<=k&&c[nowc].fi.fi<a[i].fi) change(1,1,m,lower_bound(p+1,p+m+1,c[nowc].fi.se+1)-p,m,c[nowc].se),nowc++;
		chkmax(ans,-a[i].se+val[1]);
	}
	printf("%lld\n",ans);
	return 0;
}