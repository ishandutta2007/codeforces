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
const int MAXN=2e5;
bitset<MAXN+5> vis[105],trs,is;
int pr[MAXN/6+5],prcnt=0;
void sieve(int n){
	for(int i=2;i<=n;i++){
		if(!is[i]) pr[++prcnt]=i,trs.set(i);
		for(int j=1;j<=prcnt&&pr[j]*i<=n;j++){
			is[pr[j]*i]=1;
			if(i%pr[j]==0) break;
		}
	}
	for(int j=1;j<=prcnt;j++)
		for(int k=1;k<=prcnt&&pr[j]*pr[k]<=n;k++)
			trs.set(pr[j]*pr[k]);
}
int sg[MAXN+5];
void getsg(int n){
	for(int i=0;i<=n;i++){
		while(vis[sg[i]][i]) sg[i]++;
		vis[sg[i]]|=(trs<<i);
	}
}
int main(){
	sieve(MAXN);int n,f,sum=0;scanf("%d%d",&n,&f);trs.reset(f);getsg(MAXN);
	for(int i=1,x,y,z;i<=n;i++) scanf("%d%d%d",&x,&y,&z),sum^=sg[y-x-1],sum^=sg[z-y-1];
	if(!sum) puts("Bob\nAlice");
	else puts("Alice\nBob");
	return 0;
}