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
typedef pair<ll,ll> pi;

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

const int N=10005;

void THROW(bool f){if(f)puts("NO"),exit(0);}

ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
void exgcd(ll a,ll b,ll&x,ll&y){
	if(!b)return (void)(x=1,y=0);
	exgcd(b,a%b,y,x);y-=a/b*x;
}
ll mult(ll x,ll y,ll z){return ((x*y-(ll)((ldb)x*y/z+0.5)*z)%z+z)%z;}
ll CRT(ll r1,ll m1,ll r2,ll m2){
	ll k,p;exgcd(m1,m2,k,p);
	return mult(k,r2-r1,m2)*m1+r1;
}
pi CRT(pi b1,pi b2){
	ll g=gcd(b1.se,b2.se),p=b1.fi%g,q=b2.fi%g;THROW(p!=q);
	b1.fi/=g;b1.se/=g;b2.fi/=g;b2.se/=g;
	ll ret=CRT(b1.fi,b1.se,b2.fi,b2.se)*g+p;
	ll mod=b1.se*b2.se*g; 
	return {ret,mod};
}

ll r,c,a[N],s=1,x,y;
pi now;
int n;

int main(){
	gi(r),gi(c),gi(n);
	for(int i=1;i<=n;i++){
		gi(a[i]);
		ll g=gcd(a[i],s);
		THROW(s/g*(long double)a[i]>r);
		s=s/g*a[i];
	}
	now.fi=0;now.se=1;
	for(int i=1;i<=n;i++)now=CRT(now,{(a[i]+1-i%a[i])%a[i],a[i]});
	x=s;y=now.fi;if(!y)y=s;
	THROW(y+n-1>c);
	for(int i=1;i<=n;i++)THROW(gcd(x,y+i-1)!=a[i]);
	puts("YES");
	return 0;
}