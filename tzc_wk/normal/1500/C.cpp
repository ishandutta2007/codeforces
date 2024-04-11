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
using namespace fastio;
const int MAXN=1500;
const u64 BS=131;
int n,m,a[MAXN+5][MAXN+5],b[MAXN+5][MAXN+5],deg[MAXN*2+5];
u64 pw[MAXN+5];map<u64,int> id;int cnt=0;
queue<int> qq[MAXN+5];
int hd[MAXN*2+5],to[MAXN*MAXN+5],nxt[MAXN*MAXN+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
bool vis[MAXN*2+5];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) read(a[i][j]);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) read(b[i][j]);
	for(int i=(pw[0]=1);i<=MAXN;i++) pw[i]=pw[i-1]*BS;
	for(int i=1;i<=n;i++){
		u64 hs=0;
		for(int j=1;j<=m;j++) hs+=pw[j]*a[i][j];
		if(!id.count(hs)) id[hs]=++cnt;
		qq[id[hs]].push(i);a[i][m+1]=i;
	}
	for(int i=1;i<=n;i++){
		u64 hs=0;
		for(int j=1;j<=m;j++) hs+=pw[j]*b[i][j];
		if(!id.count(hs)) return puts("-1"),0;
		else{
			int ind=id[hs];
			b[i][m+1]=qq[ind].front();qq[ind].pop();
		}
//		printf("%d\n",b[i][m+1]);
	}
	for(int i=1;i<n;i++) for(int j=1;j<=m+1;j++){
		if(b[i][j]<b[i+1][j]) adde(j,i+m+1);
		if(b[i][j]>b[i+1][j]) adde(i+m+1,j),deg[j]++;
	} queue<int> q;
	for(int j=1;j<=m+1;j++) if(!deg[j]) q.push(j),vis[j]=1;
	vector<int> res;
	while(!q.empty()){
		int x=q.front();q.pop();if(x<=m) res.pb(x);
//		printf("x=%d\n",x);
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e];
			if(y<=m+1){
				if(!--deg[y]) vis[y]=1,q.push(y);
			} else {
				if(!vis[y]) vis[y]=1,q.push(y);
			}
		} if(vis[m+1]) break;
	} if(!vis[m+1]) puts("-1");
	else{
		printf("%d\n",res.size());
		for(int i=(int)(res.size())-1;~i;i--) printf("%d ",res[i]);
	}
	return 0;
}
/*
3 3
1 1 1
2 2 2
1 1 1
1 1 1
1 1 1
2 2 2
*/