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
const int MAXN=1000;
int n,vis[MAXN+5];
double p[MAXN+5][MAXN+5],dp[MAXN+5],prd[MAXN+5];
double calc(int x){return 1.0*(dp[x]+prd[x])/(1-prd[x]);}
void work(int x){
	vis[x]=1;
	for(int i=1;i<=n;i++) if(!vis[i])
		dp[i]+=1.0*(1+calc(x))*prd[i]*p[i][x],prd[i]*=(1-p[i][x]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
		int x;scanf("%d",&x);p[i][j]=x/100.0;
	} dp[n]=0;for(int i=1;i<n;i++) prd[i]=1;work(n);
	for(int i=1;i<n;i++){
		double mn=1e9;int ps=0;
		for(int j=1;j<=n;j++) if(!vis[j]&&calc(j)<mn) mn=calc(j),ps=j;
		work(ps);
	} printf("%.12lf\n",calc(1));
	return 0;
}