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

struct node{
	int l,r,val;
	bool operator<(const node c)const{return mp(min(l,r),max(l,r))<mp(min(c.l,c.r),max(c.l,c.r));}
}a[500005];

int n,m,d;
int p[1000005],dp[1000005];
vector<pii> vec[1000005];

namespace bit{
	int val[1000005];
	void add(int x,int c){
		for(;x<=m;x+=(x&(-x))) val[x]+=c;
	}
	int ask(int x){
		int ret=0;
		for(;x;x-=(x&(-x))) ret+=val[x];
		return ret;
	}
}

int main(){
	n=readint(); d=readint();
	for(int i=1;i<=n;i++) a[i].l=readint(),a[i].r=readint();
	for(int i=1;i<=n;i++) p[++m]=a[i].l,p[++m]=a[i].r;
	p[++m]=d;
	sort(p+1,p+m+1);
	m=unique(p+1,p+m+1)-p-1;
	for(int i=1;i<=n;i++) a[i].l=lower_bound(p+1,p+m+1,a[i].l)-p,a[i].r=lower_bound(p+1,p+m+1,a[i].r)-p;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i].l>a[i].r) bit::add(a[i].l,1);
		else if(a[i].l==a[i].r) a[i].val=1;
		else a[i].val=bit::ask(a[i].r-1)-bit::ask(a[i].l)+1;
	}
	for(int i=1;i<=n;i++) if(a[i].l>a[i].r) a[i].r=a[i].l,a[i].val=1;
	for(int i=1;i<=n;i++) vec[a[i].l].pb(mp(a[i].r,a[i].val));
//	for(int i=1;i<=n;i++) cout<<"test "<<p[a[i].l]<<' '<<p[a[i].r]<<' '<<a[i].val<<endl;
	for(int i=0;i<=m;i++) dp[i]=-(1<<30);
	dp[lower_bound(p+1,p+m+1,d)-p]=0;
	for(int i=1;i<=m;i++){
		chkmax(dp[i],dp[i-1]);
		sort(vec[i].begin(),vec[i].end());
		for(auto r:vec[i]) chkmax(dp[r.fi],dp[i]+r.se);
	}
	printf("%d\n",dp[m]);
	return 0;
}