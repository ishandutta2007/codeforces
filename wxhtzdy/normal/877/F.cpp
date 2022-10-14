#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmin(T&x,T y){return x>y?x=y,1:0;}
template<typename T> bool chkmax(T&x,T y){return x<y?x=y,1:0;}

const int S=sqrt(100005);
int n,k,q,t[100005],a[100005],v[100005],vx[100005],vy[100005],cnt[300005];
ll b[100005],ans[100005],cur;

namespace cpr{
	vector<ll> vec;
	void add(ll x){vec.pb(x);}
	void build(){sort(vec.begin(),vec.end());vec.erase(unique(vec.begin(),vec.end()),vec.end());}
	int get(ll x){return lower_bound(vec.begin(),vec.end(),x)-vec.begin();}
};

struct query{
	int l,r,i;
	bool operator<(query& e) const {
		return r/S<e.r/S||(r/S==e.r/S&&l<e.l);
	}
}qs[100005];

void addl(int i){
	cur+=cnt[vy[i]];
	cnt[v[i]]++;
}
void reml(int i){
	cnt[v[i]]--;
	cur-=cnt[vy[i]];
}
void addr(int i){
	cur+=cnt[vx[i]];
	cnt[v[i]]++;
}
void remr(int i){
	cnt[v[i]]--;
	cur-=cnt[vx[i]];
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&t[i]);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=b[i-1]+a[i]*(t[i]==1?1:-1);
	for(int i=0;i<=n;i++)cpr::add(b[i]),cpr::add(b[i]+k),cpr::add(b[i]-k);
	cpr::build();
	for(int i=0;i<=n;i++)v[i]=cpr::get(b[i]),vx[i]=cpr::get(b[i]-k),vy[i]=cpr::get(b[i]+k);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)scanf("%d%d",&qs[i].l,&qs[i].r),qs[i].i=i;
	sort(qs+1,qs+q+1);
	int tl=1,tr=0;
	for(int i=1;i<=q;i++){
		while(tl<qs[i].l)reml(tl),tl++;
		while(tl>qs[i].l)tl--,addl(tl);
		while(tr<qs[i].r)tr++,addr(tr);
		while(tr>qs[i].r)remr(tr),tr--;
		ans[qs[i].i]=cur+cnt[vy[tl-1]];
	}
	for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
	return 0;
}