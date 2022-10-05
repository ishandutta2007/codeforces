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
const int MAXN=5000;
const int MAXV=10002;//remember to calculate the number of vertices and edges
const int MAXE=2e4*2;
const int INF=0x3f3f3f3f;
int n,m,d,S=10001,T=10002,p[MAXN+5],c[MAXN+5],k[MAXN+5],ret[MAXN+5];
vector<int> pos[MAXN+5];bool book[MAXN+5];
int hd[MAXV+5],nxt[MAXE+5],to[MAXE+5],cap[MAXE+5],ec=1;
void adde(int u,int v,int f){
	to[++ec]=v;cap[ec]=f;nxt[ec]=hd[u];hd[u]=ec;
	to[++ec]=u;cap[ec]=0;nxt[ec]=hd[v];hd[v]=ec;
}
int dep[MAXV+5],now[MAXV+5];
bool getdep(){
	memset(dep,-1,sizeof(dep));dep[S]=0;
	queue<int> q;q.push(S);now[S]=hd[S];
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e],z=cap[e];
			if(z&&!~dep[y]){
				dep[y]=dep[x]+1;now[y]=hd[y];
				q.push(y);
			}
		}
	} return ~dep[T];
}
int getflow(int x,int f){
	if(x==T) return f;int res=0;
	for(int &e=now[x];e;e=nxt[e]){
		int y=to[e],z=cap[e];
		if(dep[y]==dep[x]+1&&z){
			int w=getflow(y,min(f-res,z));
			cap[e]-=w;cap[e^1]+=w;res+=w;
			if(res==f) return res;
		}
	} return res;
}
int dinic(){
	int ret=0;
	while(getdep()) ret+=getflow(S,INF);
	return ret;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) adde(S,i,1);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]),pos[p[i]].pb(i);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	scanf("%d",&d);for(int i=1;i<=d;i++) scanf("%d",&k[i]),book[k[i]]=1;
	int ans=-1,sum_fl=0;
	for(int i=d;i;i--){
		while(1){
			sum_fl+=dinic();//printf("%d %d\n",ans,sum_fl);
			if(sum_fl!=ans+1) break;ans++;adde(ans+1+m,T,1);
			for(int j:pos[ans]) if(!book[j]) adde(c[j],ans+1+m,1);
		} ret[i]=ans;
		if(p[k[i]]<=ans) adde(c[k[i]],p[k[i]]+1+m,1);
		book[k[i]]=0;
	}
	for(int i=1;i<=d;i++) printf("%d\n",ret[i]);
	return 0;
}