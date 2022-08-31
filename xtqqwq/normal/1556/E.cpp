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

struct node{
	ll mn,mx,s;
	node(ll mn=0,ll mx=0,ll s=0):mn(mn),mx(mx),s(s){}
	node operator+(const node c)const{
		return node(min(mn,s+c.mn),max(mx,s+c.mx),s+c.s);
	}
};

int n,q;
vector<pii> qry[100005];
ll a[300005],mina[300000],maxa[300000],sum[300000],ans[100005];

node query(int id,int l,int r,int ql,int qr){
	if(l==ql&&r==qr) return node(mina[id],maxa[id],sum[id]);
	int mid=(l+r)/2;
	if(qr<=mid) return query(id<<1,l,mid,ql,qr);
	else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr);
	else return query(id<<1,l,mid,ql,mid)+query(id<<1|1,mid+1,r,mid+1,qr);
}

void change(int id,int l,int r,int x,int c){
	if(l==r) return (void)(mina[id]=min(0,c),maxa[id]=max(0,c),sum[id]=c);
	int mid=(l+r)/2;
	if(x<=mid) change(id<<1,l,mid,x,c);
	else change(id<<1|1,mid+1,r,x,c);
	mina[id]=min(mina[id<<1],sum[id<<1]+mina[id<<1|1]);
	maxa[id]=max(maxa[id<<1],sum[id<<1]+maxa[id<<1|1]);
	sum[id]=sum[id<<1]+sum[id<<1|1];
}

int main(){
	n=readint(); q=readint();
	for(int i=1;i<=n;i++) a[i]-=readint();
	for(int i=1;i<=n;i++) a[i]+=readint();
	int x,y;
	for(int i=1;i<=q;i++){
		x=readint(); y=readint();
		qry[x].pb(mp(y,i));
	}
	for(int i=n;i>=1;i--){
		change(1,1,n,i,a[i]);
		for(auto r:qry[i]){
			node tmp=query(1,1,n,i,r.fi);
			if(tmp.mn<0||tmp.s!=0) ans[r.se]=-1;
			else ans[r.se]=tmp.mx;
		}
	}
	for(int i=1;i<=q;i++) printf("%lld\n",ans[i]);
	return 0;
}