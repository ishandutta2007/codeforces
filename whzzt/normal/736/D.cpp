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
typedef unsigned long long ull;
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
};
using io::putc;
using io::gi;
using io::gs;
using io::print;

const int N=2005,K=33,M=500005;

int n,m,w,x[M],y[M];

struct bst{
	ull a[K];
	inline void flip(int x){a[x>>6]^=1ull<<(x&63);}
	inline int operator[](int x){return a[x>>6]>>(x&63)&1;}
	bst& operator^=(const bst&x){
		for(int i=0;i<=w;i++)a[i]^=x.a[i];
		return*this;
	}
}a[N],b[N];

int main(){
	gi(n);gi(m);w=n>>6;
	for(int i=1;i<=n;i++)b[i].flip(i);
	for(int i=1;i<=m;i++)gi(x[i]),gi(y[i]),a[x[i]].flip(y[i]);
	for(int i=1;i<=n;i++){
		if(!a[i][i])for(int j=i+1;j<=n;j++)if(a[j][i]){a[i]^=a[j],b[i]^=b[j];break;}
		for(int j=1;j<=n;j++)if(i!=j&&a[j][i])a[j]^=a[i],b[j]^=b[i];
	}
	for(int i=1;i<=m;i++)
		if(!b[y[i]][x[i]])
			putc('Y'),putc('E'),putc('S'),putc('\n');
		else
			putc('N'),putc('O'),putc('\n');
	io::flush();
	return 0;
}