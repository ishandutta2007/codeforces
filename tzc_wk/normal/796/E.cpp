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
const int MAXN=1e3;
const int MAXK=50;
int n,n1,n2,p,k,dp[2][MAXN+5][MAXK+3][MAXK+3];
int isa[MAXN+5],isb[MAXN+5];
int main(){
	scanf("%d%d%d",&n,&p,&k);
	scanf("%d",&n1);for(int i=1,x;i<=n1;i++) scanf("%d",&x),isa[x]=1;
	scanf("%d",&n2);for(int i=1,x;i<=n2;i++) scanf("%d",&x),isb[x]=1;
	if(p>=(n+k-1)/k*2){
		int ret=0;
		for(int i=1;i<=n;i++) ret+=isa[i]|isb[i];
		printf("%d\n",ret);return 0;
	}
	int pre=0,cur=1;memset(dp[pre],192,sizeof(dp[pre]));
	dp[pre][0][k][k]=0;
	for(int i=1;i<=n;i++){
		memset(dp[cur],192,sizeof(dp[cur]));
		for(int j=0;j<=p;j++){
			for(int x=1;x<=k;x++) for(int y=1;y<=k;y++){
				chkmax(dp[cur][j][min(x+1,k)][min(y+1,k)],dp[pre][j][x][y]+((isa[i]&&x<k)||(isb[i]&&y<k)));
				if(j<p){
					if(isa[i]) chkmax(dp[cur][j+1][1][min(y+1,k)],dp[pre][j][x][y]+1);
					if(isb[i]) chkmax(dp[cur][j+1][min(x+1,k)][1],dp[pre][j][x][y]+1);
				}
			}
		} pre^=cur^=pre^=cur;
	} int ans=0;
	for(int j=0;j<=p;j++) for(int x=1;x<=k;x++) for(int y=1;y<=k;y++)
		chkmax(ans,dp[pre][j][x][y]);
	printf("%d\n",ans);
	return 0;
}