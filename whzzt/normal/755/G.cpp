#include<bits/stdc++.h>

#define mms(a,n) memset(a,0,sizeof((a)[0])*(n))
#define mmp(a,b,n) memcpy(a,b,sizeof((b)[0])*(n))
#define lowbit(x) ((x)&-(x))
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define lowbit(x) ((x)&-(x))
#define fo(i,l,r) for(register int i=l,_lim_=r;i<=_lim_;i++)
#define fd(i,r,l) for(register int i=r;_lim_=l;i>=_lim_;i--)

using namespace std;
typedef long long ll;
typedef pair<ll,int> pi;

namespace io{
	const int L=(1<<19)+1;
	char ibuf[L],*iS,*iT,obuf[L],*oS=obuf,*oT=obuf+L-1,c,st[55];int f,tp;
	inline char gc(){
		if(iS==iT){
			iT=(iS=ibuf)+fread(ibuf,1,L,stdin);
			return iS==iT?EOF:*iS++;
		}
		return*iS++;
	}
	inline void flush(){fwrite(obuf,1,oS-obuf,stdout);oS=obuf;}
	inline void putc(char x){*oS++=x;if(oS==oT)flush();}
	template<class I>
	inline void gi(I&x){
		for(f=1,c=gc();c<'0'||c>'9';c=gc())if(c=='-')f=-1;
		for(x=0;c<='9'&&c>='0';c=gc())x=x*10+(c&15);x*=f;
	}
	template<class I>
	inline void print(I x){
		if(!x)putc('0');if(x<0)putc('-'),x=-x;
		while(x)st[++tp]=x%10+'0',x/=10;
		while(tp)putc(st[tp--]);
	}
	inline void gs(char*s,int&l){
		for(c=gc();c!='_'&&(c<'a'||c>'z');c=gc());
		for(l=0;c=='_'||c<='z'&&c>='a';c=gc())s[l++]=c;
	}
	inline void give(){putc('n');putc('o');putc('n');putc('e');}
};
using io::putc;
using io::gi;
using io::gs;
using io::print;

const int N=1050005,P=998244353,G=23,g=3;
inline int fpow(int a,int t){
	static int r;
	for(r=1;t;t>>=1,a=(ll)a*a%P)if(t&1)r=(ll)r*a%P;
	return r;
}

int *_ww[G],*_iww[G],inv[N];
inline int nxp(int n){int l=1;while(l<=n)l<<=1;return l;}
void predo(int n){
	static int poc[N<<2],*iter=poc;
	for(int l=2,i=1;l<=n;l<<=1,i++){
		_ww[i]=iter;for(int j=*iter=1,k=l>>1,w=fpow(g,(P-1)/l);j<k;j++)iter[j]=(ll)iter[j-1]*w%P;iter+=l>>1;
		_iww[i]=iter;for(int j=*iter=1,k=l>>1,w=fpow(g,(P-1)/l*(l-1));j<k;j++)iter[j]=(ll)iter[j-1]*w%P;iter+=l>>1;
	}
	inv[1]=1;for(int i=2;i<=n;i++)inv[i]=P-(ll)(P/i)*inv[P%i]%P;
}
void fft(int a[],int n,int dft){
	int i,j,k,l,u,v,t,*_w;
	for(i=1,j=n>>1;i<n-1;i++){
		if(i<j)swap(a[i],a[j]);
		for(k=n>>1;(j^=k)<k;k>>=1);
	}
	for(l=2,t=1;l<=n;l<<=1,t++){
		if(dft==1)_w=_ww[t];else _w=_iww[t];
		for(i=l>>1,j=0;j<n;j+=l)for(k=0;k<i;k++)u=a[j+k],v=(ll)a[j+k+i]*_w[k]%P,a[j+k]=(u+v)%P,a[j+k+i]=(u-v+P)%P;
	}
	if(dft==-1)for(i=0;i<n;i++)a[i]=(ll)a[i]*inv[n]%P;
}
void convol(int a[],int na,int b[],int nb,int c[],int n){
	static int a0[N],b0[N],c0[N];
	assert(na>=0);assert(nb>=0);assert(n>=0);
	int m=nxp(na+nb-2);
	mms(a0,m);mms(b0,m);mmp(a0,a,na);mmp(b0,b,nb);
	fft(a0,m,1);fft(b0,m,1);
	for(int i=0;i<m;i++)c0[i]=(ll)a0[i]*b0[i]%P;
	fft(c0,m,-1);mmp(c,c0,n);
}
void Inv(int a[],int b[],int n){
	if(n==1)return (void)(*b=fpow(*a,P-2));
	static int w[N];
	int D=(n+1)>>1,m=nxp(n+D*2-3);
	Inv(a,w,D);
	static int a0[N],b0[N],b1[N];
	mms(a0,m);mms(b0,m);mmp(a0,a,n);mmp(b0,w,D);
	fft(a0,m,1);fft(b0,m,1);
	for(int i=0;i<m;i++)b1[i]=((2*b0[i]-(ll)a0[i]*b0[i]%P*b0[i])%P+P)%P;
	fft(b1,m,-1);mmp(b,b1,n);
}
void Ln(int a[],int b[],int n){
	if(n==1)return (void)(*b=0);
	static int ia[N],da[N],b0[N];
	Inv(a,ia,n-1);
	for(int i=1;i<n;i++)da[i-1]=(ll)a[i]*i%P;
	convol(ia,n-1,da,n-1,b0,n-1);
	b[0]=0;for(int i=1;i<n;i++)b[i]=(ll)b0[i-1]*inv[i]%P;
}
void Exp(int a[],int b[],int n){
	if(n==1)return (void)(*b=1);
	static int b0[N],_b0[N],w0[N],w1[N],w2[N];
	int D=(n+1)>>1,m=nxp(n+D-2);
	mms(b0,n);Exp(a,b0,D);Ln(b0,_b0,n);mmp(w0,b0,D);
	for(int i=0;i<n;i++)w1[i]=(a[i]-_b0[i]+P)%P;w1[0]++;
	convol(w0,D,w1,n,w2,n);mmp(b,w2,n);
}

int n,m;
int delta[N],lnDelta[N],sqrtDelta[N];
int lambda[N],lnLambda[N],lnAns[N],ans[N];

int main(){
	gi(n);gi(m);predo(nxp(m*2));m++;
	delta[0]=1;delta[1]=6;delta[2]=1;
	Ln(delta,lnDelta,m);
	for(int i=0;i<m;i++)lnDelta[i]=(ll)lnDelta[i]*(P/2+1)%P;
	Exp(lnDelta,sqrtDelta,m);
	lambda[0]=lambda[1]=1;
	for(int i=0;i<m;i++)lambda[i]=(ll)(lambda[i]+sqrtDelta[i])*(P/2+1)%P;
	Ln(lambda,lnLambda,m);
	for(int i=0;i<m;i++)lnAns[i]=((ll)lnLambda[i]*(n+1)-lnDelta[i]+P)%P;
	Exp(lnAns,ans,m);
	for(int i=n+1;i<m;i++)ans[i]=0;
	for(int i=1;i<m;i++)print(ans[i]),putc(' ');
	io::flush();
	return 0;
}