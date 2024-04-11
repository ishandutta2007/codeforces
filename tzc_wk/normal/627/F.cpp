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
const int INF=0x3f3f3f3f;
int n,hd[MAXN+5],nxt[MAXN*2+5],to[MAXN*2+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int a[MAXN+5],b[MAXN+5],posa[MAXN+5],posb[MAXN+5];
int fa[MAXN+5],deg[MAXN+5],dep[MAXN+5];
bool vis[MAXN+5],on_pth[MAXN+5];
void dfs(int x,int f){
	fa[x]=f;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		dep[y]=dep[x]+1;dfs(y,x);
	}
}
vector<int> pth;bool fnd=0;
void findpth(int x,int f,int z){
	pth.pb(x);
	if(x==z) return fnd=1,void();
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		findpth(y,x,z);if(fnd) return;
	} pth.ppb();
}
vector<int> findpth(int u,int v){
	pth.clear();fnd=0;
	findpth(u,0,v);return pth;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),posa[a[i]]=i;
	for(int i=1;i<=n;i++) scanf("%d",&b[i]),posb[b[i]]=i;
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),adde(u,v),adde(v,u);
	dfs(posb[0],0);int res=0;bool flg=1;
	for(int x=posa[0];x!=posb[0];x=fa[x]) on_pth[x]=1,swap(a[x],a[fa[x]]),res++;
	on_pth[posb[0]]=1;
//	printf("%d\n",posb[0]);
	for(int i=1;i<=n;i++) flg&=(a[i]==b[i]);
	if(flg) return printf("0 %d\n",res),0;
	//zero moves
	int dif_cnt=0,on_cnt=0;
	for(int i=1;i<=n;i++) if(a[i]!=b[i]){
		deg[i]++;deg[fa[i]]++;vis[i]=vis[fa[i]]=1;
		dif_cnt++;
	}
	for(int i=1;i<=n;i++) if(deg[i]>2) return puts("-1"),0;
	for(int i=1;i<=n;i++) on_cnt+=vis[i];
//	printf("%d %d\n",on_cnt,dif_cnt);
	if(on_cnt!=dif_cnt+1) return puts("-1"),0;
	int U=0,V=0;
	for(int i=1;i<=n;i++) if(deg[i]==1){if(!U) U=i;else if(!V) V=i;}
	vector<int> X=findpth(U,V),XX;
	pii mn=mp(INF,0);
	for(int i=1;i<=n;i++) if(vis[i]) chkmin(mn,mp(dep[i],i));
	int p=mn.se;//printf("%d\n",p);
	for(int i=0;i<X.size();i++) if(X[i]!=p) XX.pb(X[i]);
//	for(int x:XX) printf("%d ",x);printf("\n");
	int eq=-1;
	for(int i=0;i<XX.size();i++) if(b[XX[i]]==a[XX[0]]) eq=i;
	assert(~eq);
	for(int i=0;i<XX.size();i++) if(b[XX[(i+eq)%XX.size()]]!=a[XX[i]])
		return puts("-1"),0;
	ll dis=min(1ll*(eq-1)*X.size()-1+findpth(U,posa[0]).size()+findpth(V,posb[0]).size(),
			   1ll*(XX.size()-eq-1)*X.size()-1+findpth(V,posa[0]).size()+findpth(U,posb[0]).size());
	printf("%d %d %lld\n",U,V,dis);
	return 0;
}
/*
4
0 1 2 3
0 2 3 1
1 2
2 3
2 4

7
0 1 4 3 5 2 6
1 5 4 0 3 2 6
1 2
2 3
3 4
2 5
5 6
5 7
*/