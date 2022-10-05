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
const int MAXN=200;
const int MAXM=2000;
int n,m,dis[MAXN+5][MAXN+5];
struct rel{int opt,a,b;} x[MAXM+5];
int main(){
	scanf("%d%d",&n,&m);memset(dis,63,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x[i].a,&x[i].b,&x[i].opt);
		if(x[i].opt==0) chkmin(dis[x[i].a][x[i].b],1),chkmin(dis[x[i].b][x[i].a],1);
		else chkmin(dis[x[i].a][x[i].b],1),chkmin(dis[x[i].b][x[i].a],-1);
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		chkmin(dis[i][j],dis[i][k]+dis[k][j]);
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		if(dis[i][j]>dis[i][k]+dis[k][j]) return puts("NO"),0;
//	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) printf("%d%c",dis[i][j],(j==n)?'\n':' ');
	int pos=0,ret=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(dis[i][x[j].a]==dis[i][x[j].b]) return puts("NO"),0;
		} int mx=0;
		for(int j=1;j<=n;j++) chkmax(mx,dis[i][j]);
		if(ret<mx) ret=mx,pos=i;
	} puts("YES");printf("%d\n",ret);
	int mn=0x3f3f3f3f;
	for(int i=1;i<=n;i++) chkmin(mn,dis[pos][i]);
	for(int i=1;i<=n;i++) printf("%d ",dis[pos][i]-mn);
	return 0;
}