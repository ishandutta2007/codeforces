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
const int MAXN=1e5;
const int MAXP=1<<18;
const double Pi=acos(-1);
int n,m,qu,a[MAXN+5],b[MAXN+5];
struct comp{
	double x,y;
	comp(double _x=0,double _y=0):x(_x),y(_y){}
	comp operator +(const comp &rhs){return comp(x+rhs.x,y+rhs.y);}
	comp operator -(const comp &rhs){return comp(x-rhs.x,y-rhs.y);}
	comp operator *(const comp &rhs){return comp(x*rhs.x-y*rhs.y,x*rhs.y+y*rhs.x);}
} A[MAXP+5],mA[MAXP+5],MA[MAXP+5],B[MAXP+5],mB[MAXP+5],MB[MAXP+5];
comp V[MAXP+5],lV[MAXP+5],lH[MAXP+5],rV[MAXP+5],rH[MAXP+5],l4[MAXP+5],r4[MAXP+5];
//l for <=, r for >=, V for vertical, H for horizontal, 4 for 4-connected area
int rev[MAXP+5];
void FFT(comp *a,int len,int type){
	int lg=31-__builtin_clz(len);
	for(int i=0;i<len;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
	for(int i=0;i<len;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(int i=2;i<=len;i<<=1){
		comp W=comp(cos(2*Pi/i),type*sin(2*Pi/i));
		for(int j=0;j<len;j+=i){
			comp w=comp(1,0);
			for(int k=0;k<(i>>1);k++,w=w*W){
				comp X=a[j+k],Y=w*a[(i>>1)+j+k];
				a[j+k]=X+Y;a[(i>>1)+j+k]=X-Y;
			}
		}
	} if(type==-1){
		for(int i=0;i<len;i++) a[i].x=(ll)(a[i].x/len+0.5);
	}
}
ll Ver_l[MAXP+5],Edg_l[MAXP+5],Fac_l[MAXP+5];
ll Ver_r[MAXP+5],Edg_r[MAXP+5],Fac_r[MAXP+5];
int main(){
	scanf("%d%d%d",&n,&m,&qu);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	for(int i=1;i<=n;i++) A[a[i]].x+=1;
	for(int i=1;i<=m;i++) B[b[i]].x+=1;
	for(int i=1;i<n;i++){
		mA[min(a[i],a[i+1])].x+=1;
		MA[max(a[i],a[i+1])].x+=1;
	}
	for(int i=1;i<m;i++){
		mB[min(b[i],b[i+1])].x+=1;
		MB[max(b[i],b[i+1])].x+=1;
	}
	FFT(A,MAXP,1);FFT(B,MAXP,1);FFT(mA,MAXP,1);FFT(mB,MAXP,1);
	FFT(MA,MAXP,1);FFT(MB,MAXP,1);
	for(int i=0;i<MAXP;i++){
		V[i]=A[i]*B[i];
		lV[i]=MA[i]*B[i];rV[i]=mA[i]*B[i];
		lH[i]=A[i]*MB[i];rH[i]=A[i]*mB[i];
		l4[i]=MA[i]*MB[i];r4[i]=mA[i]*mB[i];
	} FFT(V,MAXP,-1);FFT(lV,MAXP,-1);FFT(rV,MAXP,-1);
	FFT(lH,MAXP,-1);FFT(rH,MAXP,-1);FFT(l4,MAXP,-1);FFT(r4,MAXP,-1);
	for(int i=1;i<=MAXP;i++){
		Ver_l[i]+=(ll)V[i].x;Ver_r[i]+=(ll)V[i].x;
		Edg_l[i]+=(ll)lV[i].x;Edg_r[i]+=(ll)rV[i].x;
		Edg_l[i]+=(ll)lH[i].x;Edg_r[i]+=(ll)rH[i].x;
		Fac_l[i]+=(ll)l4[i].x;Fac_r[i]+=(ll)r4[i].x;
	}
	for(int i=1;i<=MAXP;i++) Ver_l[i]+=Ver_l[i-1],Edg_l[i]+=Edg_l[i-1],Fac_l[i]+=Fac_l[i-1];
	for(int i=MAXP;i;i--) Ver_r[i]+=Ver_r[i+1],Edg_r[i]+=Edg_r[i+1],Fac_r[i]+=Fac_r[i+1];
	while(qu--){
		int x;scanf("%d",&x);
		printf("%lld\n",(Ver_r[x]-Ver_l[x-1])-(Edg_r[x]-Edg_l[x-1])+(Fac_r[x]-Fac_l[x-1]));
	}
	return 0;
}