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
const int MAXN=500;
const int MAXK=11;
const int INF=0x3f3f3f3f;
int n,k,ch[MAXN+5][10],ncnt=1,occ[MAXN+5];char buf[MAXN+5];
int dp[MAXN+5][MAXN+5][MAXK+2],dep[MAXN+5],siz[MAXN+5],tmp[MAXK+2];
void dfs(int x){
	siz[x]=1;
	for(int i=0;i<=dep[x];i++) dp[x][i][0]=occ[x]*(dep[x]-i);
	for(int i=0;i<10;i++) if(ch[x][i]){
		int y=ch[x][i];dep[y]=dep[x]+1;dfs(y);
		for(int j=0;j<=dep[x];j++){
			memset(tmp,63,sizeof(tmp));
			for(int u=0;u<=min(siz[x],k);u++) for(int v=0;v<=min(siz[y],k-u);v++)
				chkmin(tmp[u+v],dp[x][j][u]+min(dp[y][j][v],dp[y][dep[y]][v-1]));
			for(int u=0;u<=min(siz[x]+siz[y],k);u++) dp[x][j][u]=tmp[u];
		} siz[x]+=siz[y];
	}
//	for(int i=0;i<=dep[x];i++) for(int j=0;j<=min(siz[x],k);j++)
//		printf("%d %d %d %d\n",x,i,j,dp[x][i][j]);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1,x,len,cur;i<=n;i++){
		scanf("%s%d",buf+1,&x);len=strlen(buf+1),cur=1;
		for(int j=1;j<=len;j++){
			if(!ch[cur][buf[j]^48]) ch[cur][buf[j]^48]=++ncnt;
			cur=ch[cur][buf[j]^48];
		} occ[cur]+=x;
	} memset(dp,63,sizeof(dp));dfs(1);int ans=INF;
	for(int i=0;i<=k;i++) chkmin(ans,dp[1][0][i]);
	printf("%d\n",ans);
	return 0;
}