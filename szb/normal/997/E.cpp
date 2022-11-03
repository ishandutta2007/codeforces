

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld double
#define llu unsigned long long
#define rep(i,x,y)  for(int i=int(x);i<int(y);++i)
#define For(i,x,y)  for(int i=int(x);i<=int(y);++i)
#define FOr(i,x,y)  for(int i=int(x);i>=int(y);--i)
#define pi acos(-1) 
#define mk make_pair
#define pa pair<ll,ll>
#define lf else if
#define IL inline
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
#define y1			fafa____
typedef complex<double> E;
namespace SHENZHEBEI{
#ifdef LOCAL
    struct _{_(){freopen("cf.in","r",stdin);}}_; 
#endif 
#define NEG 1
    static const int GYN=2333333;
    char SZB[GYN],*S=SZB,*T=SZB;
    inline char gc(){   if (S==T){  T=(S=SZB)+fread(SZB,1,GYN,stdin); if (S==T) return '\n';  }   return *S++;    }
#if NEG
    inline ll read(){    ll x=0,g=1; char ch=gc();   for (;!isdigit(ch);ch=gc()) if (ch=='-') g=-1;  for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x*g; }
    inline void write(ll x){    if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#else
    inline ll read(){    ll x=0; char ch=gc();   for (;!isdigit(ch);ch=gc());    for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x;   }
    inline void write(ll x){    if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#endif
    inline char readchar(){ char ch=gc();   for(;isspace(ch);ch=gc());  return ch;  }
    inline ll readstr(char *s){ char ch=gc();   int cur=0;  for(;isspace(ch);ch=gc());      for(;!isspace(ch);ch=gc())  s[cur++]=ch;    s[cur]='\0';    return cur; }
	void Print(long long *a,int s,int t){For(i,s,t)printf("%lld ",a[i]);puts("");}
	void Print(int *a,int s,int t){For(i,s,t)printf("%d ",a[i]);puts("");}
	void Print(char *a,int s,int t){For(i,s,t)putchar(a[i]);puts("");}
	void writeln(ll x){write(x),puts("");}
	void Max(ll &x,ll y){x=x<y?y:x;}
	ll max(ll x,ll y){return x<y?y:x;}
}using namespace SHENZHEBEI;
const ll N=500010;
vector<ll>g[N];
ll l[N],r[N],a[N],answ[N],sum[N],ans[N],q1[N],q2[N],val[N],tag[N],tim[N],Q,n,top1,top2;
#define add(p,v)	val[p]+=v,tag[p]+=v
#define _add(p,v)	tim[p]+=v,ans[p]+=v*sum[p]
void build(ll l,ll r,ll p){
	sum[p]=1;val[p]=l;
	if (l==r)return;
	ll mid=(l+r)>>1;
	build(l,mid,p<<1);	build(mid+1,r,p<<1|1);
}
void pushdown(ll p){
	if(tag[p])add(p<<1,tag[p]),add(p<<1|1,tag[p]),tag[p]=0;
	if(tim[p]){
		if (val[p]==val[p<<1])_add(p<<1,tim[p]);
		if (val[p]==val[p<<1|1])_add(p<<1|1,tim[p]);
		tim[p]=0;
	}
}
void updata(ll p){
	val[p]=min(val[p<<1],val[p<<1|1]);
	ans[p]=ans[p<<1]+ans[p<<1|1];
	sum[p]=0;
	if (val[p]==val[p<<1])		sum[p]+=sum[p<<1];
	if (val[p]==val[p<<1|1])	sum[p]+=sum[p<<1|1];
//	pp(p,ans[p]);
//	pp(ans[p<<1],ans[p<<1|1]);
}
void modify(ll l,ll r,ll p,ll s,ll t,ll v){
	if (s<=l&&r<=t)return add(p,v),void(0);
	ll mid=(l+r)>>1;pushdown(p);
	if (s<=mid)modify(l,mid,p<<1,s,t,v);
	if (t>mid)modify(mid+1,r,p<<1|1,s,t,v);
	updata(p);
}
ll query(ll l,ll r,ll p,ll s,ll t){
	if (s<=l&&r<=t)return ans[p];
	ll mid=(l+r)>>1,Ans=0;pushdown(p);
	if (s<=mid)Ans+=query(l,mid,p<<1,s,t);
	if (t>mid)Ans+=query(mid+1,r,p<<1|1,s,t);
	return Ans;
}
int main(){
	n=read();
	For(i,1,n)a[i]=read();
	Q=read();
	For(i,1,Q){
		l[i]=read(),r[i]=read();
		g[r[i]].push_back(i);
	}build(1,n,1);
	For(i,1,n){
		add(1,-1);
		for(;top1&&a[q1[top1]]<a[i];--top1){
			modify(1,n,1,q1[top1-1]+1,q1[top1],a[i]-a[q1[top1]]);
		}
		for(;top2&&a[q2[top2]]>a[i];--top2){
			modify(1,n,1,q2[top2-1]+1,q2[top2],a[q2[top2]]-a[i]);
		}q1[++top1]=q2[++top2]=i;
		_add(1,1);
		rep(j,0,g[i].size()){
			ll now=g[i][j];
			answ[now]+=query(1,n,1,l[now],i);
		}
	}
	For(i,1,Q)writeln(answ[i]);
}