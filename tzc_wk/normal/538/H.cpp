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
const int INF=0x3f3f3f3f;
int L,R,n,m,n1=INF,n2=0,l[MAXN+5],r[MAXN+5],c[MAXN+5];
int hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
void dfs(int x){
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];
		if(c[x]==3-c[y]) continue;
		else if(c[x]==c[y]) puts("IMPOSSIBLE"),exit(0);
		else c[y]=3-c[x],dfs(y);
	}
}
int main(){
	scanf("%d%d%d%d",&L,&R,&n,&m);
	for(int i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]),chkmin(n1,r[i]),chkmax(n2,l[i]);
	if(n1+n2<L) n2=L-n1;if(n1+n2>R) n1=R-n2;
	if(n1<0||n2<0) return puts("IMPOSSIBLE"),0;
	for(int i=1;i<=n;i++){
		bool flg1=(l[i]<=n1&&n1<=r[i]);
		bool flg2=(l[i]<=n2&&n2<=r[i]);
		if(!flg1&&!flg2) return puts("IMPOSSIBLE"),0;
		if(!flg1) c[i]=2;if(!flg2) c[i]=1;
	}
	for(int i=1,u,v;i<=m;i++) scanf("%d%d",&u,&v),adde(u,v),adde(v,u);
	for(int i=1;i<=n;i++) if(c[i]) dfs(i);
	for(int i=1;i<=n;i++) if(!c[i]) c[i]=1,dfs(i);
	puts("POSSIBLE");printf("%d %d\n",n1,n2);
	for(int i=1;i<=n;i++) putchar(c[i]^48);
	return 0;
}