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
const double INF=1e9;
const double Pi=acos(-1);
const int MAXN=50;
const int MAXM=100;
const int MAXT=2e4;
const int MAXP=1<<17;
int n,m,t,x,a[MAXM+5],b[MAXM+5],c[MAXM+5];
double p[MAXM+5][MAXT*2+5],dp[MAXN+5][MAXT*2+5],f[MAXM+5][MAXT*2+5];
int dis[MAXN+5][MAXN+5];
struct comp{
	double x,y;//(real,imag)
	comp(){x=y=0;}
	comp(double _x,double _y):x(_x),y(_y){}
	comp operator +(const comp &rhs){return comp(x+rhs.x,y+rhs.y);}
	comp operator -(const comp &rhs){return comp(x-rhs.x,y-rhs.y);}
	comp operator *(const comp &rhs){return comp(x*rhs.x-y*rhs.y,x*rhs.y+y*rhs.x);}
} A[MAXP+5],B[MAXP+5],C[MAXP+5];
int rev[MAXP+5];
void FFT(comp *a,int len,int type){
	int lg=31-__builtin_clz(len);
	for(int i=0;i<len;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
	for(int i=0;i<len;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(int i=2;i<=len;i<<=1){
		comp W(cos(2*Pi/i),type*sin(2*Pi/i));
		for(int j=0;j<len;j+=i){
			comp w(1,0);
			for(int k=0;k<(i>>1);k++,w=w*W){
				comp X=a[j+k],Y=a[(i>>1)+j+k]*w;
				a[j+k]=X+Y;a[(i>>1)+j+k]=X-Y;
			}
		}
	}
	if(type==-1) for(int i=0;i<len;i++) a[i].x/=len;
}
void cdq_FFT(int l,int r){
	if(l==t) return;
	if(l==r){
		for(int i=1;i<=m;i++) if(a[i]!=n)
			chkmin(dp[a[i]][l],f[i][l]+c[i]);
		return;
	} int mid=l+r>>1;cdq_FFT(mid+1,r);
	int la=r-l+1,lb=r-mid,LEN=1;
	while(LEN<=la+lb) LEN<<=1;
	for(int i=1;i<=m;i++){
		if(a[i]==n) continue;
//		for(int j=l;j<=mid;j++) for(int k=mid+1;k<=r;k++)
//			f[i][j]+=dp[b[i]][k]*p[i][k-j];
		for(int j=0;j<LEN;j++) A[j]=B[j]=C[j]=comp(0,0);
		for(int j=1;j<=r-l+1;j++) B[j].x=p[i][la-j+1];
		for(int j=mid+1;j<=r;j++) A[j-mid].x=dp[b[i]][j];
		FFT(A,LEN,1);FFT(B,LEN,1);
		for(int j=0;j<LEN;j++) C[j]=A[j]*B[j];
		FFT(C,LEN,-1);
		for(int j=l;j<=mid;j++) f[i][j]+=C[j-mid+la+1].x;
	} cdq_FFT(l,mid);
}
int main(){
//	for(int i=0;i<3;i++) A[i].x=i;
//	B[0].x=B[1].x=1;FFT(A,8,1);FFT(B,8,1);
//	for(int i=0;i<8;i++) A[i]=A[i]*B[i];FFT(A,8,-1);
//	for(int i=0;i<8;i++) printf("%.10lf\n",A[i].x);
	scanf("%d%d%d%d",&n,&m,&t,&x);
	memset(dis,63,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		chkmin(dis[a[i]][b[i]],c[i]);
		for(int j=1,x;j<=t;j++){
			scanf("%d",&x);p[i][j]=x/100000.0;
		}
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		chkmin(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=0;i<=t;i++) dp[n][i]=0;
	for(int i=t+1;i<=t*2;i++) dp[n][i]=x;
	for(int i=1;i<n;i++) for(int j=t;j<=t*2;j++) dp[i][j]=dis[i][n]+x;
	for(int i=1;i<n;i++) for(int j=0;j<t;j++) dp[i][j]=INF;
	cdq_FFT(0,2*t-1);printf("%.10lf\n",dp[1][0]);
//	for(int i=1;i<=n;i++) for(int j=0;j<=t;j++) printf("%d %d %.10lf\n",i,j,dp[i][j]);
//	for(int i=1;i<=m;i++) for(int j=0;j<=t;j++) printf("%d %d %.10lf %.10lf\n",i,j,f[i][j],p[i][j]);
	return 0;
}