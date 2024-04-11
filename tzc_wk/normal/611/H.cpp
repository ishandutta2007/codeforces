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
const int MAXV=30;
const int MAXE=300*2;
const int INF=0x3f3f3f3f;
int n,m,p[8],q[8],cnt[8];
int S=29,T=30,hd[MAXV+5],to[MAXE+5],nxt[MAXE+5],cap[MAXE+5],ec=1;
void init(){memset(hd,0,sizeof(hd));ec=1;}
void adde(int u,int v,int f){
	to[++ec]=v;cap[ec]=f;nxt[ec]=hd[u];hd[u]=ec;
	to[++ec]=u;cap[ec]=0;nxt[ec]=hd[v];hd[v]=ec;
} int dep[MAXV+5],now[MAXV+5];
bool getdep(){
	memset(dep,-1,sizeof(dep));dep[S]=0;
	queue<int> q;q.push(S);now[S]=hd[S];
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e],z=cap[e];
			if(!~dep[y]&&z){
				dep[y]=dep[x]+1;
				q.push(y);now[y]=hd[y];
			}
		}
	} return ~dep[T];
}
int getflow(int x,int f){
	if(x==T) return f;int ret=0;
	for(int &e=now[x];e;e=nxt[e]){
		int y=to[e],z=cap[e];
		if(dep[y]==dep[x]+1&&z){
			int w=getflow(y,min(f-ret,z));
			cap[e]-=w;cap[e^1]+=w;ret+=w;
			if(ret==f) return ret;
		}
	} return ret;
}
int dinic(){
	int ret=0;
	while(getdep()) ret+=getflow(S,INF);
	return ret;
}
int num[8][8],cc[8][8],pru[8],deg[8],vis[8];
void solve(){
	memset(deg,0,sizeof(deg));
	memset(vis,0,sizeof(vis));
	memset(cc,0,sizeof(cc));
	for(int i=1;i<=m-2;i++) deg[pru[i]]++;
	for(int i=1;i<=m-2;i++){
		int pos=0;
		for(int j=1;j<=m;j++){
			if(!deg[j]&&!vis[j]){pos=j;break;}
		} cc[min(pos,pru[i])][max(pos,pru[i])]++;
//		eprintf("%d %d\n",pos,pru[i]);
		deg[pru[i]]--;vis[pos]=1;
	} int u1=1,u2=m;
	while(vis[u1]) u1++;
	while(vis[u2]) u2--;
	cc[u1][u2]++;
//	eprintf("%d %d\n",u1,u2);
	int cur=0;init();
	for(int i=1;i<=m;i++) for(int j=i;j<=m;j++){
		if(cc[i][j]>num[i][j]) return;cur++;
		adde(S,cur,num[i][j]-cc[i][j]);
		adde(cur,m*(m+1)/2+i,INF);
		adde(cur,m*(m+1)/2+j,INF);
	} for(int i=1;i<=m;i++) adde(m*(m+1)/2+i,T,cnt[i]-1);
	if(dinic()==n-m){
		for(int i=1;i<=m;i++) for(int j=i;j<=m;j++){
			if(cc[i][j]) printf("%d %d\n",p[i],p[j]);
		}
		for(int i=1;i<=m;i++) q[i]=p[i];cur=0;
		for(int i=1;i<=m;i++) for(int j=i;j<=m;j++){
			cur++;
			for(int e=hd[cur];e;e=nxt[e]){
				int y=to[e],z=cap[e^1];
				if(y==S) continue;
				if(y-m*(m+1)/2==i){
					while(z--) printf("%d %d\n",++q[i],p[j]);
				} else {
					while(z--) printf("%d %d\n",++q[j],p[i]);
				}
			}	
		}
		exit(0);
	}
}
void dfs(int x){
	if(x==m-1) return solve();
	for(int i=1;i<=m;i++) pru[x]=i,dfs(x+1);
}
int main(){
	scanf("%d",&n);for(int cur=1;cur<=n;cur*=10) p[++m]=cur;
	for(int i=1;i<m;i++) cnt[i]=p[i+1]-p[i];cnt[m]=n-p[m]+1;
	for(int i=1;i<n;i++){
		static char s1[9],s2[9];
		scanf("%s%s",s1+1,s2+1);
		int l1=strlen(s1+1),l2=strlen(s2+1);
		if(l1>l2) l1^=l2^=l1^=l2;
		num[l1][l2]++;
	} if(m==1){
		if(num[1][1]!=n-1) return puts("-1"),0;
		for(int i=1;i<n;i++) printf("%d %d\n",i,i+1);
		return 0;
	} dfs(1);puts("-1");
	return 0;
}