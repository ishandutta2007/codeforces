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
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(y<x) x=y;}
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
	template<typename T> void recursive_print(T x){return (!x)?void():(recursive_print(x/10),putc(x%10^48),void());}
	template<typename T> void print(T x){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);}
	template<typename T> void print(T x,char c){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=5e5;
const ll INF=0x3f3f3f3f3f3f3f3fll;
int n,k,a[MAXN+5];ll ans;
struct dp_val{
	int num;ll res;
	dp_val(int _num=0,ll _res=0):num(_num),res(_res){}
	bool operator <(dp_val rhs) const{
		return (res!=rhs.res)?(res<rhs.res):(num>rhs.num);
	}
	dp_val operator +(dp_val rhs){
		return dp_val(num+rhs.num,res+rhs.res);
	}
} dp[MAXN+5];
bool check(int mid){
	for(int i=1;i<=n;i++) dp[i]=dp_val();dp_val mn=dp_val(0,INF);
	for(int i=1;i<=n;i++){
		dp[i]=min(dp[i-1],mn+dp_val(1,-mid+a[i]));
		mn=min(mn,dp[i-1]+dp_val(0,-a[i]));
	} //printf("%d %lld %d\n",mid,dp[n].res,dp[n].num);
	return (dp[n].num>=k)?(ans=1ll*k*mid+dp[n].res,1):0;
}
int main(){
	scanf("%d%d",&k,&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);int l=0,r=1e9,p=-1;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)) p=mid,r=mid-1;
		else l=mid+1;
	} assert(~p);check(p);printf("%lld\n",ans);
	return 0;
}