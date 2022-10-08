#include<bits/stdc++.h>

#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-funroll-loops")
#pragma GCC target("sse4")

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
#define GCD __gcd

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

const int N=100005,M=1050005,G=20;
// bit i: mod 2^{i+1}
int n,a[N],b[G],mv=M,pl[M],*bit[G],*pp=pl;
vector<int>best,cur;

int* newint(int len){int*p=pp;pp+=len;return p;}
int query(int i,int v){
	// when adding v (mod 2^{i+1}), is there any number in (2^i - v, 2^{i+1} - v] ? 
	int l=(1<<i)-v-1,r=(1<<i+1)-v-1;
	if(l<0)l+=1<<i+1;if(r<0)r+=1<<i+1;
	if(l<=r)return bit[i][r]-bit[i][l];
	return bit[i][r]+bit[i][b[i]]-bit[i][l];
}

void dfs(int p,int v){
	if(p==18){
		if(!query(p,v)&&SZ(cur)<SZ(best))best=cur;
		return;
	}
	if(query(p,v)){
		cur.pb(1<<p);dfs(p+1,v);cur.pop_back();
		cur.pb(-(1<<p));dfs(p+1,v+(1<<p));cur.pop_back();
	}else dfs(p+1,v);
}

int main(){
	fo(d,0,18)bit[d]=newint(1<<(d+1)),b[d]=b[d-1]+(1<<d);
	gi(n);
	fo(i,1,n){
		gi(a[i]);mv=min(mv,a[i]);
		fo(d,0,18)bit[d][a[i]&b[d]]++;
	}
	fo(d,0,18)fo(i,1,1<<d+1)bit[d][i]+=bit[d][i-1];
	best.resize(20);
	dfs(0,0);
	printf("%u\n",SZ(best));
	for(int v:best)printf("%d ",v);
	return 0;
}