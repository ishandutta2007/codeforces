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
#define mk make_pair<ll,ll>
#define pa pair<ll,ll>
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
#define p(x)        printf("~%d~\n",x)
#define pp(x,y)     printf("~~%d %d~~\n",x,y)
#define ppp(x,y,z)  printf("~~~%d %d %d~~~\n",x,y,z)
#define pppp(a,b,c,d)	printf("~~~%d %d %d %d\n",a,b,c,d)
#define f_in(x)     freopen(x".in","r",stdin)
#define f_out(x)    freopen(x".out","w",stdout)
#define open(x)     f_in(x),f_out(x)
#define fi first
#define se second
typedef complex<double> E;
namespace SHENZHEBEI{
#define NEG 1
    const int L=2333333;
    inline char gc(){	return getchar();	}
#if NEG
    inline ll read(){    ll x=0,f=1; char ch=gc();   for (;!isdigit(ch);ch=gc()) if (ch=='-') f=-1;  for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x*f; }
    inline void write(ll x){    if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#else
    inline ll read(){    ll x=0; char ch=gc();   for (;!isdigit(ch);ch=gc());    for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x;   }
    inline void write(ll x){    if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#endif
    inline char readchar(){ char ch=gc();   for(;isspace(ch);ch=gc());  return ch;  }
    inline ll readstr(char *s){ char ch=gc();   int cur=0;  for(;isspace(ch);ch=gc());      for(;!isspace(ch);ch=gc())  s[cur++]=ch;    s[cur]='\0';    return cur; }
    inline void writeln(ll x){  write(x);   puts("");   }
}using namespace SHENZHEBEI;
const ll N=200010,inf=2e9+233;
ll top[N],mx[N<<2],tag[N<<2],answ[N],a[N],t[N],id[N],fa[N],dep[N],num[N],son[N],q[N],dfn[N],siz[N];
ll ans,n,cnt,m;
bool cmp(ll x,ll y){return t[x]+dep[a[x]]!=t[y]+dep[a[y]]?t[x]+dep[a[x]]<t[y]+dep[a[y]]:a[x]<a[y];}
void pushdown(ll p,ll l,ll mid,ll r){
	if (tag[p]<=-inf)return;
	tag[p<<1]=tag[p<<1|1]=tag[p];
	mx[p<<1]=mid*2+tag[p];
	mx[p<<1|1]=r*2+tag[p];
	tag[p]=-inf;
}
void updata(ll p){mx[p]=max(mx[p<<1],mx[p<<1|1]);}
void change(ll p,ll l,ll r,ll s,ll t,ll v){
	if (s<=l&&r<=t)return tag[p]=v,mx[p]=r*2+v,void(0);
	ll mid=(l+r)>>1;pushdown(p,l,mid,r);
	if (s<=mid)	change(p<<1,l,mid,s,t,v);
	if (t>mid)	change(p<<1|1,mid+1,r,s,t,v);
	updata(p);
}
void query(ll p,ll l,ll r,ll s,ll t,ll v){
	if (mx[p]<=v)return;
	if (l==r)return ans=q[l],void(0);
	ll mid=(l+r)>>1;pushdown(p,l,mid,r);
	if (ans==-1&&t>mid)query(p<<1|1,mid+1,r,s,t,v);
	if (ans==-1&&s<=mid)query(p<<1,l,mid,s,t,v);
	updata(p);
}
ll work(ll x,ll t){
	ll y=x;
	for(;1;y=fa[top[y]]){
		ans=-1;
		query(1,0,n,dfn[top[y]],dfn[y],t+dfn[y]);
		if (ans!=-1){t+=dep[y]-dep[ans];y=ans;break;}
		if (!y)break;
		t+=dep[y]-dep[fa[top[y]]];
	}ll z=t+dep[x]-dep[y];
	for(;1;x=fa[top[x]]){
		if (top[x]==top[y]){
			if (x^y)change(1,0,n,dfn[y]+1,dfn[x],t-dfn[y]);
			break;
		}change(1,0,n,dfn[top[x]],dfn[x],dep[x]-dep[y]+t-dfn[x]);
	}return z;
}
int main(){
//	freopen("tree.in","r",stdin);
//	freopen("tree.out","w",stdout);
	memset(tag,-125,sizeof tag);
	n=read(),m=read();
	For(i,1,n)dep[i]=dep[fa[i]=read()]+1,siz[i]=1;
	FOr(i,n,1){
		if (siz[i]>siz[son[fa[i]]])son[fa[i]]=i;
		siz[fa[i]]+=siz[i];
	}
	for(ll i=son[0];i;i=son[i])q[dfn[i]=++cnt]=i;
	For(i,0,n)if (!dfn[i])for(ll j=i;j;j=son[j])top[q[dfn[j]=++cnt]=j]=i;
	For(i,1,m)a[i]=read(),t[i]=read(),id[i]=i;
	sort(id+1,id+m+1,cmp);
	For(i,1,m)answ[id[i]]=work(a[id[i]],t[id[i]]);
	For(i,1,m)printf("%d ",answ[i]);
}/**/