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
const int MOD=1e9+7;
const int M=1<<15;
const int MAGIC=73741817;
const int MAXK=3e4;
const int MAXP=1<<17;
const int MAX_PATH=30;
const long double Pi=acos(-1);
int qpow(int x,ll e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
struct comp{
	long double x,y;
	comp(){x=y=0;}
	comp(long double _x,long double _y){x=_x;y=_y;}
	comp operator +(const comp &rhs){return comp(x+rhs.x,y+rhs.y);}
	comp operator -(const comp &rhs){return comp(x-rhs.x,y-rhs.y);}
	comp operator *(const comp &rhs){return comp(x*rhs.x-y*rhs.y,x*rhs.y+y*rhs.x);}
} A[MAXP+5],B[MAXP+5],C[MAXP+5],D[MAXP+5];
int E[MAXP+5],F[MAXP+5];
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
//	printf("a: ");for(int i=0;i<len;i++) printf("%d%c",a[i],(i==len-1)?'\n':' ');
//	printf("b: ");for(int i=0;i<len;i++) printf("%d%c",b[i],(i==len-1)?'\n':' ');
	for(int i=0;i<len;i++) A[i].x=a[i]/M,B[i].x=a[i]%M,C[i].x=b[i]/M,D[i].x=b[i]%M;
	FFT(A,len,1);FFT(B,len,1);FFT(C,len,1);FFT(D,len,1);
	for(int i=0;i<len;i++){
		comp t1=A[i]*C[i],t2=B[i]*D[i];
		B[i]=A[i]*D[i]+B[i]*C[i];A[i]=t1;C[i]=t2;
	} FFT(A,len,-1);FFT(B,len,-1);FFT(C,len,-1);
	for(int i=0;i<len;i++) c[i]=((1ll*(ll)(A[i].x)%MOD*MAGIC%MOD+1ll*(ll)(B[i].x)%MOD*M%MOD)%MOD+(ll)(C[i].x))%MOD;
	for(int i=0;i<len;i++) A[i]=B[i]=C[i]=D[i]=comp(0,0);
//	printf("c: ");for(int i=0;i<len;i++) printf("%d%c",c[i],(i==len-1)?'\n':' ');
}
ll n;int k;
void merge(int *a,int *b,const int &x){
	static int tmp[MAXP+5];memset(tmp,0,sizeof(tmp));int tmp0=qpow(2,x),tmp1=1;
	for(int i=0;i<=k;i++) tmp[i]=1ll*a[i]*tmp1%MOD,tmp1=1ll*tmp1*tmp0%MOD;
	polymul(b,tmp,tmp,LEN<<1);
	for(int i=0;i<=k;i++) a[i]=tmp[i];
}
int fac[MAXK+5],ifac[MAXK+5];
vector<int> path[MAXK+5];
int tmp[MAX_PATH+2][MAXP+5];
int main(){
	scanf("%lld%d",&n,&k);if(n>k) return puts("0"),0;
	fac[0]=1;
	for(int i=1;i<=k;i++) fac[i]=1ll*fac[i-1]*i%MOD;
	ifac[k]=qpow(fac[k],MOD-2);
	for(int i=k-1;~i;i--) ifac[i]=1ll*ifac[i+1]*(i+1)%MOD;
	while(LEN<=k) LEN<<=1;
	static int q[MAXK+5];int head=1,rear=0;
	q[++rear]=1;path[1].pb(1);
	while(head<=rear){
		int x=q[head++];
		for(int y:path[x]){
			int u=x+y;
			if(u<=n&&!path[u].size()){
				path[u]=path[x];path[u].pb(u);q[++rear]=u;
			}
		}
	}
	for(int i=1;i<=k;i++) tmp[0][i]=ifac[i];
	for(int i=1;i<path[n].size();i++){
		for(int j=0;j<=k;j++) tmp[i][j]=tmp[i-1][j];
		for(int j=0;j<i;j++) if(path[n][j]+path[n][i-1]==path[n][i])
			merge(tmp[i],tmp[j],path[n][j]);
	}
	int ans=0;
//	for(int i=0;i<path[n].size();i++) printf("%d\n",path[n][i]);
//	for(int i=0;i<path[n].size();i++) for(int j=0;j<=k;j++)
//		printf("%d%c",tmp[i][j],(j==k)?'\n':' ');
	for(int i=1;i<=k;i++) (ans+=1ll*tmp[path[n].size()-1][i]*ifac[k-i]%MOD*fac[k]%MOD)%=MOD;
	printf("%d\n",ans);
	return 0;
}