#include<bits/stdc++.h>

#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-funroll-loops")
#pragma GCC target("avx,sse4")

#define mms(a,n) memset(a,0,sizeof((a)[0])*(n))
#define mmp(a,b,n) memcpy(a,b,sizeof((b)[0])*(n))
#define lowbit(x) ((x)&-(x))
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define fo(i,l,r) for(register int i=l,_lim_=r;i<=_lim_;i++)
#define fd(i,r,l) for(register int i=r,_lim_=l;i>=_lim_;i--)
#define fos(i,l,r,d) for(register int i=l,_lim_=r;i<=r;i+=d)
#define fol(i,l,r) for(register ll i=l,_lim_=r;i<=_lim_;i++)
#define fdl(i,r,l) for(register ll i=r,_lim_=l;i>=_lim_;i--)
#define fosl(i,l,r,d) for(register ll i=l,_lim_=r;i<=r;i+=d)
#define Clear(a) memset(a,0,sizeof(a))
#define Copy(a,b) memcpy(a,b,sizeof(b))
#define ALL(v) v.begin(),v.end()
#define SZ(v) ((int)v.size())
#define sqr(x) ((x)*(x))

using namespace std;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ldb;
typedef double db;
typedef pair<int,int> pi;
typedef vector<int> VI;
typedef vector<VI> VII;

namespace io{
	const int L=(1<<21)+1;
	char ibuf[L],*iS,*iT,obuf[L],*oS=obuf,*oT=obuf+L-1,c,st[55];int f,tp;
	#ifdef whzzt
		#define gc() getchar()
	#else
		#define gc() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,L,stdin),(iS==iT?EOF:*iS++)):*iS++)
	#endif
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
		for(c=gc();c<'a'||c>'z';c=gc());
		for(l=0;c<='z'&&c>='a';c=gc())s[l++]=c;
	}
	inline void ps(const char*s){
		fo(i,0,strlen(s)-1)putc(s[i]);
	}
};
using io::putc;
using io::gi;
using io::gs;
using io::ps;
using io::print;

const int N=1<<17,M=17,P=1e9+7;
int inv(int p){
	if(p<=1)return p;
	return P-(ll)(P/p)*inv(P%p)%P;
}
const int iN=inv(N);

int n,x[N],a[N],b[N],c[N],y[N],fib[N],t[M+1][N],r[M+1][N],w[N],bit[N],i,j,k,l,p,q,u,v,ret;

int main(){
	for(i=1;i<N;i++)bit[i]=bit[i>>1]+(i&1);
	fib[1]=1;
	for(i=2;i<N;i++)fib[i]=(fib[i-1]+fib[i-2])%P;
	gi(n);
	for(i=1;i<=n;i++)gi(j),x[j]++;
	for(i=0;i<N;i++)t[bit[i]][i]=x[i];
	for(p=0;p<=M;p++){
		for(l=2;l<=N;l<<=1)for(i=l>>1,j=0;j<N;j+=l)for(k=0;k<l>>1;k++){
			t[p][j+k+i]=(t[p][j+k+i]+t[p][j+k])%P;
		}
	}
	for(p=0;p<=M;p++)for(q=0;q<=p;q++){
		for(i=0;i<N;i++){
			r[p][i]=(r[p][i]+(ll)t[q][i]*t[p-q][i])%P;
		}
	}
	for(p=0;p<=M;p++){
		for(l=2;l<=N;l<<=1)for(i=l>>1,j=0;j<N;j+=l)for(k=0;k<l>>1;k++){
			r[p][j+k+i]=(r[p][j+k+i]-r[p][j+k]+P)%P;
		}
	}
	for(i=0;i<N;i++)a[i]=(ll)r[bit[i]][i]*fib[i]%P;
	for(i=0;i<N;i++)b[i]=(ll)x[i]*fib[i]%P;
	for(i=0;i<N;i++)w[i]=x[i];
	for(l=2;l<=N;l<<=1)for(i=l>>1,j=0;j<N;j+=l)for(k=0;k<l>>1;k++){
		u=w[j+k];v=w[j+k+i];
		w[j+k]=(u+v)%P;
		w[j+k+i]=(u-v+P)%P;
	}
	for(i=0;i<N;i++)w[i]=(ll)w[i]*w[i]%P;
	for(l=2;l<=N;l<<=1)for(i=l>>1,j=0;j<N;j+=l)for(k=0;k<l>>1;k++){
		u=w[j+k];v=w[j+k+i];
		w[j+k]=(u+v)%P;
		w[j+k+i]=(u-v+P)%P;
	}
	for(i=0;i<N;i++)c[i]=(ll)w[i]*fib[i]%P*iN%P;
	for(l=2;l<=N;l<<=1)for(i=l>>1,j=0;j<N;j+=l)for(k=0;k<l>>1;k++){
		(a[j+k]+=a[j+k+i])%=P;
		(b[j+k]+=b[j+k+i])%=P;
		(c[j+k]+=c[j+k+i])%=P;
	}
	for(i=0;i<N;i++)y[i]=(ll)a[i]*b[i]%P*c[i]%P;
	for(l=2;l<=N;l<<=1)for(i=l>>1,j=0;j<N;j+=l)for(k=0;k<l>>1;k++)
		y[j+k]=(y[j+k]-y[j+k+i]+P)%P;
	for(i=0;i<M;i++)ret=(ret+y[1<<i])%P;
	printf("%d\n",ret);
	return 0;
}