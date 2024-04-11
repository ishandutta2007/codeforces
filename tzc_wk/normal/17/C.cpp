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
const int MAXN=150;
const int MOD=51123987;
void add(int &x,int v){((x+=v)>=MOD)&&(x-=MOD);}
int n,nxt[MAXN+5][3];char s[MAXN+5];
int dp[MAXN+5][MAXN/3+5][MAXN/3+5][MAXN/3+5],ans=0;
int main(){
	scanf("%d%s",&n,s+1);dp[1][0][0][0]=1;
	nxt[n+1][0]=nxt[n+1][1]=nxt[n+1][2]=n+1;
	for(int i=n;i;i--) for(int j=0;j<3;j++)
		nxt[i][j]=(s[i]-'a'==j)?i:nxt[i+1][j];
	dp[1][0][0][0]=1;int lim=n/3+1;
	for(int i=1;i<=n;i++) for(int x=0;x<=lim;x++)
		for(int y=0;y<=lim;y++) for(int z=0;z<=lim;z++){
			if(!dp[i][x][y][z]) continue;
			if(x+y+z==n) add(ans,(abs(x-y)<=1&&abs(y-z)<=1&&abs(z-x)<=1)*dp[i][x][y][z]);
			else{
				if(nxt[i][0]^(n+1)) add(dp[nxt[i][0]][x+1][y][z],dp[i][x][y][z]);
				if(nxt[i][1]^(n+1)) add(dp[nxt[i][1]][x][y+1][z],dp[i][x][y][z]);
				if(nxt[i][2]^(n+1)) add(dp[nxt[i][2]][x][y][z+1],dp[i][x][y][z]);
			}
		} printf("%d\n",ans);
	return 0;
}