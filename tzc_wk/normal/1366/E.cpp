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
const int MAXN=2e5;
const int LOG_N=18;
const int MOD=998244353;
int n,m,a[MAXN+5],b[MAXN+5],st[MAXN+5][LOG_N+2];
int bg[MAXN+5],ed[MAXN+5];
int qry(int l,int r){
	int k=31-__builtin_clz(r-l+1);
	return min(st[l][k],st[r-(1<<k)+1][k]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),st[i][0]=a[i];
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	for(int i=1;i<=LOG_N;i++) for(int j=1;j+(1<<i)-1<=n;j++)
		st[j][i]=min(st[j][i-1],st[j+(1<<i-1)][i-1]);
	int lst=n;
	for(int i=m;i;i--){
		if(!lst) return puts("0")&0;
		int l=1,r=lst;
		while(l<=r){
			int mid=l+r>>1;
			if(qry(mid,lst)>b[i]) r=mid-1;
			else ed[i]=mid,l=mid+1;
		} if(!ed[i]||qry(ed[i],lst)!=b[i]) return puts("0")&0;
		l=1,r=ed[i];
		while(l<=r){
			int mid=l+r>>1;
			if(qry(mid,lst)==b[i]) bg[i]=mid,r=mid-1;
			else l=mid+1;
		} lst=bg[i]-1;
//		printf("%d %d\n",bg[i],ed[i]);
	} if(bg[1]!=1) return puts("0")&0;int ans=1;
	for(int i=2;i<=m;i++) ans=1ll*ans*(ed[i]-bg[i]+1)%MOD;
	printf("%d\n",ans);
	return 0;
}