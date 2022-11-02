#include<bits/stdc++.h>

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef long double llf;
typedef std::pair<int,int> pii;

#define xx first
#define yy second

template<typename T> inline T max(T a,T b){return a>b?a:b;}
template<typename T> inline T min(T a,T b){return a<b?a:b;}
template<typename T> inline T abs(T a){return a>0?a:-a;}
template<typename T> inline bool repr(T &a,T b){return a<b?a=b,1:0;}
template<typename T> inline bool repl(T &a,T b){return a>b?a=b,1:0;}
template<typename T> inline T gcd(T a,T b){T t;if(a<b){while(a){t=a;a=b%a;b=t;}return b;}else{while(b){t=b;b=a%b;a=t;}return a;}}
template<typename T> inline T sqr(T x){return x*x;}
#define mp(a,b) std::make_pair(a,b)
#define pb push_back
#define I inline
#define mset(a,b) memset(a,b,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))

#define fo0(i,n) for(int i=0,i##end=n;i<i##end;i++)
#define fo1(i,n) for(int i=1,i##end=n;i<=i##end;i++)
#define fo(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define fd0(i,n) for(int i=(n)-1;~i;i--)
#define fd1(i,n) for(int i=n;i;i--)
#define fd(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define foe(i,x)for(__typeof((x).end())i=(x).begin();i!=(x).end();++i)
#define fre(i,x)for(__typeof((x).rend())i=(x).rbegin();i!=(x).rend();++i)

struct Cg{I char operator()(){return getchar();}};
struct Cp{I void operator()(char x){putchar(x);}};
#define OP operator
#define RT return *this;
#define UC unsigned char
#define RX x=0;UC t=P();while((t<'0'||t>'9')&&t!='-')t=P();bool f=0;\
if(t=='-')t=P(),f=1;x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0'
#define RL if(t=='.'){lf u=0.1;for(t=P();t>='0'&&t<='9';t=P(),u*=0.1)x+=u*(t-'0');}if(f)x=-x
#define RU x=0;UC t=P();while(t<'0'||t>'9')t=P();x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0'
#define TR *this,x;return x;
I bool IS(char x){return x==10||x==13||x==' ';}template<typename T>struct Fr{T P;I Fr&OP,(int&x)
{RX;if(f)x=-x;RT}I OP int(){int x;TR}I Fr&OP,(ll &x){RX;if(f)x=-x;RT}I OP ll(){ll x;TR}I Fr&OP,(char&x)
{for(x=P();IS(x);x=P());RT}I OP char(){char x;TR}I Fr&OP,(char*x){char t=P();for(;IS(t);t=P());if(~t){for(;!IS
(t)&&~t;t=P())*x++=t;}*x++=0;RT}I Fr&OP,(lf&x){RX;RL;RT}I OP lf(){lf x;TR}I Fr&OP,(llf&x){RX;RL;RT}I OP llf()
{llf x;TR}I Fr&OP,(uint&x){RU;RT}I OP uint(){uint x;TR}I Fr&OP,(ull&x){RU;RT}I OP ull(){ull x;TR}};Fr<Cg>in;
#define WI(S) if(x){if(x<0)P('-'),x=-x;UC s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
#define WL if(y){lf t=0.5;for(int i=y;i--;)t*=0.1;if(x>=0)x+=t;else x-=t,P('-');*this,(ll)(abs(x));P('.');if(x<0)\
x=-x;while(y--){x*=10;x-=floor(x*0.1)*10;P(((int)x)%10+'0');}}else if(x>=0)*this,(ll)(x+0.5);else *this,(ll)(x-0.5);
#define WU(S) if(x){UC s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
template<typename T>struct Fw{T P;I Fw&OP,(int x){WI(10);RT}I Fw&OP()(int x){WI(10);RT}I Fw&OP,(uint x){WU(10);RT}
I Fw&OP()(uint x){WU(10);RT}I Fw&OP,(ll x){WI(19);RT}I Fw&OP()(ll x){WI(19);RT}I Fw&OP,(ull x){WU(20);RT}I Fw&OP()
(ull x){WU(20);RT}I Fw&OP,(char x){P(x);RT}I Fw&OP()(char x){P(x);RT}I Fw&OP,(const char*x){while(*x)P(*x++);RT}
I Fw&OP()(const char*x){while(*x)P(*x++);RT}I Fw&OP()(lf x,int y){WL;RT}I Fw&OP()(llf x,int y){WL;RT}};Fw<Cp>out;

const int N=200007,M=2000007,P=1000000007;

int n,pm,s[N],p[M],lo[M],ans[M],a2[M],f[23];
pii st[N];
bool fin;

inline void fafa(int x)
{
	int c=0;
	while(x!=1)
	{
		f[c++]=lo[x];
		x/=lo[x];
	}
	for(int i=0,t;i<c;i=t)
	{
		for(t=i;t<c&&f[i]==f[t];t++);
		repr(ans[f[i]],t-i);
	}
}

inline void fafa2(int x)
{
	int c=0;
	while(x!=1)
	{
		f[c++]=lo[x];
		x/=lo[x];
	}
	for(int i=0,t;i<c;i=t)
	{
		for(t=i;t<c&&f[i]==f[t];t++);
		if(ans[f[i]]==t-i)a2[f[i]]++;
	}
}

inline bool fafa3(int x)
{
	int c=0;
	while(x!=1)
	{
		f[c++]=lo[x];
		x/=lo[x];
	}
	bool flag=1;
	for(int i=0,t;i<c;i=t)
	{
		for(t=i;t<c&&f[i]==f[t];t++);
		flag&=ans[f[i]]!=t-i||a2[f[i]]>1;
	}
	return flag;
}

inline bool chk(int x)
{
	int c=0;
	while(x!=1)
	{
		f[c++]=lo[x];
		x/=lo[x];
	}
	bool flag=0;
	for(int i=0,t;i<c;i=t)
	{
		for(t=i;t<c&&f[i]==f[t];t++);
		if(ans[f[i]]<t-i)flag=1;
	}
	return flag;
}

int q[N];

int main()
{
	fo(i,2,M-1)
	{
		if(!lo[i])p[pm++]=i,lo[i]=i;
		for(int j=0;i*p[j]<M;j++)
		{
			lo[i*p[j]]=p[j];
			if(i%p[j]==0)break;
		}
	}
	in,n;
	fo1(i,n)in,s[i];
	std::sort(s+1,s+n+1,std::greater<int>());
	int m=0;
	for(int i=1,t;i<=n;i=t)
	{
		for(t=i;t<=n&&s[i]==s[t];t++);
		int c=t-i;
		st[++m]=mp(s[i],c);
	}
	fo1(i,m)if(st[i].yy>2)st[i].yy--,fin=1;
	int qc=0;
	fo1(i,m)if(st[i].yy>=2)
	{
		if(chk(st[i].xx))st[i].yy--,fafa(st[i].xx),q[qc++]=st[i].xx;
		else if(chk(st[i].xx-1))st[i].yy--,fafa(st[i].xx-1),q[qc++]=st[i].xx-1;
		else fin=1,st[i].yy--;
	}
	fo1(i,m)if(st[i].yy>=1)
	{
		if(chk(st[i].xx))st[i].yy--,fafa(st[i].xx),q[qc++]=st[i].xx;
		else if(chk(st[i].xx-1))st[i].yy--,fafa(st[i].xx-1),q[qc++]=st[i].xx-1;
		else fin=1,st[i].yy--;
	}
	std::sort(q,q+qc,std::greater<int>());
	fo0(i,qc)fafa2(q[i]);
	fo0(i,qc)if(fafa3(q[i]))fin=1;
	int ta=1;
	fo1(i,M-1)fo0(j,ans[i])ta=(ll)ta*i%P;
	if(fin)(++ta)%=P;
	out,ta,'\n';
}