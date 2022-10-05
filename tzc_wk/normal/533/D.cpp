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
const int MAXN=1e5;
const int INF=0x3f3f3f3f;
int n,a[MAXN+5],b[MAXN+5],l[MAXN+5],r[MAXN+5];
int stk[MAXN+5],tp;
int main(){
	scanf("%d",&n);
	for(int i=0;i<=n+1;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	b[0]=b[n+1]=r[0]=l[n+1]=INF;stk[tp=1]=0;
	for(int i=1;i<=n+1;i++){
		while(tp&&a[stk[tp]]+r[stk[tp]]<a[i]) --tp;
		r[i]=(b[i]<<1)-(a[i]-a[stk[tp]]);
		if(r[i]>0){
			while(tp&&a[stk[tp]]+r[stk[tp]]<=a[i]+r[i]) --tp;
			stk[++tp]=i;
		}
	} stk[tp=1]=n+1;
	for(int i=n;~i;i--){
		while(tp&&a[stk[tp]]-l[stk[tp]]>a[i]) --tp;
		l[i]=(b[i]<<1)-(a[stk[tp]]-a[i]);
		if(l[i]>0){
			while(tp&&a[stk[tp]]-l[stk[tp]]>=a[i]-l[i]) --tp;
			stk[++tp]=i;
		}
	} stk[tp=1]=0;int ans=INF;
	for(int i=1;i<=n;i++) if(0ll+l[i]+r[i]>=(b[i]<<1))
		return puts("0")&0;
	for(int i=1;i<=n+1;i++){
		if(l[i]>0){
			int L=1,R=tp,p=-1;
			while(L<=R){
				int mid=L+R>>1;
				if(a[stk[mid]]+r[stk[mid]]<a[i]-l[i]) R=mid-1;
				else p=mid,L=mid+1;
			} chkmin(ans,a[i]-a[stk[p]]);
		} if(r[i]>0){
			while(tp&&a[stk[tp]]+r[stk[tp]]<=a[i]+r[i]) --tp;
			stk[++tp]=i;
		}
	} printf("%d.%d\n",ans>>1,5*(ans&1));
	return 0;
}