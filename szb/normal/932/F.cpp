#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
#define Max(x,y)    ((x)=((x)<(y)?(y):(x))
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
#ifdef LOCAL
    struct _{_(){freopen("cf.in","r",stdin);}}_;
#endif
#define NEG 1
    inline char gc(){   return getchar();   }
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
    inline ld getreal(){    static ld lbc;  scanf("%lf",&lbc);  return lbc; }
}using namespace SHENZHEBEI;
const ll N=1000010,M=8000010,inf=1e18;
const int LL=-100000,RR=100000;
ll head[N],nxt[N],vet[N],ans[N],n,cnt,a[N],b[N],A[M],B[M];
ll tot;
int ls[M],rs[M],rt[N];
void insert(ll x,ll y){nxt[++tot]=head[x];head[x]=tot;vet[tot]=y;}
void change(int &x,ll a,ll b,int l,int r){
	if (!x)return x=++cnt,A[x]=a,B[x]=b,void(0);
	ll mid=(l+r)>>1;
	if (A[x]+B[x]*l>a+b*l)swap(A[x],a),swap(B[x],b);
	if (l==r)return;
	if (A[x]+mid*B[x]>a+mid*b){
		swap(A[x],a),swap(B[x],b);
		change(ls[x],a,b,l,mid);
	}lf (A[x]+r*B[x]>a+r*b)
		change(rs[x],a,b,mid+1,r);
}
void merge(int &x,int y,int l,int r){
	if (!x||!y)return x+=y,void(0);
	ll mid=(l+r)>>1;
	merge(ls[x],ls[y],l,mid);
	merge(rs[x],rs[y],mid+1,r);
	change(x,A[y],B[y],l,r);
}
ll ask(int x,int k,int l,int r){
	if (!x)return inf;
	if (l==r)return A[x]+1LL*B[x]*k;
	ll mid=l+r>>1;
	return min(A[x]+1LL*B[x]*k,k<=mid?ask(ls[x],k,l,mid):ask(rs[x],k,mid+1,r));
}
void dfs(ll x,ll pre){
	for(ll i=head[x];i;i=nxt[i])if (vet[i]!=pre){
		dfs(vet[i],x);
		merge(rt[x],rt[vet[i]],LL,RR);
	}ans[x]=rt[x]?ask(rt[x],a[x],LL,RR):0;
	change(rt[x],ans[x],b[x],LL,RR);
}
int main(){
	n=read();
	For(i,1,n)a[i]=read();
	For(i,1,n)b[i]=read();
	For(i,2,n){
		ll x=read(),y=read();
		insert(x,y),insert(y,x);
	}dfs(1,0);
	For(i,1,n)write(ans[i]),putchar(' ');
}