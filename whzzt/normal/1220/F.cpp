#pragma optimize("unroll-loops,no-stack-protector")
#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define ALL(a) a.begin(),a.end()
#define lowbit(x) ((x)&-(x))
#define dec minus_down
using namespace std;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef pair<int,int>pii;
typedef vector<int>VI;
typedef long long i64;
typedef long long ll;
typedef double ld;
namespace io{
	struct eof{eof(){}};
	const int L=(1<<21)|5;
	char ibuf[L],*iS,*iT,obuf[L],*oS=obuf,*oT=obuf+L-1,c,qu[55];int f,qr;
	#define gc() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,L,stdin),(iS==iT?EOF:*iS++)):*iS++)
	inline void flush(){fwrite(obuf,1,oS-obuf,stdout),oS=obuf;}
	inline void putc(char x){*oS++=x;if(oS==oT)flush();}
	template<class I>inline void gi(I&x){
		for(f=1,c=gc();(c<'0'||c>'9')&&(c!=EOF);c=gc())if(c=='-')f=-1;
 		if(c==EOF)throw eof();
		for(x=0;c<='9'&&c>='0';c=gc())x=x*10+(c&15);x*=f;
	}
	template<class I>inline void print(I x){
		if(!x)putc('0');if(x<0)putc('-'),x=-x;
		while(x)qu[++qr]=x%10+'0',x/=10;while(qr)putc(qu[qr--]);
	}
#if __cplusplus < 201103L
	// do nothing
#else
	struct StringReader{
		function<bool(char)>chk;
		StringReader(){chk=[&](char c){return c<='z'&&c>='a';};}
		StringReader(function<bool(char)>func){chk=func;}
		inline char read(){for(c=gc();!chk(c);c=gc());return c;}
		inline void gs(char*s){for(c=gc();!chk(c);c=gc());for(;chk(c);c=gc())*s++=c;*s=0;}
		string readString(){string s;for(c=gc();!chk(c);c=gc());for(;chk(c);c=gc())s+=c;return s;}
	};
#endif
	inline void ps(const char*s){int l=strlen(s),x;for(x=0;x<l;x++)putc(s[x]);}
	struct IOC{~IOC(){flush();}}ioc;
	inline double readld(){
		double x=0,y=1;
		for(c=gc();c<'0'||c>'9';c=gc())if(c=='-')y=-1;assert(c!='.');
		for(;c<='9'&&c>='0';c=gc())x=x*10+(c&15);x*=y;assert(c!='e');
		if(c=='.')for(c=gc();c<='9'&&c>='0';c=gc())y*=0.1,x+=y*(c&15);
		return x;
	}
	inline void printld(double x,int y){
		if(x<0)putc('-'),x=-x;x+=.5*pow(.1,y);print((u64)x),putc('.');
		for(x-=(u64)x;y;--y)x*=10,putc((int)x+'0'),x-=(int)x;
	}
}using io::gi;using io::print;using io::putc;
template<class T>int ctz(T a){return sizeof(T)>2?__builtin_ctzll(a):__builtin_ctz(a);}
template<class T>inline T gcd(T a,T b){
	int shift=ctz(a|b);
	for(b>>=ctz(b),a>>=ctz(a);a;a-=b,a>>=ctz(a))if(a<b)swap(a,b);
	return b<<shift;
}
template<class T>void exgcd(T a,T b,T&x,T&y){
	if(!b)return (void)(x=1,y=0);
	exgcd(b,a%b,y,x),y-=a/b*x;
}
template<class T>T Inv(T a,T p){T x,y;exgcd(a,p,x,y);return (x%p+p)%p;}
inline int fpow(int a,int t,int p){static int r;for(r=1;t;a=(ll)a*a%p,t>>=1)if(t&1)r=(ll)r*a%p;return r;}
string to_string(string s){return '"'+s+'"';};
string to_string(const char*s){return to_string(string(s));}
string to_string(bool f){return f?"true":"false";}
template<class A,class B>string to_string(pair<A,B>p){return "("+to_string(p.fi)+", "+to_string(p.se)+")";}
template<class T>string to_string(T v){string s="{",e="";for(auto&x:v)s+=e+to_string(x),e=", ";s+="}";return s;}
void debug_out(){cerr<<endl;}template<class A,class...B>void debug_out(A x,B...y){cerr<<" "<<to_string(x),debug_out(y...);}
void scan(){}template<class A,class...B>void scan(A&a,B&...b){gi(a),scan(b...);}
template<class T>void read(T first,T last){for(;first!=last;++first)gi(*first);}
template<class T>void write(T first,T last){for(;first!=last;putc(++first==last?'\n':' '))print(*first);}
template<class T>void show(T x){print(x),putc('\n');}
template<class A,class...B>void show(A a,B...b){print(a),putc(' '),show(b...);}
template<class T>inline bool chkmin(T&a,T b){return b<a?a=b,true:false;}
template<class T>inline bool chkmax(T&a,T b){return a<b?a=b,true:false;}
template<class T>inline T abs(T x){return x<0?-x:x;}
const int P=998244353,mod=P;
inline void inc(int&x,int y){x+=y;x<P?:x-=P;}
inline void inc(int&x,u64 y){x=(x+y)%P;}
inline void dec(int&x,int y){x-=y;x>=0?:x+=P;}
inline void dec(int&x,u64 y){x-=y%P;x>=0?:x+=P;}
inline int add(int x,int y){return (x+=y)<mod?x:x-mod;}
inline int sub(int x,int y){return (x-=y)<0?x+mod:x;}
inline int mul(int x,int y){return i64(x)*y%mod;}
inline void addx(int&x,int y){(x+=y)<mod?:x-=mod;}
inline void subx(int&x,int y){(x-=y)>=0?:x+=mod;}
template<class T>inline int sgn(T x){return (x>0)-(x<0);}
inline int fpow(int a,i64 t){
	static const int fmod=mod-1;
	t%=fmod;if(t<0)t+=fmod;int r;
	for(r=1;t;t>>=1,a=mul(a,a))if(t&1)r=mul(r,a);
	return r;
}
const int N=4e5+5;
namespace lct {
	struct node{
		node *c[2],*fa;
		int sz,sw,val,rval;
		multiset<int> w;
		bool rev;
		node();
		void pushup();
		void pushdown();
	}Tnull,*null=&Tnull,a[N];
	node::node(){
		c[0]=c[1]=fa=null;
		sz=sw=rev=val=rval=0;
		w.insert(0);
	}
	void node::pushup(){
		sz=c[0]->sz+c[1]->sz+1;
		sw=max(c[0]->sw,c[0]->sz+*--w.end());
		if(c[1]!=null) sw=max(sw,c[0]->sz+1+c[1]->sw);
		rval=c[1]==null?val:c[1]->rval;
	}
	void node::pushdown(){
		if (rev) {
			if(c[0]!=null)c[0]->rev^=1;
			if(c[1]!=null)c[1]->rev^=1;
			swap(c[0],c[1]),rev^=1;
		}
	}
	#define isroot(x) ((x)->fa->c[0]!=(x)&&(x)->fa->c[1]!=(x))
	void rotate(node*x){
		node*y=x->fa,*z=y->fa;
		if(z->c[0]==y)z->c[0]=x;
		if(z->c[1]==y)z->c[1]=x;
		bool l=y->c[1]==x,r=l^1;
		x->c[r]->fa=y,y->fa=x,x->fa=z;
		y->c[l]=x->c[r],x->c[r]=y,y->pushup();
	}
	node*st[N];int tp;
	void splay(node*x){
		st[tp=1]=x;
		for(node*y=x;!isroot(y);y=y->fa)st[++tp]=y->fa;
		while(tp)st[tp--]->pushdown();
		while(!isroot(x)){
			node*y=x->fa,*z=y->fa;
			if(!isroot(y))
				if(z->c[0]==y^y->c[0]==x)rotate(x);
				else rotate(y);
			rotate(x);
		}
		x->pushup();
	}
	node *findroot(node*x){
		splay(x); x->pushdown();
		for(x->pushdown();x->c[0]!=null;x=x->c[0],x->pushdown());
		return x;
	}
	node *findprev(node*x){
		splay(x); x->pushdown();
		for((x=x->c[0])->pushdown();x->c[1]!=null;x=x->c[1],x->pushdown());
		return x;
	}
	void access(node*x){
		node*y=null;
		for(;x!=null;y=x,x=x->fa){
			splay(x);
			if(x->c[1]!=null) x->w.insert(x->c[1]->sw+1);
			if(y!=null) x->w.erase(x->w.find(y->sw+1));
			x->c[1]=y;
			x->pushup();
		}
	}
	void link(node*x,node*y){
		//cerr<<"link "<<x->val<<' '<<y->val<<endl;
		access(x);
		splay(x);
		splay(y);
		y->fa=x;
		x->w.insert(y->sw+1);
		x->pushup();
	}
	void cut(node*x,node*y){
		//cerr<<"cut "<<x->val<<' '<<y->val<<endl;
		access(x);
		splay(x);
		splay(y);
		y->fa=null;
		x->w.erase(x->w.find(y->sw+1));
		x->pushup();
	}
};
using lct::node;
using lct::a;
const int M=20;
int n,c[N],L[N],R[N],qu[N],qr,f[M][N],lg[N];
int x,v;
int cmp(int a,int b){ return c[a]<c[b]?a:b; }
int ask(int l,int r){
	if(l>r) r+=n;
	int d=lg[r-l+1];
	int k=cmp(f[d][l],f[d][r-(1<<d)+1]);
	return k<=n?k:k-n;
}
int main(){
	scan(n);
	read(c+1,c+n+1);
	for(int i=1;i<=n;++i){
		while(qr>0&&c[qu[qr]]>c[i]) qu[qr--]=0;
		if(qr) L[i]=qu[qr];
		qu[++qr]=i;
	}
	qr=0;
	for(int i=n;i>=1;--i){
		while(qr>0&&c[qu[qr]]>c[i]) qu[qr--]=0;
		if(qr) R[i]=qu[qr];
		qu[++qr]=i;
	}
	for(int i=1;i<=n;++i) a[i].val=c[i];
	for(int i=1;i<=n;++i) c[i+n]=c[i];
	for(int i=1;i<=n<<1;++i) f[0][i]=i;
	for(int i=2;i<=n<<1;++i) lg[i]=lg[i-1]+!(i&i-1);
	for(int d=1;1<<d<=n<<1;++d) for(int i=1;i+(1<<d)-1<=n<<1;++i) {
		f[d][i]=cmp(f[d-1][i],f[d-1][i+(1<<(d-1))]);
	}
	for(int i=1;i<=n;++i){
		if(L[i]||R[i]){
			if(c[L[i]]>c[R[i]]) lct::link(a+L[i],a+i);
			else lct::link(a+R[i],a+i);
		}else lct::link(a,a+i);
	}
	x=0;
	lct::splay(a);
	v=a->sw;
	//cerr<<v<<' '<<x<<endl;
	for(int l=1;l<n;++l){
		node *p=a+l;
		lct::access(p);
		lct::splay(p);
		node *u=lct::findprev(p);
		lct::cut(u,p);
		int s=p-a,t=u-a;
		if(!t) s=l+1,t=l+n-1;
		else{
			if(s<l) s+=n; if(t<l) t+=n;
			if(s>t) swap(s,t);
			++s,--t;
		}
		if(s<=t){
			node *v=a+ask(s,t);
			lct::cut(p,v);
			lct::link(u,v);
		}
		node *q=a+(l==1?n:l-1);
		lct::access(q);
		lct::splay(q);
		if(q->rval>p->val){
			while(true){
				if(q->c[0]->rval>p->val) q=q->c[0];
				else if(q->val>p->val) break;
				else q=q->c[1];
			}
			lct::access(q);
			lct::splay(q);
			node *k=lct::findprev(q);
			lct::cut(k,q);
			lct::link(k,p);
			lct::link(p,q);
		}else{
			lct::access(q);
			lct::splay(q);
			lct::link(q,p);
		}
		lct::splay(a);
		if(a->sw<v) v=a->sw,x=l;
		//cerr<<v<<' '<<x<<endl;
	}
	print(v),putc(' '),print(x),putc('\n');
}