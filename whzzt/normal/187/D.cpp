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
#define sqr(x) ((ll)(x)*(x))
#define GCD __gcd

using namespace std;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ldb;
typedef double db;
typedef pair<uint,uint> pi;
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
	struct IOFLUSHER{~IOFLUSHER(){flush();}}_ioflusher_;
};
using io::putc;
using io::gi;
using io::gs;
using io::ps;
using io::print;

const int N=100005,M=4000005;

set<pi>D;
uint n,m,q,a,b,rt[N];
uint ls[M],rs[M],sz[M],ec;
ll s[N],dp[N],ret[N];

void copynode(uint&x){uint y=++ec;ls[y]=ls[x];rs[y]=rs[x];sz[y]=sz[x];x=y;}
void modify(uint&x,uint l,uint r,uint p){
	copynode(x);sz[x]++;if(l==r)return;
	int mid=(l+r)>>1;
	if(p<=mid)modify(ls[x],l,mid,p);else modify(rs[x],mid+1,r,p);
}
bool any(uint x,uint y,uint l,uint r,uint s,uint t){
	if(sz[x]==sz[y])return false;
	if(l==s&&r==t)return true;
	int mid=(l+r)>>1;
	if(t<=mid)return any(ls[x],ls[y],l,mid,s,t);
	if(s>mid)return any(rs[x],rs[y],mid+1,r,s,t);
	return any(ls[x],ls[y],l,mid,s,mid)||any(rs[x],rs[y],mid+1,r,mid+1,t);
}
bool wait(uint u,uint v){
	uint x=(a+s[u])%m,y=(s[u]+m-1)%m;
	if(x<=y)
		return any(rt[v],rt[u],0,m-1,x,y);
	return any(rt[v],rt[u],0,m-1,x,m-1)||any(rt[v],rt[u],0,m-1,0,y);
}

void ban(uint l,uint r,ll val,ll mval){
	set<pi>::iterator it;
	for(it=D.lower_bound(pi(l,0));it!=D.end()&&it->fi<=r;D.erase(it++)){
		ret[it->se]+=(it->fi+val-1)/m*m+m+mval;
	}
}

int main(){
	uint i,l,r,mid,t;
	gi(n);gi(a);gi(b);m=a+b;
	for(i=1;i<=n+1;i++){
		gi(s[i]);
		s[i]=s[i]+s[i-1];
		modify(rt[i]=rt[i-1],0,m-1,s[i]%m);
	}
	for(i=n;i>=1;i--){
		l=i+1;r=n+1;mid=(l+r)>>1;
		while(l<r){
			if(wait(i,mid))
				r=mid;
			else
				l=mid+1;
			mid=(l+r)>>1;
		}
		if(mid<=n)
			dp[i]=dp[mid]+(s[mid]-s[i]-1)/m*m+m;
		else
			dp[i]=dp[mid]+s[mid]-s[i];
	}
	gi(q);
	for(i=1;i<=q;i++){
		gi(t);
		D.insert(pi(t%m,i));
		ret[i]=t/m*m;
	}
	for(i=1;i<=n;i++){
		l=((a-s[i])%m+m)%m;
		r=m-1-s[i]%m;
		if(l<=r)
			ban(l,r,s[i],dp[i]);
		else
			ban(l,m-1,s[i],dp[i]),ban(0,r,s[i],dp[i]);
	}
	for(set<pi>::iterator it=D.begin();it!=D.end();++it)
		ret[it->se]+=it->fi+s[n+1];
	for(i=1;i<=q;i++)
		print(ret[i]),putc('\n');
	return 0;
}