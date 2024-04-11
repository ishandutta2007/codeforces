//#pragma comment(linker,"/stack:200000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
const int MAXN=250;
const int MOD=998244353;
int n,a[MAXN+5],b[MAXN+5],c[2][2],fa[MAXN+5],cnt=0,ans[MAXN+5];
int find(int x){return (!fa[x])?x:fa[x]=find(fa[x]);}
void merge(int x,int y){x=find(x);y=find(y);(x==y)?(cnt++):(fa[x]=y);}
int fac[MAXN+5],ifac[MAXN+5],s[MAXN+5][MAXN+5];
void init_fac(int n){
	for(int i=(fac[0]=ifac[0]=ifac[1]=1)+1;i<=n;i++) ifac[i]=1ll*ifac[MOD%i]*(MOD-MOD/i)%MOD;
	for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%MOD,ifac[i]=1ll*ifac[i-1]*ifac[i]%MOD;
	for(int i=(s[0][0]=1);i<=n;i++) for(int j=1;j<=i;j++)
		s[i][j]=(s[i-1][j-1]+1ll*(i-1)*s[i-1][j])%MOD;
}
void calc(int *f,int a,int b){
	if(!b){
		for(int i=0;i<=a;i++) f[i]=s[a][i];
		return;
	} for(int i=0;i<=a;i++) for(int j=i;j<=a;j++)
		f[i]=(f[i]+1ll*fac[a]*ifac[j]%MOD*ifac[a-j]%MOD*
		s[j][i]%MOD*fac[a+b-j-1]%MOD*ifac[b-1])%MOD;
}
int f1[MAXN+5],f2[MAXN+5],f3[MAXN+5],tmp[MAXN+5];
int in[MAXN+5],out[MAXN+5];
int main(){
	scanf("%d",&n);init_fac(MAXN);
	memset(in,0xff,sizeof(in));memset(out,0xff,sizeof(out));
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	for(int i=1;i<=n;i++) if(a[i]&&b[i]) merge(a[i],b[i]);
	for(int i=1;i<=n;i++) in[b[i]]=a[i],out[a[i]]=b[i];
	for(int i=1;i<=n;i++) if(!~in[i]&&~out[i]){
		int cur=i;
		while(cur&&~out[cur]) cur=out[cur];
		if(!cur) ++c[0][1];
	}
	for(int i=1;i<=n;i++) if(~in[i]&&!~out[i]){
		int cur=i;
		while(cur&&~in[cur]) cur=in[cur];
		if(!cur) ++c[1][0];
	}
	for(int i=1;i<=n;i++) if(!a[i]&&!b[i]) c[0][0]++;
	for(int i=1;i<=n;i++) if(!in[i]){
		int cur=i;
		while(cur&&~out[cur]) cur=out[cur];
		if(!cur) ++c[0][0];
	} //printf("%d %d %d\n",c[0][0],c[1][0],c[0][1]);
	calc(f1,c[1][0],c[0][0]);calc(f2,c[0][1],c[0][0]);
	for(int i=0;i<=c[0][0];i++) f3[i]=1ll*fac[c[0][0]]*s[c[0][0]][i]%MOD;
//	for(int i=0;i<=c[1][0];i++) printf("%d%c",f1[i]," \n"[i==c[1][0]]);
//	for(int i=0;i<=c[0][1];i++) printf("%d%c",f2[i]," \n"[i==c[0][1]]);
//	for(int i=0;i<=c[0][0];i++) printf("%d%c",f3[i]," \n"[i==c[0][0]]);
	for(int i=0;i<=c[1][0];i++) for(int j=0;j<=c[0][1];j++)
		tmp[i+j]=(tmp[i+j]+1ll*f1[i]*f2[j])%MOD;
	for(int i=0;i<=c[1][0]+c[0][1];i++) for(int j=0;j<=c[0][0];j++)
		ans[i+j]=(ans[i+j]+1ll*tmp[i]*f3[j])%MOD;
	for(int i=0;i<n;i++) printf("%d%c",(n-i-cnt<0)?0:ans[n-i-cnt]," \n"[i==n-1]);
	return 0;
}