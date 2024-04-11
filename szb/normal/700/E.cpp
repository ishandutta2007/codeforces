#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld double
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
	void writeln(ll x){write(x);putchar('\n');}
	void Min(ll &x,ll y){x=x<y?x:y;}
	void Max(ll &x,ll y){x=x>y?x:y;}
	ll inline max(ll x,ll y){return x>y?x:y;}
	ll inline min(ll x,ll y){return x<y?x:y;}
}using namespace SHENZHEBEI;
const ll N=800010,M=16000010;
char s[N];
ll step[N],son[N][30],rk[N],f[N],g[N],rigt[N],rt[N],pre[N],c[N];
ll ls[M],rs[M],n,ans,cnt,Cnt;
namespace Sam{
	ll p,np,q,nq,now;
	ll merge(ll x,ll y){
		if (!x||!y)return x|y;
		ll p=++Cnt;
		ls[p]=merge(ls[x],ls[y]);
		rs[p]=merge(rs[x],rs[y]);
		return p;
	}
	void Insert(ll &p,ll l,ll r,ll pos){
		ll x=++Cnt;ls[x]=ls[p];rs[x]=rs[p];p=x;
		if (l==r)return;
		ll mid=(l+r)>>1;
		pos<=mid?Insert(ls[p],l,mid,pos):Insert(rs[p],mid+1,r,pos);
	}
	bool query(ll p,ll l,ll r,ll s,ll t){
		if (!p||(s<=l&&r<=t))return p;
		ll mid=(l+r)>>1,ans=0;
		if (s<=mid)ans|=query(ls[p],l,mid,s,t);
		if (t>mid)ans|=query(rs[p],mid+1,r,s,t);
		return ans;
	}
	void extend(ll ch,ll x){
		p=now;step[now=np=++cnt]=step[p]+1;rigt[np]=x;
		for(;p&&!son[p][ch];p=pre[p])son[p][ch]=np;
		if (!p)pre[np]=1;
		else{
			q=son[p][ch];
			if (step[q]==step[p]+1)pre[np]=q;
			else{
				step[nq=++cnt]=step[p]+1;rigt[nq]=x;
				memcpy(son[nq],son[q],sizeof son[q]);
				pre[nq]=pre[q];pre[q]=pre[np]=nq;
				for(;son[p][ch]==q;p=pre[p])son[p][ch]=nq;
			}
		}
	}
	void build(){
		cnt=now=1;
		For(i,1,n)extend(s[i]-'a',i);
		For(i,1,cnt)++c[step[i]];
		For(i,1,cnt)c[i]+=c[i-1];
		FOr(i,cnt,1)rk[c[step[i]]--]=i;
//		For(i,1,cnt)write(step[i]),putchar(' ');puts("");
//		for(;;);
//		For(i,1,cnt)write(pre[i]),putchar(' ');puts("");
		FOr(i,cnt,2){
			ll x=rk[i];
//			writeln(x);
			Insert(rt[x],1,n,rigt[x]);
			rt[pre[x]]=merge(rt[pre[x]],rt[x]);
		}
	}
	void work(){
		ans=1;
		For(i,2,cnt){
			ll x=rk[i];
			if (pre[x]==1)f[x]=1,g[x]=x;
			else{
				if (query(rt[g[pre[x]]],1,n,rigt[x]-step[x]+step[g[pre[x]]],rigt[x]-1))f[x]=f[pre[x]]+1,g[x]=x;
				else	f[x]=f[pre[x]],g[x]=g[pre[x]];
			}
			Max(ans,f[x]);
		}
	}
}
int main(){
	n=read();readstr(s+1);
	Sam::build();
	Sam::work();
	writeln(ans);
}