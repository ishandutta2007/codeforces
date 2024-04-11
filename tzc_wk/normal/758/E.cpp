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
const int MAXN=2e5;
int n,hd[MAXN+5],to[MAXN*2+5],W[MAXN*2+5],P[MAXN*2+5],nxt[MAXN*2+5],ec=0;
void adde(int u,int v,int w,int p){to[++ec]=v;W[ec]=w;P[ec]=p;nxt[ec]=hd[u];hd[u]=ec;}
int dep[MAXN+5],dfn[MAXN+5],edt[MAXN+5],tim;
int upw[MAXN+5],upp[MAXN+5],del[MAXN+5],fa[MAXN+5];
ll sumw[MAXN+5];
void dfs0(int x,int f){
	dfn[x]=++tim;fa[x]=f;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e],w=W[e],p=P[e];if(y==f) continue;
		dep[y]=dep[x]+1;dfs0(y,x);sumw[x]+=sumw[y]+w;
		upw[y]=w;upp[y]=p;
	} edt[x]=tim;
}
priority_queue<pii> q[MAXN+5];
void merge(priority_queue<pii> &x,priority_queue<pii> &y){
	if(x.size()<y.size()) swap(x,y);
	while(!y.empty()){
		pii p=y.top();y.pop();
		x.push(p);
	}
}
ll t[MAXN+5];
void add(int x,int v){for(int i=x;i<=n;i+=(i&(-i))) t[i]+=v;}
ll query(int x){ll ret=0;for(int i=x;i;i&=(i-1)) ret+=t[i];return ret;}
ll getsum(int x){return sumw[x]-(query(edt[x])-query(dfn[x]));}
void dfs(int x,int f){
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		dfs(y,x);merge(q[x],q[y]);
	}
	if(x!=1&&getsum(x)>upp[x]){
		ll dif;
		while(!q[x].empty()&&(dif=getsum(x)-upp[x])>0){
			pii p=q[x].top();q[x].pop();int y=p.se;
			int can=min((ll)upw[y]-del[y]-1,upp[y]-del[y]-getsum(y));
			if(dif>=can) del[y]+=can,add(dfn[y],can);
			else del[y]+=dif,add(dfn[y],dif),q[x].push(p);
		} //printf("%d %d\n",x,getsum(x));
		if(q[x].empty()&&getsum(x)>upp[x]) puts("-1"),exit(0);
	} q[x].push(mp(dep[x],x));
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v,w,p;i<n;i++){
		scanf("%d%d%d%d",&u,&v,&w,&p);
		adde(u,v,w,p);adde(v,u,w,p);
	} dfs0(1,0);dfs(1,0);printf("%d\n",n);
	for(int i=1;i<=(n-1<<1);i+=2){
		int pt=(dep[to[i]]>dep[to[i+1]])?to[i]:to[i+1];
		printf("%d %d %d %d\n",to[i+1],to[i],upw[pt]-del[pt],upp[pt]-del[pt]);
	}
	return 0;
}