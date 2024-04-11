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
const int MAXM=3e5;
int n,m,deg[MAXN+5],hd[MAXN+5],to[MAXM*2+5],nxt[MAXM*2+5],ec=1;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
bool vis[MAXM*2+5];int num=0;
void cir(int x){
	for(int &e=hd[x];e;e=nxt[e]) if(!vis[e]){
		vis[e]=vis[e^1]=1;int y=to[e];cir(y);++num;
		if(num&1) printf("%d %d\n",x,y);
		else printf("%d %d\n",y,x);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);deg[u]++;deg[v]++;
		adde(u,v);adde(v,u);
	} int pre=0;
	for(int i=1;i<=n;i++) if(deg[i]&1){
		if(pre) adde(pre,i),adde(i,pre),++m,pre=0;
		else pre=i;
	} if(m&1) adde(1,1),++m;
	printf("%d\n",m);
	for(int i=1;i<=n;i++) cir(i);
	return 0;
}