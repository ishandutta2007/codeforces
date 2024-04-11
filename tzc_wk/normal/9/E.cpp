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
const int MAXN=50;
int n,m,pc=0,deg[MAXN+5],ed=0,siz=0;bool vis[MAXN+5];
int hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0;
pii p[MAXN+5];
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
void dfs(int x,int pre){
	if(vis[x]){
		if(siz!=n) puts("NO"),exit(0);
		else puts("YES\n0"),exit(0);
		return;
	} vis[x]=1;siz++;ed=x;
	for(int e=hd[x];e;e=nxt[e]) if(to[e]!=pre) dfs(to[e],x);
}
int main(){
	scanf("%d%d",&n,&m);if(m>n) return puts("NO"),0;
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		deg[u]++;deg[v]++;
		adde(u,v),adde(v,u);
	}
	for(int i=1;i<=n;i++) if(deg[i]>=3) return puts("NO"),0;
	for(int i=1;i<=n;i++){
		if(!deg[i]) p[++pc]=mp(i,i);
		else if(deg[i]==1&&!vis[i]){
			siz=0;ed=0;dfs(i,0);
			p[++pc]=mp(i,ed);
		}
	}
	for(int i=1;i<=n;i++) if(!vis[i]){siz=0;dfs(i,0);}
	printf("YES\n");
//	for(int i=1;i<=pc;i++) printf("%d %d\n",p[i].fi,p[i].se);
	priority_queue<pii,vector<pii>,greater<pii> > q;
	for(int i=1;i<=pc;i++) q.push(p[i]);
	vector<pii> ret;
	while(!q.empty()){
		if(q.size()==1){pii pp=q.top();ret.pb(pp);break;}
		pii p1=q.top();q.pop();pii p2=q.top();q.pop();
		ret.pb(mp(p1.fi,p2.fi));q.push(mp(min(p1.se,p2.se),max(p1.se,p2.se)));
	}
	sort(ret.begin(),ret.end());
	printf("%d\n",ret.size());
	for(int i=0;i<ret.size();i++) printf("%d %d\n",ret[i].fi,ret[i].se);
	return 0;
}