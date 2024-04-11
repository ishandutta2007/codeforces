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
int n,m,a[MAXN+5],b[MAXN+5],dp[MAXN+5],mn[MAXN+5],pre[MAXN+5],ps[MAXN+5];
//dp[i]: LIS ended on the i-th element
//mn[i]: the minimum number of the last element of increasing sequence of length i
//pre[i]: the previous element of the LIS ended on the i-th element
//ps[i]: the position of the minimum number of the last element of increasing sequence of length i
int main(){
	scanf("%d",&n);for(int i=1;i<=n+1;i++) mn[i]=INF+1;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);a[++n]=INF;
	scanf("%d",&m);for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	sort(b+1,b+m+1);
	for(int i=1;i<=n;i++){
		if(~a[i]){
			int t=lower_bound(mn+1,mn+n+1,a[i])-mn;
			dp[i]=t;pre[i]=ps[t-1];mn[t]=a[i];ps[t]=i;
		} else {
			for(int j=m,k=n;j;j--){
				while(mn[k]>=b[j]) k--;
				mn[k+1]=b[j];ps[k+1]=i;
			}
		}
	}
//	printf("dp: ");for(int i=1;i<=n;i++) printf("%d ",dp[i]);printf("\n");
//	printf("pre: ");for(int i=1;i<=n;i++) printf("%d ",pre[i]);printf("\n");
	int x=n,val=a[n],is=0,clen=dp[n]+1;
	while(clen--){
//		printf("%d %d\n",x,clen);
		if(!is){
			if(!~a[pre[x]]){
				is=1;
				for(int j=m;j;j--) if(~b[j]&&b[j]<a[x]){
					a[pre[x]]=b[j];b[j]=-1;break;
				}
			} x=pre[x];
		} else {
			bool flg=0;
			for(int j=x-1;~j;j--) if(~a[j]&&a[j]<a[x]&&dp[j]+1==clen){
				x=j;is=0;flg=1;break;
			}
			if(!flg){
				int val=0,pos=0;
				for(int j=1;j<=m;j++) if(~b[j]&&b[j]<a[x]) val=b[j],pos=j;
				b[pos]=-1;is=1;//printf("%d\n",val);
				for(int j=x-1;j;j--) if(!~a[j]){a[j]=val;x=j;break;}
			}
		}
	}
	for(int i=1;i<=n;i++) if(!~a[i]){
		for(int j=1;j<=m;j++) if(~b[j]){a[i]=b[j],b[j]=-1;break;}
	}
	for(int i=1;i<n;i++) printf("%d ",a[i]);
	return 0;
}