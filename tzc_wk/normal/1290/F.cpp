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
const int MOD=998244353;
int n,m,x[7],y[7],dp[34][23][23][23][23][2][2];
void add(int &x,int v){((x+=v)>=MOD)&&(x-=MOD);}
int chk(int dm,int dn,int ori){
	if(dm^dn) return (dn<dm)?0:1;
	return ori;
}
int calc(int p,int ps_x,int ps_y,int ng_x,int ng_y,int xm,int ym){
	if(p==30) return (!ps_x&&!ps_y&&!ng_x&&!ng_y&&!xm&&!ym);
	if(~dp[p][ps_x][ps_y][ng_x][ng_y][xm][ym]) return dp[p][ps_x][ps_y][ng_x][ng_y][xm][ym];
	int d=m>>p&1;dp[p][ps_x][ps_y][ng_x][ng_y][xm][ym]=0;
	for(int s=0;s<(1<<n);s++){
		int tps_x=ps_x,tps_y=ps_y,tng_x=ng_x,tng_y=ng_y;
		for(int i=1;i<=n;i++) if(s>>(i-1)&1){
			(x[i]>0)?(tps_x+=x[i]):(tng_x-=x[i]);
			(y[i]>0)?(tps_y+=y[i]):(tng_y-=y[i]);
		} int d_px=tps_x&1,d_py=tps_y&1,d_nx=tng_x&1,d_ny=tng_y&1;
		if(d_px==d_nx&&d_py==d_ny)
			add(dp[p][ps_x][ps_y][ng_x][ng_y][xm][ym],
			calc(p+1,tps_x>>1,tps_y>>1,tng_x>>1,tng_y>>1,chk(d,d_px,xm),chk(d,d_py,ym)));
	} return dp[p][ps_x][ps_y][ng_x][ng_y][xm][ym];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	memset(dp,-1,sizeof(dp));
	printf("%d\n",(calc(0,0,0,0,0,0,0)-1+MOD)%MOD);
	return 0;
}