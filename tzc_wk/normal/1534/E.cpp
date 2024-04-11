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
const int MAXN=500;
int n,k;
int main(){
	scanf("%d%d",&n,&k);if((n&1)&&(~k&1)) return puts("-1"),0;
	if((n%k)%2==0){
		int lft=n/k*k-k,tt=n-lft;
		if(n%k==0){
			int res=0;
			for(int i=1;i<=n/k;i++){
				printf("?");
				for(int j=1;j<=k;j++) printf(" %d",(i-1)*k+j);
				printf("\n");fflush(stdout);
				int x;scanf("%d",&x);res^=x;
			} printf("! %d\n",res);fflush(stdout);
		} else if(tt%2==0&&tt/2+lft>=k){
			int res=0;
			for(int i=1;i<=lft/k;i++){
				printf("?");
				for(int j=1;j<=k;j++) printf(" %d",(i-1)*k+j);
				printf("\n");fflush(stdout);
				int x;scanf("%d",&x);res^=x;
			} printf("?");
			for(int i=1;i<=k-(tt/2);i++) printf(" %d",i);
			for(int i=1;i<=tt/2;i++) printf(" %d",lft+i);
			printf("\n");fflush(stdout);
			int x;scanf("%d",&x);res^=x;
			printf("?");
			for(int i=1;i<=k-(tt/2);i++) printf(" %d",i);
			for(int i=1;i<=tt/2;i++) printf(" %d",lft+(tt/2)+i);
			printf("\n");fflush(stdout);
			scanf("%d",&x);res^=x;
			printf("! %d\n",res),fflush(stdout);
		} else {
			int res=0;
			for(int i=1;i<=n/k;i++){
				printf("?");
				for(int j=1;j<=k;j++) printf(" %d",(i-1)*k+j);
				printf("\n");fflush(stdout);
				int x;scanf("%d",&x);res^=x;
			} printf("?");
			for(int i=1;i<=k-(n%k)/2;i++) printf(" %d",i);
			for(int i=1;i<=(n%k)/2;i++) printf(" %d",n/k*k+i);
			printf("\n");fflush(stdout);
			int x;scanf("%d",&x);res^=x;
			printf("?");
			for(int i=1;i<=k-(n%k)/2;i++) printf(" %d",i);
			for(int i=1;i<=(n%k)/2;i++) printf(" %d",n-i+1);
			printf("\n");fflush(stdout);
			scanf("%d",&x);res^=x;
			printf("! %d\n",res),fflush(stdout);
		}
	} else {
		int rst=n/k*k-k,tt=n-rst,res=0;
		for(int i=1;i<=rst;i+=k){
			printf("?");
			for(int j=i;j<i+k;j++) printf(" %d",j);
			printf("\n");fflush(stdout);
			int x;scanf("%d",&x);res^=x;
		} if(tt/2+rst>=k){
			printf("?");
			for(int i=1;i<=k-tt/2;i++) printf(" %d",i);
			for(int i=1;i<=tt/2;i++) printf(" %d",rst+i);
			printf("\n");fflush(stdout);
			int x;scanf("%d",&x);res^=x;
			printf("?");
			for(int i=1;i<=k-tt/2;i++) printf(" %d",i);
			for(int i=1;i<=tt/2;i++) printf(" %d",n-i+1);
			printf("\n");fflush(stdout);
			scanf("%d",&x);res^=x;
			printf("! %d\n",res),fflush(stdout);
		} else {
			static bool vis[MAXN+5]={0};
			int could=(n-k)<<1;
			int need=(tt+could-1)/could;
			for(int i=1;i<=need;i++){
				int ql=rst+(i-1)*could+1;
				int qr=rst+i*could;chkmin(qr,n);
				int len=min(could,qr-ql+1);
				printf("?");memset(vis,0,sizeof(vis));
				for(int j=ql;j<=qr;j++) vis[j]=1;int nd=k-(len/2);
				vector<int> v;
				for(int j=1;j<=n;j++) if(!vis[j]&&nd) --nd,v.pb(j);
				for(int x:v) printf(" %d",x);
				for(int j=ql;j<ql+(len>>1);j++) printf(" %d",j);
				printf("\n");fflush(stdout);
				int x;scanf("%d",&x);res^=x;
				printf("?");for(int x:v) printf(" %d",x);
				for(int j=ql+(len>>1);j<=qr;j++) printf(" %d",j);
				printf("\n");fflush(stdout);
				scanf("%d",&x);res^=x;
			} printf("! %d\n",res),fflush(stdout);
		}
	}
	return 0;
}