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
const int MAXN=1e5;
const double INF=1e9;
const double EPS=1e-4;
int n,d,a[MAXN+5];
double dp[MAXN+5][11];
vector<int> ans;
void dump(int x,int y){
	if(x==0) return;
	if(dp[x-1][y]==dp[x][y]) return dump(x-1,y),void();
	else{
		for(int i=0;i<10;i++)
			if(i*a[x]%10==y&&fabs(dp[x-1][i]+log(a[x])-dp[x][y])<EPS)
				return ans.pb(x),dump(x-1,i),void();
	}
}
int main(){
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=0;i<=n;i++) for(int j=0;j<10;j++) dp[i][j]=-INF;
	dp[0][1]=0;
	for(int i=0;i<n;i++) for(int j=0;j<10;j++){
		chkmax(dp[i+1][j],dp[i][j]);
		chkmax(dp[i+1][j*a[i+1]%10],dp[i][j]+log(a[i+1]));
	}
	if(dp[n][d]<=0) puts("-1");
	else{
		dump(n,d);printf("%d\n",ans.size());
		for(int id:ans) printf("%d ",a[id]);
	}
	return 0;
}