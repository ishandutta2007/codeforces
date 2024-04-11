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
const int MAXN=1e6;
int n,hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int dep[MAXN+5],mxdep[MAXN+5],wson[MAXN+5];
void dfs1(int x=1,int f=0){
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		dep[y]=mxdep[y]=dep[x]+1;dfs1(y,x);
		if(mxdep[y]>mxdep[x]) mxdep[x]=mxdep[y],wson[x]=y;
	}
}
vector<int> dp[MAXN+5];
int ans[MAXN+5];
void dfs2(int x=1,int f=0){
	if(!wson[x]) dp[x].pb(1),ans[x]=0;
	else{
		dfs2(wson[x],x);swap(dp[x],dp[wson[x]]);
		ans[x]=ans[wson[x]];dp[x].pb(1);
		if(dp[x][ans[x]]==1) ans[x]=mxdep[x]-dep[x];
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e];if(y==f||y==wson[x]) continue;dfs2(y,x);
			for(int i=0;i<=mxdep[y]-dep[y];i++){
				int tmp=mxdep[x]-dep[x]-(mxdep[y]-dep[y]-i)-1;
				dp[x][tmp]+=dp[y][i];
				if(dp[x][tmp]>dp[x][ans[x]]||(dp[x][tmp]==dp[x][ans[x]]&&tmp>ans[x]))
					ans[x]=tmp;
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		adde(u,v);adde(v,u);
	} dfs1();dfs2();
	for(int i=1;i<=n;i++) printf("%d\n",mxdep[i]-dep[i]-ans[i]);
	return 0;
}