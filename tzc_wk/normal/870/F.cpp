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
const int MAXN=1e7;
int n,pr[MAXN/10+5],prcnt=0,mnp[MAXN+5],phi[MAXN+5],cnt[MAXN+5];
bitset<MAXN+5> vis;
void sieve(){
	phi[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis.test(i)){pr[++prcnt]=i;phi[i]=i-1;mnp[i]=i;}
		for(int j=1;pr[j]*i<=n&&j<=prcnt;j++){
			vis[pr[j]*i]=1;mnp[pr[j]*i]=pr[j];
			if(i%pr[j]==0){phi[pr[j]*i]=phi[i]*pr[j];break;}
			else phi[pr[j]*i]=phi[i]*phi[pr[j]];
		}
	}
}
int calc(int l,int r){return (l>r)?0:(cnt[r]-cnt[l]);}
int main(){
	scanf("%d",&n);sieve();ll sum=0,ans0=0,ans1=0,ans2=0,ans3=0;
	for(int i=2;i<=n;i++) cnt[mnp[i]]++;
	for(int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
	for(int i=1;i<=n;i++) sum+=phi[i]-1;
	ans1=1ll*(n-1)*(n-2)/2-sum;
	for(int i=1;i<=n;i++){
		int num=cnt[i]-cnt[i-1];
		if(i<=n/2) ans3+=1ll*num*calc(max(i,n/i),n/2);
		ans0+=1ll*num*calc(max(n/2,i),n);
	} ans2=sum-ans0-ans3;
	printf("%lld\n",ans1+(ans2<<1)+(ans3<<1)+ans3);
	return 0;
}