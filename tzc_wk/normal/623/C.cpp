#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
namespace fastio{
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getchar();T neg=0;
		while(!isdigit(c)) neg|=!(c^'-'),c=getchar();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		if(neg) x=(~x)+1;
	}
	template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc(x%10^48);}
	template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1e5;
const int LOG_N=18;
const int INF=0x3f3f3f3f;
int n,mx[MAXN+5][LOG_N+2],mn[MAXN+5][LOG_N+2];
pii x[MAXN+5];
int query_mx(int l,int r){
	if(l>r) return -INF;int k=31-__builtin_clz(r-l+1);
	return max(mx[l][k],mx[r-(1<<k)+1][k]);
}
int query_mn(int l,int r){
	if(l>r) return INF;int k=31-__builtin_clz(r-l+1);
	return min(mn[l][k],mn[r-(1<<k)+1][k]);
}
int findpos(int v){
	int l=1,r=n,p=n+1;
	while(l<=r){
		int mid=l+r>>1;
		if(x[mid].fi>=v) p=mid,r=mid-1;
		else l=mid+1;
	} return p;
}
int getlim(ll x){
	int l=0,r=1e9,p=0;
	while(l<=r){
		int mid=l+r>>1;
		if(1ll*mid*mid<=x) p=mid,l=mid+1;
		else r=mid-1;
	} return p;
}
bool check(ll v){
	int lim=getlim(v);
	if(query_mx(1,n)-query_mn(1,n)<=lim) return 1;
	for(int i=1;i<=n;i++){
		int t=abs(x[i].fi);
		int p1=findpos(-t),p2=findpos(min(-t+lim,t)+1);
		int p3=findpos(max(t-lim,-t)),p4=findpos(t+1);
//		printf("%d %d %d %d %d\n",t,p1,p2,p3,p4);
		int mx=max(query_mx(1,p1-1),query_mx(p2,n));
		int mn=min(query_mn(1,p1-1),query_mn(p2,n));
//		printf("%d %d\n",mn,mx);
		if(mx==-INF) return 1;
		bool flg=1;
		if(mx-mn>lim) flg=0;
		if(p1<p2&&1ll*mx*mx+1ll*t*t>v) flg=0;
		if(p1<p2&&1ll*mn*mn+1ll*t*t>v) flg=0;
		if(flg) return 1;
		mx=max(query_mx(1,p3-1),query_mx(p4,n));
		mn=min(query_mn(1,p3-1),query_mn(p4,n));
//		printf("%d %d\n",mn,mx);
		if(mx==-INF) return 1;
		flg=1;
		if(mx-mn>lim) flg=0;
		if(p3<p4&&1ll*mx*mx+1ll*t*t>v) flg=0;
		if(p3<p4&&1ll*mn*mn+1ll*t*t>v) flg=0;
		if(flg) return 1;
	} return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&x[i].fi,&x[i].se);
	sort(x+1,x+n+1);
//	for(int i=1;i<=n;i++) printf("%d %d\n",x[i].fi,x[i].se);
	for(int i=1;i<=n;i++) mn[i][0]=x[i].se,mx[i][0]=x[i].se;
	for(int i=1;i<=LOG_N;i++) for(int j=1;j+(1<<i)-1<=n;j++){
		mn[j][i]=min(mn[j][i-1],mn[j+(1<<i-1)][i-1]);
		mx[j][i]=max(mx[j][i-1],mx[j+(1<<i-1)][i-1]);
	} //check(100);
	ll l=0,r=1e17,x=-1145141919810ll;
	while(l<=r){
		ll mid=l+r>>1;
		if(check(mid)) x=mid,r=mid-1;
		else l=mid+1;
	} printf("%lld\n",x);
	return 0;
}
/*
10
1 6
2 2
-1 9
-8 8
-4 10
-10 -6
5 -1
-3 -7
-4 3
9 4
*/