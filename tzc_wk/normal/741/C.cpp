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
int n,hd[MAXN*2+5],nxt[MAXN*4+5],to[MAXN*4+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int col[MAXN*2+5],u[MAXN+5],v[MAXN+5];
void dfs(int x){
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];
		if(!col[y]) col[y]=3-col[x],dfs(y);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) adde(i*2-1,i*2),adde(i*2,i*2-1);
	for(int i=1;i<=n;i++) scanf("%d%d",&u[i],&v[i]),adde(u[i],v[i]),adde(v[i],u[i]);
	for(int i=1;i<=n*2;i++) if(!col[i]) col[i]=1,dfs(i);
	for(int i=1;i<=n;i++) printf("%d %d\n",col[u[i]],col[v[i]]);
	return 0;
}