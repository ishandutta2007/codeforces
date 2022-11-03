#include<bits/stdc++.h>
using namespace std;
#define ll int
#define llu unsigned long long
#define ld double
#define llu unsigned long long
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
#define pi acos(-1)
#define mk make_pair<ld,ld>
#define pa pair<ld,ld>
#define lf else if
#define max(x,y)    ((x)<(y)?(y):(x))
#define min(x,y)    ((x)<(y)?(x):(y))
#define sqr(x)      ((x)*(x))
#define abs(x)      ((x)>0?(x):-(x))
#define Mul(x,y)    ((x)=1LL*(x)*(y)%mod)
#define Add(x,y)    ((x)=((x)+(y))%mod)
#define Max(x,y)    ((x)=((x)<(y)?(y):(x)))
#define Min(x,y)    ((x)=((x)>(y)?(y):(x)))
#define E(x)        return writeln(x),0
#define p(x)        prllf("~%d~\n",x)
#define pp(x,y)     prllf("~~%d %d~~\n",x,y)
#define ppp(x,y,z)  prllf("~~~%d %d %d~~~\n",x,y,z)
#define pppp(a,b,c,d)	prllf("~~~%d %d %d %d\n",a,b,c,d)
#define f_in(x)     freopen(x".in","r",stdin)
#define f_out(x)    freopen(x".out","w",stdout)
#define open(x)     f_in(x),f_out(x)
namespace SHENZHEBEI{
#define NEG 1
    const ll L=2333333;
    char SZB[L],*S=SZB,*T=SZB;
    inline char gc(){   if (S==T){  T=(S=SZB)+fread(SZB,1,L,stdin); if (S==T) return '\n';  }   return *S++;    }
#if NEG
    inline ll read(){    ll x=0,f=1; char ch=gc();   for (;!isdigit(ch);ch=gc()) if (ch=='-') f=-1;  for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x*f; }
    inline void write(ll x){    if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#else
    inline ll read(){    ll x=0; char ch=gc();   for (;!isdigit(ch);ch=gc());    for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x;   }
    inline void write(ll x){    if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#endif
    inline char readchar(){ char ch=gc();   for(;isspace(ch);ch=gc());  return ch;  }
    inline ll readstr(char *s){ char ch=gc();   ll cur=0;  for(;isspace(ch);ch=gc());      for(;!isspace(ch);ch=gc())  s[cur++]=ch;    s[cur]='\0';    return cur; }
    inline void writeln(ll x){  write(x);   puts("");   }
}using namespace SHENZHEBEI;
struct edge{ll from,to,Nxt;};
struct TU{
    stack<ll> s;
    edge e[400005];
    ll head[400005],Low[400005],sccno[400005],pre[400005],num[400005],Out[400005],cnt,dfsc,n,m;
    TU(){m=0;memset(head,-1,sizeof(head));}
    void SCC(){
        dfsc=cnt=0;
        memset(num,0,sizeof(num));
        memset(sccno,0,sizeof(sccno));
        memset(pre,0,sizeof(pre));
        for(ll i=1;i<=n;i++)
            if (!pre[i])
                dfs(i);
    }
    void dfs(ll u){
        pre[u]=Low[u]=++dfsc;
        s.push(u);
        for(ll i=head[u];i!=-1;i=e[i].Nxt){
            ll v=e[i].to;
            if (!pre[v]){
                dfs(v);
                Low[u]=min(Low[u],Low[v]);
            } else if (!sccno[v])
                Low[u]=min(Low[u],pre[v]);
            
        }
        if (Low[u]==pre[u]){
            cnt++;
            for(;;){
                ll x=s.top(); s.pop();  sccno[x]=cnt;   num[cnt]++;    if (x==u)    break;
            }
        }
    }
    void Work(){
        memset(Out,5,sizeof(Out));
        for(ll i=1;i<=n;i++){
            for(ll j=head[i];j!=-1;j=e[j].Nxt)
                if (sccno[i]!=sccno[e[j].to])
                    Out[sccno[i]]=false;
        }
		ll to=0,ans=n+1;
		for(ll i=1;i<=cnt;i++)if (Out[i] && num[i]<ans)		ans=num[i],to=i;
				writeln(ans);
		for(ll i=1;i<=n;i++)	if (sccno[i]==to)write(i),putchar(' ');
    }
    void addedge(ll from,ll to){
        e[++m]=(edge){from,to,head[from]};
        head[from]=m;
    }
}gg;
ll a[200002];
int main(){
	ll n=gg.n=read(),m=read(),h=read();
	For(i,1,n)a[i]=read();
	while(m--){
		ll u=read(),v=read();
		if (a[u]==(a[v]+1)%h)gg.addedge(v,u);
		if (a[v]==(a[u]+1)%h)gg.addedge(u,v);
	}
	gg.SCC();
	gg.Work();
}