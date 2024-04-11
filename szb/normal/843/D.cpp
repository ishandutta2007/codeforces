#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld double
#define llu unsigned long long
#define rep(i,x,y)  for(int i=(ll)(x);i<(ll)(y);++i)
#define For(i,x,y)  for(int i=(ll)(x);i<=(ll)(y);++i)
#define FOr(i,x,y)  for(int i=(ll)(x);i>=(ll)(y);--i)
#define pi acos(-1) 
#define mk make_pair
#define pa pair<ll,int>
#define lf else if
#define IL inline
#define max(x,y)    ((x)<(y)?(y):(x))
#define min(x,y)    ((x)<(y)?(x):(y))
#define sqr(x)      ((x)*(x))
#define Mul(x,y)    ((x)=1LL*(x)*(y)%mod)
#define Add(x,y)    ((x)=((x)+(y))%mod)
#define E(x)        return writeln(x),0
#define LL			(long long)
#define p(x)        printf("~%lld~\n",LL(x))
#define pp(x,y)     printf("~~%lld %lld~~\n",LL(x),LL(y))
#define ppp(x,y,z)  printf("~~~%lld %lld %lld~~~\n",LL(x),LL(y),LL(z))
#define pppp(a,b,c,d)	printf("~~~%lld %lld %lld %lld\n",LL(a),LL(b),LL(c),LL(d))
#define f_in(x)     freopen(x".in","r",stdin)
#define f_out(x)    freopen(x".out","w",stdout)
#define open(x)     f_in(x),f_out(x)
#define fi first
#define se second
#define GuYue		puts("\nGuYueNa________________________________________________________________________________")
typedef complex<double> E;
namespace SHENZHEBEI{
#ifdef LOCAL
    struct _{_(){freopen("cf.in","r",stdin);}}_; 
#endif 
#define NEG 1
    static const int GYN=2333333;
    char SZB[GYN],*SS=SZB,*TT=SZB;
    inline char gc(){   if (SS==TT){  TT=(SS=SZB)+fread(SZB,1,GYN,stdin); if (SS==TT) return '\n';  }   return 

*SS++;    }
#if NEG
    inline long long read(){    long long x=0,g=1; char ch=gc();   for (;!isdigit(ch);ch=gc()) if (ch=='-') 

g=-1;  for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x*g; }
    inline void write(long long x){    if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x

%10+'0');  }
#else
    inline long long read(){    long long x=0; char ch=gc();   for (;!isdigit(ch);ch=gc());    for (;isdigit

(ch);ch=gc())  x=x*10-48+ch;   return x;   }
    inline void write(long long x){    if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#endif
    inline char readchar(){ char ch=gc();   for(;isspace(ch);ch=gc());  return ch;  }
    inline long long readstr(char *s){ char ch=gc();   int cur=0;  for(;isspace(ch);ch=gc());      for(;!

isspace(ch);ch=gc())  s[cur++]=ch;    s[cur]='\0';    return cur; }
	void Print(long long *a,int s,int t){For(i,s,t)printf("%long longd ",a[i]);}
	void Print(int *a,int s,int t){For(i,s,t)printf("%d ",a[i]);}
	void Print(char *a,int s,int t){For(i,s,t)putchar(a[i]);}
	void writeln(long long x){write(x);puts("");}
	void Min(long long &x,long long y){x=x<y?x:y;}
	void Max(long long &x,long long y){x=x>y?x:y;}
}using namespace SHENZHEBEI;
const ll N=100010;
vector<int>Has[N],g[N];
priority_queue<pa,vector<pa>,greater<pa> >Q;
int n,m,QQ,x[N],y[N],fafa[N],w[N],head[N],nxt[N];
ll dis[N];
void Dijstra(){
	For(i,2,n)dis[i]=2e18;
	Q.push(mk(0,1));
	for(;!Q.empty();){
		ll x=Q.top().se;Q.pop();
		for(ll i=head[x];i;i=nxt[i]){
			ll to=y[i],val=w[i];
			if (dis[to]>dis[x]+val){
				dis[to]=dis[x]+val;
				Q.push(mk(dis[to],to));
			}
		}
	}
}
int main(){
	n=read(),m=read(),QQ=read();
	For(i,1,m){
		x[i]=read(),y[i]=read(),w[i]=read();
		nxt[i]=head[x[i]];head[x[i]]=i;
	}Dijstra();
	for(;QQ--;)if (read()==1){
		ll x=read();writeln(dis[x]>1e18?-1:dis[x]);
	}else{
		ll sum=read();For(i,1,sum)++w[read()];Min(sum,n);
		For(i,2,n)fafa[i]=2e18;
		Has[0].push_back(1);ll len=0;
		For(add_val,0,len){
		rep(szb,0,Has[add_val].size()){
			int x=Has[add_val][szb];
			if (fafa[x]!=add_val)continue;
			for(ll i=head[x];i;i=nxt[i]){
				int to=y[i],val=w[i]+fafa[x]+dis[x]-dis[to];
				if (val<=sum&&fafa[to]>val)
					fafa[to]=val,Has[val].push_back(to),Max(len,val);
			}
		}Has[add_val].clear();
		}
		For(i,2,n)dis[i]=min(2e18,dis[i]+fafa[i]);
	}
}
/*
,+i 
0	1	0	0	1	1	0

*/