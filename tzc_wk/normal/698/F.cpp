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
	template<typename T> void print(T x,char c){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1e6;
const int MOD=1e9+7;
int pr[MAXN/8+5],prcnt=0,mnp[MAXN+5];
bitset<MAXN+5> vis;
void sieve(int n){
	for(int i=2;i<=n;i++){
		if(!vis[i]) pr[++prcnt]=i,mnp[i]=i;
		for(int j=1;j<=prcnt&&pr[j]*i<=n;j++){
			vis[pr[j]*i]=1;mnp[pr[j]*i]=pr[j];
			if(i%pr[j]==0) break;
		}
	}
}
int n,a[MAXN+5],fac[MAXN+5],mul[MAXN+5],num[MAXN+5];
int to1[MAXN+5],to2[MAXN+5];
int c1[MAXN+5],c2[MAXN+5];
vector<int> pf[MAXN+5];
int main(){
	scanf("%d",&n);sieve(n);
	for(int i=2;i<=n;i++){
		int tmp=i;mul[i]=1;
		while(tmp^1){
			int p=mnp[tmp];
			while(tmp%p==0) tmp/=p;
			pf[i].pb(p);mul[i]*=p;
		} c1[mul[i]]++;
	} pf[1].pb(1);num[1]=1;c2[1]++;
	for(int i=1;i<=prcnt;i++) num[pr[i]]=n/pr[i],c2[num[pr[i]]]++;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) if(a[i]){
		if(pf[i].size()!=pf[a[i]].size()) return puts("0"),0;
		for(int j=0;j+1<pf[i].size();j++) if(pf[i][j]!=pf[i][j]) return puts("0"),0;
		int x=pf[i].back(),y=pf[a[i]].back();
		if(num[x]!=num[y]) return puts("0"),0;
		if(to1[x]&&to1[x]!=y) return puts("0"),0;
		if(to2[y]&&to2[y]!=x) return puts("0"),0;
		if(!to1[x]&&!to2[y]) c2[num[x]]--;
		to1[x]=y;to2[y]=x;c1[mul[a[i]]]--;
	} int res=1;
	for(int i=(fac[0]=1);i<=n;i++) fac[i]=1ll*fac[i-1]*i%MOD;
	for(int i=1;i<=n;i++) res=1ll*res*fac[c1[i]]%MOD;
	for(int i=1;i<=n;i++) res=1ll*res*fac[c2[i]]%MOD;
	printf("%d\n",res);
	return 0;
}