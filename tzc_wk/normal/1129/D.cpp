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
inline void debug(int x){fprintf(stderr,"ycx has aked ioi %d times\n",x);}
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
	template<typename T> void print(T x,char c){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1e5;
const int SQRT=316;
const int MOD=998244353;
void add(int &x,int y){((x+=y)>=MOD)&&(x-=MOD);}
int n,k,a[MAXN+5],blk_sz,blk_cnt,bel[MAXN+5];
int L[SQRT+5],R[SQRT+5],sum[SQRT+5][MAXN+5];
int cnt[MAXN+5],tag[SQRT+5],dp[MAXN+5],tot[SQRT+5];
int pre[MAXN+5],pre_pre[MAXN+5];
void add(int x,int y,int z){
	if(x>y) return;
	if(bel[x]==bel[y]){
		for(int i=x;i<=y;i++){
			if(z==1) add(sum[bel[x]][++cnt[i]],dp[i]);
			else add(sum[bel[x]][cnt[i]--],MOD-dp[i]);
		}
	} else {
		for(int i=x;i<=R[bel[x]];i++){
			if(z==1) add(sum[bel[x]][++cnt[i]],dp[i]);
			else add(sum[bel[x]][cnt[i]--],MOD-dp[i]);
		}
		for(int i=L[bel[y]];i<=y;i++){
			if(z==1) add(sum[bel[y]][++cnt[i]],dp[i]);
			else add(sum[bel[y]][cnt[i]--],MOD-dp[i]);
		}
		for(int i=bel[x]+1;i<bel[y];i++) tag[i]+=z;
	}
}
int calc(){
	int ret=0;
	for(int i=0;i<=blk_cnt;i++){
		add(ret,tot[i]);
		if(k-tag[i]+1>=0) add(ret,MOD-sum[i][k-tag[i]+1]);
		else add(ret,MOD-tot[i]);
	} return ret;
}
int main(){
	scanf("%d%d",&n,&k);dp[0]=1;
	blk_sz=(int)pow(n,0.5);blk_cnt=n/blk_sz+1;
	for(int i=1;i<=blk_cnt;i++){
		L[i]=(i-1)*blk_sz;R[i]=min(i*blk_sz-1,n);
		for(int j=L[i];j<=R[i];j++) bel[j]=i;
	} sum[1][0]=1;tot[1]=1;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		add(pre_pre[a[i]],pre[a[i]]-1,-1);add(pre[a[i]],i-1,1);
		pre_pre[a[i]]=pre[a[i]];pre[a[i]]=i;dp[i]=calc();
		add(sum[bel[i]][0],dp[i]);add(tot[bel[i]],dp[i]);
//		printf("%d\n",dp[i]);
	} printf("%d\n",dp[n]);
	return 0;
}