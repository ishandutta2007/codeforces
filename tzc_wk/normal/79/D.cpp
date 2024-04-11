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
const int MAXN=1e4;
const int MAXM=100;
const int MAXK=20;
const int MAXP=1<<20;
const int INF=0x3f3f3f3f;
int n,k,m,a[MAXN+5],b[MAXN+5],l[MAXM+5],id[MAXN+5],pos[MAXK+5];
int dis[MAXN+5],d[MAXK+5][MAXK+5],cnt;
void bfs(int s){
	queue<int> q;memset(dis,-1,sizeof(dis));
	dis[s]=d[id[s]][id[s]]=0;q.push(s);
	while(!q.empty()){
		int x=q.front();q.pop();
		if(id[x]) d[id[s]][id[x]]=dis[x];
		for(int i=1;i<=m;i++){
			if(x+l[i]<=n+1){
				if(!~dis[x+l[i]]) dis[x+l[i]]=dis[x]+1,q.push(x+l[i]);
			} if(x-l[i]>=1){
				if(!~dis[x-l[i]]) dis[x-l[i]]=dis[x]+1,q.push(x-l[i]);
			}
		}
	}
}
int dp[MAXP+5];
int main(){
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1,x;i<=k;i++) scanf("%d",&x),a[x]=1;
	for(int i=1;i<=m;i++) scanf("%d",&l[i]);
	for(int i=1;i<=n+1;i++) b[i]=a[i]^a[i-1];
	for(int i=1;i<=n+1;i++) if(b[i]) id[i]=++cnt,pos[cnt]=i;
	memset(d,63,sizeof(d));
	for(int i=1;i<=n+1;i++) if(id[i]) bfs(i);
	memset(dp,63,sizeof(dp));dp[0]=0;
//	printf("%d\n",cnt);
//	for(int i=1;i<=cnt;i++) for(int j=1;j<=cnt;j++)
//		printf("%d%c",d[i][j]," \n"[j==cnt]);
	for(int i=0;i<(1<<cnt);i++){
		if(dp[i]>=INF) continue;
		for(int j=1;j<=cnt;j++) for(int l=1;l<j;l++)
			if((~i>>j-1&1)&&(~i>>l-1&1))
				chkmin(dp[i|(1<<j-1)|(1<<l-1)],dp[i]+d[j][l]);
	} printf("%d\n",(dp[(1<<cnt)-1]>=INF)?-1:dp[(1<<cnt)-1]);
	return 0;
}