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
const int MAXN=2e5;
int n,a[MAXN+5];ll s[MAXN+5],ss[MAXN+5],ans=0;
double getx(int x){return x;}
double gety(int x){return 1ll*x*s[x]-ss[x];}
double slope(int j,int k){return 1.0*(gety(j)-gety(k))/(getx(j)-getx(k));}
int stk[MAXN+5],tp=0;
int main(){
	scanf("%d",&n);for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i],ss[i]=ss[i-1]+1ll*i*a[i];
	for(int i=1;i<=n;i++){
		while(tp>=2&&slope(stk[tp],stk[tp-1])<slope(i-1,stk[tp])) --tp;
		stk[++tp]=i-1;int l=1,r=tp-1,p=tp;
		while(l<=r){
			int mid=l+r>>1;
			if(slope(stk[mid],stk[mid+1])>s[i]) l=mid+1;
			else p=mid,r=mid-1;
		} //printf("%d %d\n",i,stk[p]);
		chkmax(ans,ss[i]-1ll*stk[p]*s[i]+1ll*stk[p]*s[stk[p]]-ss[stk[p]]);
	} printf("%lld\n",ans);
	return 0;
}