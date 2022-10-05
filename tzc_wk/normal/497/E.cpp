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
const int LOG=60;
const int MAXM=30;
const int MOD=1e9+7;
ll n;int m,d[LOG+2],dc=-1;
struct mat{
	int a[MAXM+2][MAXM+2];
	mat(){memset(a,0,sizeof(a));}
	mat operator *(const mat &rhs){
		mat ret;
		for(int i=0;i<=m;i++) for(int j=0;j<=m;j++) for(int k=0;k<=m;k++)
			ret.a[i][j]=(ret.a[i][j]+1ll*a[i][k]*rhs.a[k][j])%MOD;
		return ret;
	}
} ans,mul,a[LOG+2][MAXM+2],suf[LOG+2][MAXM+2],pre[LOG+2][MAXM+2];
int main(){
	scanf("%lld%d",&n,&m);
	while(n){d[++dc]=n%m;n/=m;}
	for(int i=0;i<=dc;i++){
		if(!i){
			for(int j=0;j<m;j++){
				a[i][j].a[m][m]=1;
				for(int k=0;k<m;k++) if(k^j) a[i][j].a[k][k]=1;
				for(int k=0;k<=m;k++) a[i][j].a[j][k]=1;
//				printf("A %d %d:\n",i,j);
//				for(int k=0;k<=m;k++) for(int l=0;l<=m;l++)
//					printf("%d%c",a[i][j].a[k][l],(l==m)?'\n':' ');
			}
		} else {
			for(int j=0;j<m;j++){
				if(!j) a[i][j]=suf[i-1][0];
				else a[i][j]=suf[i-1][j]*pre[i-1][j-1];
//				printf("A %d %d:\n",i,j);
//				for(int k=0;k<=m;k++) for(int l=0;l<=m;l++)
//					printf("%d%c",a[i][j].a[k][l],(l==m)?'\n':' ');
			}
		}
		pre[i][0]=a[i][0];
		for(int j=1;j<m;j++) pre[i][j]=pre[i][j-1]*a[i][j];
		suf[i][m-1]=a[i][m-1];
		for(int j=m-2;~j;j--) suf[i][j]=a[i][j]*suf[i][j+1];
	} int sum=0;ans.a[m][0]=1;
	for(int i=0;i<=m;i++) mul.a[i][i]=1;
	for(int i=dc;~i;i--){
		while(d[i]){
			d[i]--;mul=mul*a[i][sum];
			sum++;if(sum==m) sum=0;
		}
	} ans=mul*ans;int ret=0;
	for(int i=0;i<=m;i++) ret=(ret+ans.a[i][0])%MOD;
	printf("%d\n",ret%MOD);
	return 0;
}