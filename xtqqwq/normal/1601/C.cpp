#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m;
int a[1000005],b[1000005],cnt[2100000][2],mina[2100000],tp[2100000];
pii p[1000005];

namespace bit{
	int val[1000005];
	void add(int x,int c){
		for(;x<=n;x+=(x&(-x))) val[x]+=c;
	}
	int ask(int x){
		int ret=0;
		for(;x;x-=(x&(-x))) ret+=val[x];
		return ret;
	}
}

void update(int id){
	cnt[id][0]=cnt[id<<1][0]+cnt[id<<1|1][0];
	cnt[id][1]=cnt[id<<1][1]+cnt[id<<1|1][1];
	mina[id]=min(mina[id<<1]+cnt[id<<1|1][0],mina[id<<1|1]+cnt[id<<1][1]);
}

void build(int id,int l,int r){
	if(l==r){
		if(!l) cnt[id][0]=1,cnt[id][1]=0,mina[id]=0;
		else cnt[id][0]=0,cnt[id][1]=mina[id]=1;
		return;
	}
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	update(id);
}

void change(int id,int l,int r,int x,int c){
	if(l==r){
		tp[id]=c;
		if(tp[id]<=1) cnt[id][tp[id]]=1,cnt[id][tp[id]^1]=0;
		else cnt[id][0]=cnt[id][1]=0;
		mina[id]=cnt[id][1];
		return;
	}
	int mid=(l+r)/2;
	if(x<=mid) change(id<<1,l,mid,x,c);
	else change(id<<1|1,mid+1,r,x,c);
	update(id);
}

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		for(int i=1;i<=m;i++) b[i]=readint();
		sort(b+1,b+m+1);
		for(int i=1;i<=n;i++) p[i]=mp(a[i],i);
		sort(p+1,p+n+1);
		build(1,0,n);
		int pl=1;
		ll ans=0;
		for(int i=1;i<=m;i++){
			while(pl<=n&&p[pl].fi<b[i]) change(1,0,n,p[pl].se,0),pl++;
			if(b[i]!=b[i-1]){
				for(int j=pl;p[j].fi==b[i];j++) change(1,0,n,p[j].se,2);
			}
			ans+=mina[1];
		}
		for(int i=1;i<=n;i++) a[p[i].se]=i;
		for(int i=1;i<=n;i++) bit::val[i]=0;
		for(int i=1;i<=n;i++){
			ans+=i-1-bit::ask(a[i]-1);
			bit::add(a[i],1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}