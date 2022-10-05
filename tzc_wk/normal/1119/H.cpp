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
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1<<17;
const int MOD=998244353;
const int INV2=499122177;
int n,k,x,y,z,ans[MAXN+5],c1[MAXN+5],c2[MAXN+5],c3[MAXN+5];
int qpow(int x,int e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
void FWTxor(int *a,int len,int type){
	for(int i=2;i<=len;i<<=1)
		for(int j=0;j<len;j+=i)
			for(int k=0;k<(i>>1);k++){
				int X=a[j+k],Y=a[(i>>1)+j+k];
				if(type==1) a[j+k]=X+Y,a[(i>>1)+j+k]=X-Y;
				else a[j+k]=1ll*(X+Y)*INV2%MOD,a[(i>>1)+j+k]=1ll*(X-Y+MOD)*INV2%MOD;
			}
}
int main(){
	scanf("%d%d",&n,&k);int xsum=0;
	scanf("%d%d%d",&x,&y,&z);
	for(int i=1,a,b,c;i<=n;i++){
		scanf("%d%d%d",&a,&b,&c);b^=a;c^=a;xsum^=a;
		c1[b]++;c2[c]++;c3[b^c]++;
	}
	FWTxor(c1,1<<k,1);FWTxor(c2,1<<k,1);FWTxor(c3,1<<k,1);
	for(int i=0;i<(1<<k);i++){
		int w1=(n+c1[i]+c2[i]+c3[i])/4;
		int w2=(n+c1[i]-c2[i]-c3[i])/4;
		int w3=(n-c1[i]+c2[i]-c3[i])/4;
		int w4=(n-c1[i]-c2[i]+c3[i])/4;
//		printf("%d %d %d\n",c1[i],c2[i],c3[i]);
//		printf("%d %d %d %d\n",w1,w2,w3,w4);
		ans[i]=1ll*qpow((x+y)%MOD+z,w1)*qpow(x+y-z,w2)%MOD*
		qpow(x-y+z,w3)%MOD*qpow(x-y-z,w4)%MOD;
		if(ans[i]<0) ans[i]+=MOD;
	} FWTxor(ans,1<<k,-1);
	for(int i=0;i<(1<<k);i++) printf("%d ",ans[i^xsum]);
	return 0;
}