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
const int MAXN=1e6;
int k,f[7],qu;ll dp[MAXN+5];
void add(int w,ll v){for(int i=MAXN;i>=w;i--) chkmax(dp[i],dp[i-w]+v);}
void ins(int w,int v,int c){
//	printf("%d %d %d\n",w,v,c);
	int k=0;c=min(c,MAXN/w);
	while((1<<k+1)-1<=c) add(w*(1<<k),1ll*v*(1<<k)),k++;
	k--;if(c>(1<<k+1)-1) add(w*(c-((1<<k+1)-1)),1ll*v*(c-((1<<k+1)-1)));
}
int main(){
	scanf("%d",&k);for(int i=0;i<6;i++) scanf("%d",&f[i]);
	for(int i=1;i<MAXN;i++){
		int tmp=i;
		for(int j=0;j<6;j++){
			int rem=tmp%10;tmp/=10;
			if(rem%3==0) dp[i]+=1ll*(rem/3)*f[j];
		}
	}
	for(int i=0,pw=1;i<=5;i++,pw*=10) ins(3*pw,f[i],3*(k-1));
	int qu;scanf("%d",&qu);
	while(qu--){int k;scanf("%d",&k);printf("%lld\n",dp[k]);}
	return 0;
}