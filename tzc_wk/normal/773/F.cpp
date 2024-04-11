#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
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
template<typename T> void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXP=1<<16;
const int LOG_N=30;
const double Pi=acos(-1);
int n,m,mod;
struct comp{
	double x,y;//(real,imag)
	comp(){x=y=0;}
	comp(double _x,double _y){x=_x;y=_y;}
	comp operator +(const comp &rhs){return comp(x+rhs.x,y+rhs.y);}
	comp operator -(const comp &rhs){return comp(x-rhs.x,y-rhs.y);}
	comp operator *(const comp &rhs){return comp(x*rhs.x-y*rhs.y,x*rhs.y+y*rhs.x);}
} A[MAXP+5],B[MAXP+5],C[MAXP+5],D[MAXP+5];
int LEN=1,LOG=0,rev[MAXP+5];
void FFT(comp *a,int len,int type){
	int lg=log2(len);
	for(int i=0;i<len;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
	for(int i=0;i<len;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(int i=2;i<=len;i<<=1){
		comp W(cos(2*Pi/i),type*sin(2*Pi/i));
		for(int j=0;j<len;j+=i){
			comp w(1,0);
			for(int k=0;k<(i>>1);k++,w=w*W){
				comp X=a[j+k],Y=w*a[(i>>1)+j+k];
				a[j+k]=X+Y;a[(i>>1)+j+k]=X-Y;
			}
		}
	}
	if(type==-1) for(int i=0;i<len;i++) a[i].x=(ll)(a[i].x/len+0.5);
}
void polymul(int *a,int *b,int *c,int len){
	for(int i=0;i<len;i++) A[i]=comp(a[i]>>9,0),B[i]=comp(a[i]&511,0),C[i]=comp(b[i]>>9,0),D[i]=comp(b[i]&511,0);
	FFT(A,len,1);FFT(B,len,1);FFT(C,len,1);FFT(D,len,1);
	for(int i=0;i<len;i++){
		comp t1=A[i]*C[i],t2=B[i]*D[i];
		B[i]=A[i]*D[i]+B[i]*C[i];A[i]=t1;C[i]=t2;
	} FFT(A,len,-1);FFT(B,len,-1);FFT(C,len,-1);
	for(int i=0;i<len;i++) c[i]=(1ll*(ll)(A[i].x)%mod*262144ll%mod+1ll*(ll)(B[i].x)%mod*512%mod+(ll)(C[i].x)%mod)%mod;
}
struct data{int a[2][MAXP+5];data(){memset(a,0,sizeof(a));}};
int tmp[3][MAXP+5];
void merge(data &a,data &b,const int &x){
	for(int i=0;i<LEN;i++) tmp[0][i]=(a.a[0][i]+a.a[1][i])%mod;(tmp[0][0]+=1)%=mod;
	polymul(tmp[0],b.a[0],tmp[1],LEN);polymul(tmp[0],b.a[1],tmp[2],LEN);
	for(int i=0;i<=n;i++){
		if(x&1) a.a[0][i]=(a.a[0][i]+tmp[2][i])%mod,a.a[1][i]=(a.a[1][i]+tmp[1][i])%mod;
		else a.a[0][i]=(a.a[0][i]+tmp[1][i])%mod,a.a[1][i]=(a.a[1][i]+tmp[2][i])%mod;
	}
}
data d;
int main(){
	scanf("%d%d%d",&n,&m,&mod);int ans=0;
	while(LEN<=n+n) LEN<<=1;
	int cur=0;
	for(int i=LOG_N;i;i--){
		merge(d,d,cur);cur<<=1;
		if(m>>i&1){
			for(int j=n;j;j--)
				d.a[1][j]=(d.a[1][j]+d.a[0][j-1]+d.a[1][j-1])%mod;
			(d.a[1][1]+=1)%=mod;cur|=1;
		}
		for(int j=1;j<=n;j+=2) ans=(ans+d.a[1][j])%mod;
	} printf("%d\n",ans);
	return 0;
}