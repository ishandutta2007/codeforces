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
	template<typename T> void recursive_print(T x){return (!x)?void():(recursive_print(x/10),putc(x%10^48),void());}
	template<typename T> void print(T x){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);}
	template<typename T> void print(T x,char c){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1000;
int n,k,a[MAXN+5][MAXN+5];ll s1[MAXN+5],s2[MAXN+5];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++) for(int j=1;j<=n;j++){
		scanf("%d",&a[i][j]);s1[i]+=a[i][j];
		s2[i]+=1ll*a[i][j]*a[i][j];
	} ll vv=(s1[k]-s1[1])/(k-1);int p=0;
	for(int i=2;i<k;i++) if(s1[i]!=s1[1]+(i-1)*vv) p=i;
	ll need_s=s1[1]+(p-1)*vv;
	ll sum_sqv,need_sqr;
	if(p>3) sum_sqv=s2[p-3]+s2[p-1]-(s2[p-2]<<1);
	else sum_sqv=s2[p+1]+s2[p+3]-(s2[p+2]<<1);
	need_sqr=(s2[p-1]+s2[p+1]-sum_sqv)>>1;
//	printf("%lld %lld\n",need_s,need_sqr);
//	printf("%lld\n",sum_sqv);
	for(int i=1;i<=n;i++){
		ll sqr=s2[p]-1ll*a[p][i]*a[p][i]+
		1ll*(need_s-s1[p]+a[p][i])*(need_s-s1[p]+a[p][i]);
		if(sqr==need_sqr){
			printf("%d %lld\n",p-1,need_s-s1[p]+a[p][i]);
			fflush(stdout);return 0;
		}
	}
	return 0;
}