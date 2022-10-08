#pragma GCC diagnostic error "-std=c++11"
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
template<class T>inline bool chkmin(T&a,T b){return b<a?a=b,true:false;}
template<class T>inline bool chkmax(T&a,T b){return a<b?a=b,true:false;}
template<class T>inline T abs(T x){return x<0?-x:x;}
const int P=998244353;
inline void inc(int&x,int y){x+=y;x<P?:x-=P;}
inline void inc(int&x,u64 y){x=(x+y)%P;}
inline void dec(int&x,int y){x-=y;x>=0?:x+=P;}
inline void dec(int&x,u64 y){x-=y%P;x>=0?:x+=P;}
template<class T>inline int sgn(T x){return (x>0)-(x<0);}
const int N=1e6+5,M=1e6,L=100005,E=305;
map<vector<int>,int>go,dd;
map<u64,int>n1,n2;
int T,pr[N],pc,mp[N],cnt,ccnt,dis[L][E],ans[E][E];
u64 calc(vector<int>u){
	u64 s=1;
	for(int v:u)s*=v+1;
	return s;
}
void dfs(vector<int>cur,int num){
	int p=pr[cur.size()+1];
	int emax=cur.size()?*cur.rbegin():20;
	int e=0;
	go[cur]=++cnt;
	if(!n1.count(calc(cur)))n1[calc(cur)]=++ccnt;
	while((u64)num*p<=M&&e<emax)num*=p,++e,cur.pb(e),dfs(cur,num),cur.pop_back();
}
int main(){
	int i,j,v,c,a,b;
	for(mp[1]=1,i=2;i<=M;i++)if(!mp[i])for(mp[i]=pr[++pc]=i,j=i+i;j<=M;j+=i)mp[j]=i;
	memset(dis,0x3f,sizeof(dis)),memset(ans,0x3f,sizeof(ans));
	dfs(vector<int>(),1);
	dd=go,n2=n1;
	for(auto it:go){
		queue<pair<vector<int>,int>>q;
		set<vector<int>>vis;
		v=go[it.fi],q.push(make_pair(it.fi,0));
		vis.insert(it.fi);
		if(!n2.count(calc(it.fi)))n2[calc(it.fi)]=++ccnt;
		while(q.size()){
			vector<int>tt;int ee;
			tie(tt,ee)=q.front(),q.pop();
			if(!n2.count(calc(tt)))n2[calc(tt)]=++ccnt;
			chkmin(dis[n2[calc(tt)]][v],ee),++ee;
			if(ee>=9)continue;
			tt.pb(0);vector<int>ss;
			for(i=0;i<tt.size();i++)if(i==0||tt[i-1]!=tt[i]){
				ss=tt,ss[i]++;
				while(ss.size()&&*ss.rbegin()==0)ss.pop_back();
				if(!vis.count(ss)){
					vis.insert(ss);
					if(!dd.count(ss))dd[ss]=++cnt;
					q.push(make_pair(ss,ee));
				}
			}
			for(i=0;i+1<tt.size();i++)if(tt[i]!=tt[i+1]){
				ss=tt,ss[i]--;
				while(ss.size()&&*ss.rbegin()==0)ss.pop_back();
				if(!vis.count(ss)){
					vis.insert(ss);
					if(!dd.count(ss))dd[ss]=++cnt;
					q.push(make_pair(ss,ee));
				}
			}
		}
	}
	for(i=1;i<=ccnt;i++){
		vector<int>p;
		for(a=1;a<=go.size();a++)if(dis[i][a]<10)p.pb(a);
		for(int a:p)for(int b:p)chkmin(ans[a][b],dis[i][a]+dis[i][b]);
	}
	for(a=1;a<=go.size();a++)for(b=1;b<=go.size();b++)if(ans[a][b]>10)ans[a][b]=10;
	for(scan(T);T;--T){
		scan(a,b);
		vector<int>g;
		v=c=0;
		for(;a>1;a/=mp[a]){
			if(mp[a]!=v){
				if(c)g.pb(c);
				v=mp[a],c=1;
			}else ++c;
		}
		if(c)g.pb(c);
		sort(ALL(g)),reverse(ALL(g)),a=go[g];
		g.clear();
		v=c=0;
		for(;b>1;b/=mp[b]){
			if(mp[b]!=v){
				if(c)g.pb(c);
				v=mp[b],c=1;
			}else ++c;
		}
		if(c)g.pb(c);
		sort(ALL(g)),reverse(ALL(g)),b=go[g];
		print(ans[a][b]),putc('\n');
	}
}