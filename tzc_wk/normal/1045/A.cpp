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
const int MAXV=3e4;
const int MAXE=1.5e5*2;
const int INF=0x3f3f3f3f;
const int MAXN=5e3;
int n,m,S=29999,T=3e4;
int hd[MAXV+5],to[MAXE+5],nxt[MAXE+5],cap[MAXE+5],ec=1;
void adde(int u,int v,int f){
//	printf("%d %d %d\n",u,v,f);
	to[++ec]=v;cap[ec]=f;nxt[ec]=hd[u];hd[u]=ec;
	to[++ec]=u;cap[ec]=0;nxt[ec]=hd[v];hd[v]=ec;
}
int dep[MAXV+5],now[MAXV+5];
bool getdep(){
	memset(dep,-1,sizeof(dep));dep[S]=0;
	queue<int> q;q.push(S);now[S]=hd[S];
	while(!q.empty()){
		int x=q.front();q.pop();now[x]=hd[x];
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e],z=cap[e];
			if(!~dep[y]&&z){
				dep[y]=dep[x]+1;
				now[y]=hd[y];q.push(y);
			}
		}
	} return ~dep[T];
}
int getflow(int x,int f){
	if(x==T) return f;int ret=0;
	for(int &e=now[x];e;e=nxt[e]){
		int y=to[e],z=cap[e];
		if(z&&dep[y]==dep[x]+1){
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
int ps[MAXN*4+5],leaf[MAXN+5],opt[MAXN+5];
void build(int k,int l,int r){
	if(l==r) return leaf[l]=k,ps[k]=l,void();
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	adde(k+n,(k<<1)+n,INF);adde(k+n,(k<<1|1)+n,INF);
}
void connect(int k,int l,int r,int ql,int qr,int id){
	if(ql<=l&&r<=qr) return adde(id,k+n,1),void();int mid=l+r>>1;
	if(qr<=mid) connect(k<<1,l,mid,ql,qr,id);
	else if(ql>mid) connect(k<<1|1,mid+1,r,ql,qr,id);
	else connect(k<<1,l,mid,ql,mid,id),connect(k<<1|1,mid+1,r,mid+1,qr,id);
}
int by[MAXN+5];
void walk(int k,int id){
	if(ps[k]) return by[ps[k]]=id,void();
//	printf("walk %d %d\n",k,id);
	for(int e=hd[k+n];e;e=nxt[e]){
		if(to[e]!=(k<<1)+n&&to[e]!=(k<<1|1)+n) continue;
//		printf("%d %d %d\n",e,to[e],cap[e^1]);
		if(!cap[e^1]) continue;
		cap[e^1]--;walk(to[e]-n,id);
		return;
	}
}
int main(){
	scanf("%d%d",&n,&m);build(1,1,m);
	for(int i=1;i<=n;i++){
		scanf("%d",&opt[i]);
		if(opt[i]==0){
			int len;scanf("%d",&len);
			adde(S,i,1);
			while(len--){
				int x;scanf("%d",&x);
				adde(i,leaf[x]+n,1);
			}
		} else if(opt[i]==1){
			int l,r;scanf("%d%d",&l,&r);
			adde(S,i,1);connect(1,1,m,l,r,i);
		} else {
			int a,b,c;scanf("%d%d%d",&a,&b,&c);
			adde(S,i,2);adde(i,leaf[a]+n,1);
			adde(i,leaf[b]+n,1);adde(i,leaf[c]+n,1);
		}
	}
	for(int i=1;i<=m;i++) adde(leaf[i]+n,T,1);
	printf("%d\n",dinic());
	for(int i=1;i<=n;i++) if(opt[i]==0){
		for(int e=hd[i];e;e=nxt[e]){
			if(to[e]!=S&&cap[e^1]==1){
				by[ps[to[e]-n]]=i;
			}
		}
	}
	for(int i=1;i<=n;i++) if(opt[i]==1){
		int fl=-1;
		for(int e=hd[i];e;e=nxt[e]) (to[e]==S)&&(fl=cap[e]);
//		printf("%d\n",fl);
		assert(~fl);
		if(fl){
			for(int e=hd[i];e;e=nxt[e]) if((to[e]^S)&&cap[e^1])
				walk(to[e]-n,i); 
		}
	}
	for(int i=1;i<=n;i++) if(opt[i]==2){
		int fl=-1;
		for(int e=hd[i];e;e=nxt[e]) (to[e]==S)&&(fl=cap[e]);
		assert(~fl);
		for(int e=hd[i];e;e=nxt[e]) if((to[e]^S)&&cap[e^1]){
			by[ps[to[e]-n]]=i;
		}
		if(fl&1){
			for(int e=hd[i];e;e=nxt[e]) if(to[e]^S&&!cap[e^1]){
				by[ps[to[e]-n]]=i;break;
			}
		}
	}
	for(int i=1;i<=m;i++) if(by[i]) printf("%d %d\n",by[i],i);
	return 0;
}