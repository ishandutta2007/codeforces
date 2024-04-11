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
#define I __attribute__((always_inline))inline
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

const int N=100055,M=305;

struct data
{
	std::vector<std::pair<ll,ll>>s,sl,sr;
}fe[M];

std::vector<int>p[N];
int n,m,uc,rc,fa[N],ri[N],ro[N],dep[N],sz[N],d[M][M];
ll ans,fs[N],fl[N];
bool use[N];
pii ue[M];

inline int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

inline bool dfs(int x)
{
	int c=0;sz[x]=1;
	foe(i,p[x])if(*i!=fa[x])
	{
		fa[*i]=x;
		dep[*i]=dep[x]+1;
		sz[x]+=sz[*i];
		if(dfs(*i))c++;
	}
	if(c>1)ri[x]=-1;
	if(ri[x])ri[x]=++rc,ro[rc]=x;
	return c>0||ri[x];
}

inline void dfs2(int x,int fa)
{
	fs[x]=1,fl[x]=0;
	foe(i,p[x])if(*i!=fa&&!use[*i])
	{
		dfs2(*i,x);
		fs[x]+=fs[*i];
		fl[x]+=fl[*i]+fs[*i];
	}
}

template<typename T>inline std::pair<std::pair<ll,ll>,ll> dfs3(int x,int fa,T chk)
{
	std::pair<std::pair<ll,ll>,ll>r=mp(mp(1,0),0);
	foe(i,p[x])if(*i!=fa&&chk(*i))
	{
		std::pair<std::pair<ll,ll>,ll>v=dfs3(*i,x,chk);
		v.xx.yy+=v.xx.xx;
		r.yy+=r.xx.xx*v.xx.yy+v.xx.xx*r.xx.yy;
		r.yy+=v.yy;
		r.xx.xx+=v.xx.xx;
		r.xx.yy+=v.xx.yy;
	}
	return r;
}

int main()
{
	//freopen("in.txt","r",stdin);
	in,n,m;
	fo1(i,n)fa[i]=i;
	fo1(i,m)
	{
		int x,y;
		in,x,y;
		if(find(x)!=find(y))
		{
			p[x].pb(y);
			p[y].pb(x);
			fa[find(x)]=find(y);
			//out,"tree:",x,' ',y,'\n';
		}
		else
		{
			ue[uc++]=mp(x,y);
			ri[x]=-1;
			ri[y]=-1;
		}
	}
	if(m==n-1)
	{
		out,dfs3(1,0,[&](int x){return 1;}).yy,'\n';
		return 0;
	}
	fa[1]=0;
	dfs(1);
	//fo1(i,n)out,ri[i],' ';out,'\n';
	mset(d,0x3f);
	fo1(i,n)if(ri[i])
	{
		int t=fa[i];
		while(t&&!ri[t])t=fa[t];
		if(t)d[ri[t]][ri[i]]=d[ri[i]][ri[t]]=dep[i]-dep[t];
	}
	fo0(i,uc)
	{
		int x=ri[ue[i].xx],y=ri[ue[i].yy];
		repl(d[x][y],1),repl(d[y][x],1);
	}
	fo1(i,rc)repl(d[i][i],0);
	fo1(i,rc)fo1(j,rc)fo1(k,rc)repl(d[j][k],d[j][i]+d[i][k]);
	//fo1(i,rc){fo1(j,rc)out,d[i][j],' ';out,'\n';}
	std::vector<pii>te;
	fo1(i,n)if(ri[i])
	{
		int t=fa[i];
		while(t&&!ri[t])t=fa[t];
		if(t)
		{
			te.pb(mp(i,t));
			for(int x=i;x!=t;x=fa[x])use[x]=1;
			use[t]=1;
		}
	}
	//out,"pre ok\n";
	//out,te.size(),' ',rc,'\n';
	//out,"te:";foe(i,te)out,'(',i->xx,',',i->yy,')',' ';out,'\n';
	fo1(i,n)if(ri[i])
	{
		dfs2(i,0);
		ans+=dfs3(i,0,[&](int x){return!use[x];}).yy;//
		//out,i,' ',ans,'\n';
	}
	auto solt=[&](std::pair<ll,ll>a,std::pair<ll,ll>b,int d)
	{
		ans+=a.yy*b.xx+a.xx*b.yy+(ll)d*a.xx*b.xx;
		//out,"solt:",a.xx,' ',a.yy,' ',b.xx,' ',b.yy,' ',ans,'\n';
	};
	fo0(i,rc-1)
	{
		int x=te[i].xx,y=te[i].yy;
		//out,"a1\n";
		for(int u=fa[x];u!=y;u=fa[u])
		{
			dfs2(u,0);
			fe[i].s.pb(mp(fs[u],fl[u]));
			ans+=dfs3(u,0,[&](int x){return!use[x];}).yy;//
		}
		//out,"a2\n";
		std::pair<ll,ll>t(0,0);
		fo0(j,fe[i].s.size())
		{
			t.xx+=fe[i].s[j].xx;
			t.yy+=fe[i].s[j].yy+fe[i].s[j].xx*ll(j+1);
			fe[i].sl.pb(t);
		}
		//out,"a3\n";
		t=mp(0,0);
		fd0(j,fe[i].s.size())
		{
			t.xx+=fe[i].s[j].xx;
			t.yy+=fe[i].s[j].yy+fe[i].s[j].xx*ll(fe[i].s.size()-j);
			fe[i].sr.pb(t);
		}
		if(fa[x]!=y)
		{
			//ans+=dfs3(fa[x],0,[&](int x){return!ri[x];}).yy;//
			//out,i,' ',ans,'\n';
			fo0(j,fe[i].s.size())
			{
				int o=j+1+d[ri[x]][ri[y]];
				//dis(j+o)==dis(r)
				if(j+o>=fe[i].s.size())o=fe[i].s.size()-1-j;
				else o+=(fe[i].s.size()-j-o)/2;
				if(fe[i].s.size()-o-j-1)solt(fe[i].s[j],fe[i].sr[fe[i].s.size()-o-j-2],j+1+d[ri[x]][ri[y]]);
				std::pair<ll,ll>tmp=fe[i].sl[j+o];
				tmp.xx-=fe[i].sl[j].xx;
				tmp.yy-=fe[i].sl[j].yy;
				tmp.yy-=(fe[i].sl[j+o].xx-fe[i].sl[j].xx)*(j+1);
				solt(fe[i].s[j],tmp,0);
			}
		}
		//out,"a4\n";
	}
	//out,"edge ok:",ans,'\n';
	//out,"ok3\n";
	//
	fo1(i,rc)fo1(j,i-1)ans+=(ll)fs[ro[i]]*fs[ro[j]]*d[i][j]+fl[ro[i]]*fs[ro[j]]+fs[ro[i]]*fl[ro[j]];
	//out,"pd ok:",ans,'\n';
	//
	auto sol=[&](std::pair<ll,ll>o,int dx,int dy,int id)
	{
		//out,"sol:",o.xx,' ',o.yy,' ',dx,' ',dy,' ',id,' ',fe[id].s.size(),'\n';
		if(abs(dx-dy)>=fe[id].s.size()||fe[id].s.size()==1)
		{
			if(dx<dy)solt(o,fe[id].sl.back(),dx);
			else solt(o,fe[id].sr.back(),dy);
			return;
		}
		int l=0,r=0;
		if(dx<dy)l+=dy-dx;else r+=dx-dy;
		int t=(fe[id].s.size()-l-r)/2;
		l+=t,r+=t;
		if(l+r!=fe[id].s.size()){if(!r)r++;else l++;}
		//out,"lr:",l,' ',r,'\n';
		solt(o,fe[id].sl[l-1],dx);
		solt(o,fe[id].sr[r-1],dy);
		//out,ans,'\n';
	};
	fo1(i,rc)fo0(j,rc-1)if(fe[j].s.size())
	{
		//out,'/',ro[i],'\n';
		int o=ro[i],x=ri[te[j].xx],y=ri[te[j].yy];
		int dx=d[i][x],dy=d[i][y];
		sol(mp(fs[o],fl[o]),dx,dy,j);
	}
	//out,"p-e ok\n";
	//
	fo0(i,rc-1)fo0(j,i)if(fe[j].s.size())
	{
		int xi=ri[te[i].xx],yi=ri[te[i].yy],x=ri[te[j].xx],y=ri[te[j].yy];
		int dxx=d[xi][x],dxy=d[xi][y],dyx=d[yi][x],dyy=d[yi][y];
		fo0(k,fe[i].s.size())
		{
			int l=k+1,r=fe[i].s.size()-k;
			sol(fe[i].s[k],min(dxx+l,dyx+r),min(dxy+l,dyy+r),j);
		}
	}
	out,ans,'\n';
}