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
const int MAXN=100;
const int MAXK=400;
const int MAX_ID=10201;
int n,m,mod,fa[MAX_ID+5];char s[MAXN+5][MAXN+5];
int qpow(int x,int e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%mod) if(e&1) ret=1ll*ret*x%mod;
	return ret;
}
pii rid[MAX_ID+5];bool flg[2];
int get(int x,int y){return (x-1)*(m+1)+y;}
pii getpos(int x){x--;return mp(x/(m+1)+1,x%(m+1)+1);}
int find(int x){return (!fa[x])?x:fa[x]=find(fa[x]);}
void merge(int x,int y){
	x=find(x);y=find(y);if(x^y) fa[x]=y;
	else flg[(getpos(x).fi+getpos(x).se)&1]=0;
}
int id[MAX_ID+5],a[MAXK+5][MAXK+5],idn=0,ans=0;
void add(int x,int y){
	if(x==y) return;x--;y--;
	a[x][y]=(a[x][y]+mod-1)%mod;
	a[y][x]=(a[y][x]+mod-1)%mod;
	a[x][x]=(a[x][x]+1)%mod;
	a[y][y]=(a[y][y]+1)%mod;
}
int getdet(){
	int sgn=1;
	for(int i=1;i<idn;i++){
		int t=i;
		for(int j=i+1;j<idn;j++) if(a[j][i]) t=j;
		if(t^i) sgn=-sgn;
		for(int j=i;j<idn;j++) swap(a[i][j],a[t][j]);
		int iv=qpow(a[i][i],mod-2);
		for(int j=i+1;j<idn;j++){
			int mul=1ll*(mod-a[j][i])*iv%mod;
			for(int k=i;k<idn;k++) a[j][k]=(a[j][k]+1ll*mul*a[i][k])%mod;
		}
	} int res=(sgn+mod)%mod;
	for(int i=1;i<idn;i++) res=1ll*res*a[i][i]%mod;
	return res;
}
int main(){
	scanf("%d%d%d",&n,&m,&mod);flg[0]=flg[1]=1;
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
		if(s[i][j]=='/') merge(get(i+1,j),get(i,j+1));
		if(s[i][j]=='\\') merge(get(i,j),get(i+1,j+1));
	}
	if(flg[1]){
		for(int i=1;i<=n+1;i++) for(int j=1;j<=m+1;j++)
			if(find(get(i,j))==get(i,j)&&((i+j)&1))
				id[get(i,j)]=++idn;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(s[i][j]=='*'){
			if((i+j)&1) add(id[find(get(i,j))],id[find(get(i+1,j+1))]);
			else add(id[find(get(i+1,j))],id[find(get(i,j+1))]);
		} ans=(ans+getdet())%mod;
	} memset(a,0,sizeof(a));idn=0;
	if(flg[0]){
		for(int i=1;i<=n+1;i++) for(int j=1;j<=m+1;j++)
			if(find(get(i,j))==get(i,j)&&(~(i+j)&1))
				id[get(i,j)]=++idn;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(s[i][j]=='*'){
			if(~(i+j)&1) add(id[find(get(i,j))],id[find(get(i+1,j+1))]);
			else add(id[find(get(i+1,j))],id[find(get(i,j+1))]);
		} ans=(ans+getdet())%mod;
	} printf("%d\n",ans);
	return 0;
}
/*
2 2 5
/\
\/
*/