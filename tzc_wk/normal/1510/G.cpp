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
const int MAXN=100;
const int INF=0x3f3f3f3f;
int n,k,hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int dp[MAXN+5][MAXN+5][2],tmp[MAXN+5][2],siz[MAXN+5];
vector<pair<pii,int> > pth[MAXN+5][MAXN+5][2],tmp_pth[MAXN+5][2];
void dfs(int x){
	dp[x][0][0]=-1;dp[x][0][1]=-2;
	dp[x][1][0]=dp[x][1][1]=0;siz[x]=1;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];dfs(y);memset(tmp,63,sizeof(tmp));
		for(int i=0;i<=siz[x]+siz[y];i++){
			tmp_pth[i][0].clear();tmp_pth[i][1].clear();
		}
		for(int i=1;i<=siz[x];i++) for(int j=0;j<=siz[y];j++){
			if(tmp[i+j][0]>dp[x][i][0]+dp[y][j][1]+2){
				tmp[i+j][0]=dp[x][i][0]+dp[y][j][1]+2;
				tmp_pth[i+j][0]=pth[x][i][0];
				tmp_pth[i+j][0].pb(mp(mp(y,j),1));
			}
			if(tmp[i+j][0]>dp[x][i][1]+dp[y][j][0]+1){
				tmp[i+j][0]=dp[x][i][1]+dp[y][j][0]+1;
				tmp_pth[i+j][0]=pth[x][i][1];
				tmp_pth[i+j][0].pb(mp(mp(y,j),0));
			}
			if(tmp[i+j][1]>dp[x][i][1]+dp[y][j][1]+2){
				tmp[i+j][1]=dp[x][i][1]+dp[y][j][1]+2;
				tmp_pth[i+j][1]=pth[x][i][1];
				tmp_pth[i+j][1].pb(mp(mp(y,j),1));
			}
		}
		for(int i=2;i<=siz[x]+siz[y];i++){
			dp[x][i][0]=tmp[i][0];
			dp[x][i][1]=tmp[i][1];
			pth[x][i][0]=tmp_pth[i][0];
			pth[x][i][1]=tmp_pth[i][1];
		} siz[x]+=siz[y];
	}
//	for(int i=0;i<=siz[x];i++){
//		printf("%d %d %d %d\n",x,i,dp[x][i][0],dp[x][i][1]);
//		for(pair<pii,int> u:pth[x][i][0]) printf("%d,%d,%d ",u.fi.fi,u.fi.se,u.se);printf("\n");
//		for(pair<pii,int> u:pth[x][i][1]) printf("%d,%d,%d ",u.fi.fi,u.fi.se,u.se);printf("\n");
//	}
}
vector<int> ans;
void dump(int x,int y,int z){
//	printf("%d %d %d\n",x,y,z);
	if(!y) return;ans.pb(x);if(y==1) return;
	for(int i=0;i<pth[x][y][z].size();i++){
		pair<pii,int> pp=pth[x][y][z][i];
		if(!pp.fi.se) continue;
		if(pp.se==1) dump(pp.fi.fi,pp.fi.se,pp.se),ans.pb(x);
	}
	for(int i=0;i<pth[x][y][z].size();i++){
		pair<pii,int> pp=pth[x][y][z][i];
		if(!pp.fi.se) continue;
		if(pp.se==0) dump(pp.fi.fi,pp.fi.se,pp.se);
	}
}
void solve(){
	scanf("%d%d",&n,&k);
	memset(hd,0,sizeof(hd));memset(to,0,sizeof(to));ec=0;
	for(int i=2,fa;i<=n;i++) scanf("%d",&fa),adde(fa,i);
	memset(dp,63,sizeof(dp));
	for(int i=1;i<=n;i++) for(int j=0;j<=n;j++){
		pth[i][j][0].clear();pth[i][j][1].clear();
	} dfs(1);ans.clear();
	printf("%d\n",min(dp[1][k][0],dp[1][k][1]));
	if(dp[1][k][0]<dp[1][k][1]) dump(1,k,0);
	else dump(1,k,1);
	for(int u:ans) printf("%d ",u);printf("\n");
}
int main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve();
	return 0;
}
/*
3
6 2
1 1 2 2 3
6 6
1 1 2 2 3
6 4
1 2 3 4 5
*/