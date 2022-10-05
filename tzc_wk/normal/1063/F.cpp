//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
//#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
//#pragma GCC optimize("move-loop-invariants")
//#pragma GCC optimize("unswitch-loops")
//#pragma GCC optimize("branch-target-load-optimize")
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
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
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
	template<typename T> void recursive_print(T x){return (!x)?void():(recursive_print(x/10),putc(x%10^48),void());}
	template<typename T> void print(T x){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);}
	template<typename T> void print(T x,char c){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=5e5;
const int LOG_N=19;
int n;char str[MAXN+5];pii x[MAXN+5];
int sa[MAXN+5],rk[MAXN+5],ht[MAXN+5],seq[MAXN+5],buc[MAXN+5];
void getsa(){
	int vmax=122,gr=0;
	for(int i=1;i<=n;i++) buc[str[i]]++;
	for(int i=1;i<=vmax;i++) buc[i]+=buc[i-1];
	for(int i=n;i;i--) sa[buc[str[i]]--]=i;
	for(int i=1;i<=n;i++){
		if(str[sa[i]]!=str[sa[i-1]]) ++gr;
		rk[sa[i]]=gr;
	} vmax=gr;
	for(int k=1;k<=n;k<<=1){
		for(int i=1;i<=n;i++){
			if(i+k<=n) x[i]=mp(rk[i],rk[i+k]);
			else x[i]=mp(rk[i],0);
		} memset(buc,0,sizeof(buc));int num=0;gr=0;
		for(int i=n-k+1;i<=n;i++) seq[++num]=i;
		for(int i=1;i<=n;i++) if(sa[i]>k) seq[++num]=sa[i]-k;
		for(int i=1;i<=n;i++) buc[x[i].fi]++;
		for(int i=1;i<=vmax;i++) buc[i]+=buc[i-1];
		for(int i=n;i;i--) sa[buc[x[seq[i]].fi]--]=seq[i];
		for(int i=1;i<=n;i++){
			if(x[sa[i]]!=x[sa[i-1]]) ++gr;
			rk[sa[i]]=gr;
		} vmax=gr;if(vmax==n) break;
	}
}
void getht(){
	int k=0;
	for(int i=1;i<=n;i++){
		if(rk[i]==1) continue;if(k) --k;int j=sa[rk[i]-1];
		while(i+k<=n&&j+k<=n&&str[i+k]==str[j+k]) ++k;
		ht[rk[i]]=k;
	}
}
int st[MAXN+5][LOG_N+2];
void buildst(){
	for(int i=1;i<=n;i++) st[i][0]=ht[i];
	for(int i=1;i<=LOG_N;i++) for(int j=1;j+(1<<i)-1<=n;j++)
		st[j][i]=min(st[j][i-1],st[j+(1<<i-1)][i-1]);
}
int queryst(int l,int r){
	int k=31-__builtin_clz(r-l+1);
	return min(st[l][k],st[r-(1<<k)+1][k]);
}
int getlcp(int x,int y){
	if(x==y) return n-x+1;
	x=rk[x];y=rk[y];if(x>y) swap(x,y);
	return queryst(x+1,y);
}
int dp[MAXN+5];
struct node{int l,r,mx;} s[MAXN*4+5];
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r) return;int mid=l+r>>1;
	build(k<<1,l,mid);build(k<<1|1,mid+1,r);
}
void modify(int k,int x,int v){
	if(s[k].l==s[k].r) return s[k].mx=v,void();
	int mid=s[k].l+s[k].r>>1;
	if(x<=mid) modify(k<<1,x,v);
	else modify(k<<1|1,x,v);
	s[k].mx=max(s[k<<1].mx,s[k<<1|1].mx);
}
int query(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r) return s[k].mx;
	int mid=s[k].l+s[k].r>>1;
	if(r<=mid) return query(k<<1,l,r);
	else if(l>mid) return query(k<<1|1,l,r);
	else return max(query(k<<1,l,mid),query(k<<1|1,mid+1,r));
}
pii get_itvl(int x,int len){
	x=rk[x];int L=1,R=x-1,l=x,r=x;
	while(L<=R){
		int mid=L+R>>1;
		if(queryst(mid+1,x)>=len) l=mid,R=mid-1;
		else L=mid+1;
	} L=x+1,R=n;
	while(L<=R){
		int mid=L+R>>1;
		if(queryst(x+1,mid)>=len) r=mid,L=mid+1;
		else R=mid-1;
	} return mp(l,r);
}
bool check(int x,int v){
	if(v==1) return 1;
	pii p=get_itvl(x,v-1);
//	printf("itvl %d %d\n",p.fi,p.se);
	if(query(1,p.fi,p.se)+1>=v) return 1;
	p=get_itvl(x+1,v-1);
//	printf("itvl %d %d\n",p.fi,p.se);
//	printf("%d\n",query(1,p.fi,p.se));
	if(query(1,p.fi,p.se)+1>=v) return 1;
	return 0;
}
int main(){
	scanf("%d%s",&n,str+1);getsa();getht();buildst();
//	for(int i=1;i<=n;i++) printf("%d%c",sa[i]," \n"[i==n]);
	int res=0;build(1,1,n);
	for(int i=n;i;i--){
//		for(int j=1;j<i;j++){
//			chkmax(dp[j],min(min(getlcp(i,j),dp[i])+1,i-j));
//			if(j+1!=i) chkmax(dp[j],min(min(getlcp(i,j+1),dp[i])+1,i-j));
//		}
		dp[i]=dp[i+1]+1;
		while(!check(i,dp[i])){
			modify(1,rk[i+dp[i]-1],dp[i+dp[i]-1]);
			dp[i]--;
		}
		chkmax(res,dp[i]);
//		printf("%d %d\n",i,dp[i]);
	} printf("%d\n",res);
	return 0;
}