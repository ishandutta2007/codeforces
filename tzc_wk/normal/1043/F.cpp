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
#define mt make_tuple
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
	template<typename T> void print(T x,char c){print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const u64 BS=131;
const int MAXN=3e5;
int n,m,cnt[MAXN+5],ck[67],dp[67];u64 pw[MAXN+5];
int mnp[MAXN+5],pr[MAXN/5+5],prcnt=0,vis[MAXN+5],cc[MAXN+5];
vector<int> fc[MAXN+5];
void sieve(int n){
	for(int i=2;i<=n;i++){
		if(!vis[i]) pr[++prcnt]=i,mnp[i]=i;
		for(int j=1;j<=prcnt&&pr[j]*i<=n;j++){
			vis[pr[j]*i]=1;mnp[i*pr[j]]=pr[j];
			if(i%pr[j]==0) break;
		}
	}
}
int main(){
//	freopen("sor.in","r",stdin);
//	freopen("sor.out","w",stdout);
	scanf("%d",&n);sieve(MAXN);
	for(int i=(pw[0]=1);i<=MAXN;i++) pw[i]=pw[i-1]*BS;
	for(int i=1;i<=MAXN;i++){
		int tmp=i;
		while(tmp^1){
			int p=mnp[tmp];
			while(tmp%p==0) tmp/=p;
			fc[i].pb(p);
		}
	}
	for(int i=1,x;i<=n;i++) scanf("%d",&x),cnt[x]++;
	vector<int> vec;int d=0;
	for(int j=1;j<=MAXN;j++) if(cnt[j]) vec.pb(j),d=__gcd(d,j);
	if(d>1) puts("-1");
	else{
		if(cnt[1]) return printf("1\n"),0;
		unordered_map<u64,int> cc;
		for(int x:vec){
			for(int i=0;i<(1<<fc[x].size());i++){
				u64 pww=0;
				for(int j=0;j<fc[x].size();j++) if(i>>j&1)
					pww+=pw[fc[x][j]];
				cc[pww]++;
			}
		} int mn=9;
		for(int x:vec){
			int sz=fc[x].size();
			for(int i=0;i<(1<<sz);i++){
				u64 pww=0;
				for(int j=0;j<fc[x].size();j++) if(i>>j&1)
					pww+=pw[fc[x][j]];
				ck[(1<<sz)-1-i]=cc[pww]-1;
			}
			for(int i=0;i<sz;i++) for(int j=0;j<(1<<sz);j++)
				if(~j>>i&1) ck[j^(1<<i)]-=ck[j];
			for(int i=0;i<sz;i++) for(int j=0;j<(1<<sz);j++)
				if(j>>i&1) ck[j^(1<<i)]+=ck[j];
			memset(dp,63,sizeof(dp));dp[0]=0;
			for(int i=0;i<(1<<sz);i++){
				int rst=(1<<sz)-1-i;
				for(int j=rst;j;--j&=rst) if(ck[j])	
					chkmin(dp[i|j],dp[i]+1);
			} chkmin(mn,dp[(1<<sz)-1]+1);
			if(mn==2) break;
		} printf("%d\n",mn);
	}
	return 0;
}