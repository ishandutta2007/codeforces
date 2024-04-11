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
const int MAXN=65536;
const int MAXP=2048;
int n,qu,a[MAXN+5],hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int dep[MAXN+5],fa[MAXN+5][10];
void dfs0(int x,int f){
	fa[x][0]=f;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		dep[y]=dep[x]+1;dfs0(y,x);
	}
}
int mx[MAXN+5][258],mxv[258];
int ch[MAXP+5][2],ncnt=0,rt=0;
void insert(int &k,int d,int v){
	if(!k) k=++ncnt;if(!~d) return;
	insert(ch[k][v>>d&1],d-1,v);
}
int query(int k,int d,int v){
	if(!~d) return 0;
	if(ch[k][~v>>d&1]) return query(ch[k][~v>>d&1],d-1,v)|(1<<d);
	else return query(ch[k][v>>d&1],d-1,v);
}
void clear(){memset(ch,0,sizeof(ch));ncnt=rt=0;}
int main(){
	scanf("%d%d",&n,&qu);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),adde(u,v),adde(v,u);dfs0(1,0);
	for(int i=1;i<=8;i++) for(int j=1;j<=n;j++) fa[j][i]=fa[fa[j][i-1]][i-1];
	for(int i=1;i<=n;i++){
		clear();memset(mxv,0,sizeof(mxv));
		for(int j=i,stp=0;j&&stp<256;j=fa[j][0],stp++){
			chkmax(mxv[a[j]>>8],stp^(a[j]&255));
			insert(rt,7,a[j]>>8);
		}
		for(int j=0;j<256;j++){
			int p=query(rt,7,j);
			mx[i][j]=(p<<8)|mxv[p^j];
		}
	} while(qu--){
		int u,v,p;scanf("%d%d",&u,&v);p=v;int cur=0,res=0;
		while(dep[p]-dep[u]>255) chkmax(res,mx[p][cur]),p=fa[p][8],++cur;
		while(p^u) chkmax(res,a[p]^(dep[v]-dep[p])),p=fa[p][0];
		chkmax(res,a[u]^(dep[v]-dep[u]));printf("%d\n",res);
	}
	return 0;
}