#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define mms(a,n) memset(a,0,sizeof((a)[0])*(n))
#define mmp(a,b,n) memcpy(a,b,sizeof((b)[0])*(n))
#define lowbit(x) ((x)&-(x))
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define lowbit(x) ((x)&-(x))
#define fo(i,l,r) for(register int i=l,_lim_=r;i<=_lim_;i++)
#define fd(i,r,l) for(register int i=r,_lim_=l;i>=_lim_;i--)

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pi;
typedef double db;
typedef long double ldb;

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
		for(c=gc();c!='_'&&(c<'a'||c>'z');c=gc());
		for(l=0;c=='_'||c<='z'&&c>='a';c=gc())s[l++]=c;
	}
};
using io::putc;
using io::gi;
using io::gs;
using io::print;

const int N=200005,M=32,L=525005;

int n,q,a[N],mx;
struct LinearBase{
	int a[M],m;
	int find(int k){
		for(int i=1;i<=m;i++)if((k^a[i])<k)k^=a[i];
		return k;
	}
	void ext(int k){
		if(mx>>m){
			if(k=find(k)){
				int j=1;
				while(k<=a[j])j++;
				++m;for(int i=m;i>j;i--)a[i]=a[i-1];
				a[j]=k;
				for(int i=1;i<j;i++)if((k^a[i])<a[i])a[i]^=k;
			}
		}	
	}
	friend LinearBase operator+(const LinearBase&a,const LinearBase&b){
		if((1ll<<a.m)>mx)return a;if((1ll<<b.m)>mx)return b;
		LinearBase ret=a;
		for(int i=1;i<=b.m;i++)ret.ext(b.a[i]);
		return ret;
	}
	void clear(){while(m)a[m--]=0;}
}seg[L],ans;

void build(int x,int l,int r){
	if(l==r){
		seg[x].ext(a[l]);
		return;
	}
	int mid=(l+r)>>1,ls=x<<1,rs=ls|1;
	build(ls,l,mid);build(rs,mid+1,r);
	seg[x]=seg[ls]+seg[rs];
}

void modify(int x,int l,int r,int p,int k){
	if(l==r){
		seg[x].a[1]^=k;
		mx=max(mx,seg[x].a[1]);
		if(!seg[x].a[1])seg[x].m=0;else seg[x].m=1;
		return;
	}
	int mid=(l+r)>>1,ls=x<<1,rs=ls|1;
	if(p<=mid)modify(ls,l,mid,p,k);
	else modify(rs,mid+1,r,p,k);
	seg[x]=seg[ls]+seg[rs];
}
void modify(int x,int l,int r,int p,int q,int k){
	if(l==r){
		seg[x].a[1]^=k;
		mx=max(mx,seg[x].a[1]);
		if(!seg[x].a[1])seg[x].m=0;else seg[x].m=1;
		return;
	}
	int mid=(l+r)>>1,ls=x<<1,rs=ls|1;
	if(q<=mid)modify(ls,l,mid,p,q,k);
	else if(p>mid)modify(rs,mid+1,r,p,q,k);
	else modify(ls,l,mid,p,k),modify(rs,mid+1,r,q,k);
	seg[x]=seg[ls]+seg[rs];
}

LinearBase query(int x,int l,int r,int s,int t){
	if(l==s&&r==t)return seg[x];
	int mid=(l+r)>>1,ls=x<<1,rs=ls|1;
	if(t<=mid)return query(ls,l,mid,s,t);
	if(s>mid)return query(rs,mid+1,r,s,t);
	if(t-mid>=mid-s+1){
		LinearBase w=query(rs,mid+1,r,mid+1,t);
		if((1ll<<w.m)>mx)return w;
		return w+query(ls,l,mid,s,mid);
	}
	LinearBase w=query(ls,l,mid,s,mid);
	if((1ll<<w.m)>mx)return w;
	return w+query(rs,mid+1,r,mid+1,t);
}

int sum[N];
void add(int x,int u){while(x<=n)sum[x]^=u,x+=lowbit(x);}
int ask(int x){int r=0;while(x)r^=sum[x],x-=lowbit(x);return r;} 

int main(){
	gi(n),gi(q);
	for(int i=1,s=0;i<=n;i++)gi(a[i]),add(i,a[i]),add(i+1,a[i]);
	for(int i=n;i>=1;i--)mx=max(mx,a[i]^=a[i-1]);
	build(1,1,n);
	for(int i=1,op,l,r,k;i<=q;i++){
		gi(op);gi(l);gi(r);
		if(op==1){
			gi(k);
			if(r<n)modify(1,1,n,l,r+1,k);else modify(1,1,n,l,k);
			add(l,k);add(r+1,k);
		}else{
			if(l<r)ans=query(1,1,n,l+1,r);else ans.clear();
			ans.ext(ask(l));
			print(1<<ans.m);
			putc('\n');
		}
	}
	io::flush();
	return 0;
}