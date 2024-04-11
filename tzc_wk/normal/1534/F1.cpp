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
const int MAXN=4e5;
const int MAXM=MAXN*4;
int n,m;vector<int> ps[MAXN+5];
string s[MAXN+5];
int id(int x,int y){return (x-1)*m+y;}
int hd[MAXN+5],to[MAXM+5],nxt[MAXM+5],ec=0;
void adde(int u,int v){/*printf("%d %d\n",u,v);*/to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int dfn[MAXN+5],low[MAXN+5],tim=0,bel[MAXN+5],stk[MAXN+5],tp=0,vis[MAXN+5],cmp=0;
int deg[MAXN+5],res=0;
void tarjan(int x){
	dfn[x]=low[x]=++tim;vis[x]=1;stk[++tp]=x;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];
		if(!dfn[y]) tarjan(y),chkmin(low[x],low[y]);
		else if(vis[y]) chkmin(low[x],dfn[y]);
	} if(low[x]==dfn[x]){
//		printf("%d %d\n",x,cmp+1);
		++cmp;int o;do{
			o=stk[tp--];
			vis[o]=0;bel[o]=cmp;
		} while(o^x);
	}
}
int main(){
	scanf("%d%d",&n,&m);for(int i=1;i<=n;i++) cin>>s[i],s[i]=" "+s[i];
	for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) if(s[j][i]=='#') ps[i].pb(j);
	for(int i=0;i<=m+1;i++) ps[i].pb(n+1);
	for(int i=1;i<=m;i++) for(int j=0;j+1<ps[i].size();j++){
		int cur=ps[i][j],nxt=ps[i][j+1];
		if(nxt!=n+1) adde(id(cur,i),id(nxt,i));
		int pos=*lower_bound(ps[i-1].begin(),ps[i-1].end(),cur);
		if(pos!=n+1) adde(id(cur,i),id(pos,i-1));
		pos=*lower_bound(ps[i+1].begin(),ps[i+1].end(),cur);
		if(pos!=n+1) adde(id(cur,i),id(pos,i+1));
		if(j){
			int pre=ps[i][j-1];
			if(pre==cur-1) adde(id(cur,i),id(pre,i));
		}
	} for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
		if(s[i][j]=='.') continue;
		if(!dfn[id(i,j)]) tarjan(id(i,j));
	}
//	for(int i=1;i<=n*m;i++) printf("%d\n",bel[i]);
	for(int i=1;i<=n*m;i++) for(int e=hd[i];e;e=nxt[e]){
		int j=to[e];if(bel[i]^bel[j]) deg[bel[j]]++;
	} for(int i=1;i<=cmp;i++) res+=(!deg[i]);
	printf("%d\n",res);
	return 0;
}