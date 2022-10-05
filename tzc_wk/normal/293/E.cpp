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
const int MAXN=1e5;
int n,L,W,hd[MAXN+5],to[MAXN*2+5],val[MAXN*2+5],nxt[MAXN*2+5],ec=0;
void adde(int u,int v,int w){to[++ec]=v;val[ec]=w;nxt[ec]=hd[u];hd[u]=ec;}
int mx[MAXN+5],siz[MAXN+5],cent=0;bool vis[MAXN+5];
void findcent(int x,int f,int totsiz){
	mx[x]=0;siz[x]=1;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f||vis[y]) continue;
		findcent(y,x,totsiz);siz[x]+=siz[y];
		chkmax(mx[x],siz[y]);
	} chkmax(mx[x],totsiz-siz[x]);
	if(!cent||mx[cent]>mx[x]) cent=x;
}
int dep[MAXN+5],sum[MAXN+5],t[MAXN+5];ll ans=0;
void add(int x,int v){x++;for(int i=x;i<=n+1;i+=(i&-i)) t[i]+=v;}
int query(int x){int ret=0;x++;for(int i=x;i;i&=(i-1)) ret+=t[i];return ret;}
struct node{
	int s,d;
	node(int _s=0,int _d=0):s(_s),d(_d){}
	bool operator <(const node &rhs) const{return s<rhs.s;}
};
int subsiz[MAXN+5];
vector<node> sub,all;
void getdis(int x,int f){
	sub.pb(node(sum[x],dep[x]));all.pb(node(sum[x],dep[x]));
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e],z=val[e];if(y==f||vis[y]) continue;
		dep[y]=dep[x]+1;sum[y]=sum[x]+z;getdis(y,x);
	}
}
void divcent(int x){
//	printf("divcent %d\n",x);
	vis[x]=1;dep[x]=sum[x]=0;all.clear();
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e],z=val[e];if(vis[y]) continue;
		dep[y]=1;sum[y]=z;sub.clear();getdis(y,x);
		sort(sub.begin(),sub.end());int cur=0;
		for(int i=sub.size()-1;~i;i--){
			while(cur<sub.size()&&sub[cur].s+sub[i].s<=W){
				add(sub[cur].d,1);cur++;
			} int upb=L-sub[i].d;
			if(upb>=0) ans-=query(upb);
		} for(int i=0;i<cur;i++) add(sub[i].d,-1);
		subsiz[y]=sub.size();
	} all.pb(node(0,0));sort(all.begin(),all.end());
	int cur=0;
	for(int i=all.size()-1;~i;i--){
		while(cur<all.size()&&all[cur].s+all[i].s<=W){
			add(all[cur].d,1);cur++;
		} int upb=L-all[i].d;
		if(upb>=0) ans+=query(upb);
	} for(int i=0;i<cur;i++) add(all[i].d,-1);
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(vis[y]) continue;
		cent=0;findcent(y,x,subsiz[y]);divcent(cent);
	}
}
int main(){
	scanf("%d%d%d",&n,&L,&W);
	for(int i=2,f,w;i<=n;i++){
		scanf("%d%d",&f,&w);
		adde(i,f,w);adde(f,i,w);
	} findcent(1,0,n);divcent(cent);
	printf("%lld\n",ans-n>>1);
	return 0;
}