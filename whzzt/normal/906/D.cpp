#include<bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
#define Clear(a) memset(a,0,sizeof(a))
#define Copy(a,b) memcpy(a,b,sizeof(b))
#define ALL(v) v.begin(),v.end()
#define SZ(v) ((int)v.size()-1)

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ldb;
typedef double db;
typedef pair<int,int> pi;

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
};
using io::putc;
using io::gi;
using io::gs;
using io::print;

const int N=100005,G=65;

int n,num[N],p,mod[G],m,q,ans;

int phi(int n){
	int ret=n;
	for(int p=2;p*p<=n;p++)if(n%p==0){
		ret=ret/p*(p-1);
		while(n%p==0)n/=p;
	}
	if(n>1)ret=ret/n*(n-1);
	return ret;
}
int tpow(int a,int t,int p){
	int r=1;
	bool f=false,o=false;
	for(;t;t>>=1,o|=(ll)a*a>=p,a=(ll)a*a%p)if(t&1){
		f|=o;
		if((ll)r*a>=p)f=true;
		r=(ll)r*a%p;
	}
	return r+(f?p:0);
}

int main(){
	gi(n),gi(p);
	for(int i=1;i<=n;i++)gi(num[i]);
	while(p>1)mod[m++]=p,p=phi(p);mod[m]=1;
	gi(q);
	for(int i=1,l,r;i<=q;i++){
		gi(l);gi(r);
		if(r>l+m)r=l+m;ans=1;
		for(int p=r;p>=l;p--)ans=tpow(num[p],ans,mod[p-l]);
		printf("%d\n",ans%*mod);
	}
	return 0;
}