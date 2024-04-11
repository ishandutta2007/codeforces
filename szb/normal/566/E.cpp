
#include<bits/stdc++.h>
using namespace std;
#define ll int
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
	void rewrite(ll x,ll y){write(x),putchar(' ');writeln(y);}
}using namespace SHENZHEBEI;
const ll N=2010;
ll fa[N],n,cnt,ok[N],rt1,rt2,Cnt;
vector<pa>edge[N];
bitset<1010>a[N];
ll find(ll x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void same(ll x,ll y){fa[find(x)]=find(y);fa[find(x+n)]=find(y+n);}
void unsame(ll x,ll y){fa[find(x)]=find(y+n);fa[find(x+n)]=find(y);}
int main(){
	n=read();
	if (n==1)return 0;
	if (n==2)return puts("1 2"),0;
	For(i,1,n){
		ll sum=read();
		For(j,1,sum)a[read()][i]=1;
	}
	For(i,1,2*n)fa[i]=i;
	For(i,1,n)For(j,i+1,n){
		ll sum=(a[i]&a[j]).count();
		if (sum==1)	same(i,j),++Cnt;
		lf (sum==2)	unsame(i,j),++cnt,ok[i]=ok[j]=1;
		else	edge[sum].push_back(mk(i,j));
	}
	if (!cnt){
		For(i,1,n-1)rewrite(1,i+1);
	}else{
		FOr(sum,n,1)rep(i,0,edge[sum].size()){
			pa to=edge[sum][i];
			ll x=to.fi,y=to.se;
			if (find(x)!=find(y)){
				rewrite(x,y);
				unsame(x,y);
			}
		}
	}
}