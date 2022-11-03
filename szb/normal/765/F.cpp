#include<bits/stdc++.h>
using namespace std; 
#define ll int
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
#define pi acos(-1)
#define mk make_pair<ll,ll>
#define pa pair<ll,ll>
#define fi first
#define se second
#define lf else if
#define max(x,y)    ((x)<(y)?(y):(x))
#define min(x,y)    ((x)<(y)?(x):(y))
#define mul(x,y)    x=x*(y)%mod
#define Add(x,y)    x=(x+(y))%mod
#define EXIT(x) return writeln(x),0;
typedef complex<double> E;
namespace SHENZHEBEI{
#ifdef LOCAL
    struct _{_(){freopen("cf.in","r",stdin);}}_;
#endif 
#define NEG 0
    const int L=2333333;
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
    inline ll readstr(char *s){ char ch=gc();   int cur=0;  for(;isspace(ch);ch=gc());      for(;!isspace(ch);ch=gc())  s[cur++]=ch;    s[cur]='\0';    return cur; }
    inline void writeln(ll x){  write(x);   puts("");   }
}using namespace SHENZHEBEI;
const ll N=1e5+7,inf=1e9+7,bx=200;
pa a[N];
ll f[N][max(N/bx,bx)+10],Ls[N],Rs[N],n,cnt,Q,pos[N],pre[N],suc[N],h[max(N/bx,bx)+10][max(N/bx,bx)+10],q1[N],q2[N],sz[N],b[N];
void work(ll x,ll y){//xy f ->, g->
    ll pos1=Ls[x];
    For(pos2,Ls[y],Rs[y]){
        while(pos1<Rs[x]&&abs(a[pos1].fi-a[pos2].fi)>abs(a[pos1+1].fi-a[pos2].fi))++pos1;
        f[a[pos2].se][x]=abs(a[pos1].fi-a[pos2].fi);
    }
    ll pos2=Ls[y];
    For(pos1,Ls[x],Rs[x]){
        while(pos2<Rs[y]&&abs(a[pos1].fi-a[pos2].fi)>abs(a[pos1].fi-a[pos2+1].fi))++pos2;
        f[a[pos1].se][y]=abs(a[pos1].fi-a[pos2].fi);
    }
    FOr(i,Rs[x]-1,Ls[x])    f[i][y]=min(f[i][y],f[i+1][y]);
    For(i,Ls[y]+1,Rs[y])    f[i][x]=min(f[i][x],f[i-1][x]);
    h[x][y]=f[Ls[x]][y];
}
void WORK(ll x){
    h[x][x]=inf;
    For(i,Ls[x],Rs[x]){
        pre[i]=suc[i]=inf;
        For(j,Ls[x],i-1)pre[i]=min(pre[i],abs(b[i]-b[j]));
        For(j,i+1,Rs[x])suc[i]=min(suc[i],abs(b[i]-b[j]));
        h[x][x]=min(min(h[x][x],pre[i]),suc[i]);
    }
    For(i,Ls[x]+1,Rs[x])    pre[i]=min(pre[i],pre[i-1]);
    FOr(i,Rs[x]-1,Ls[x])    suc[i]=min(suc[i],suc[i+1]);
}
ll Query(ll x,ll y){
    ll p=pos[x],t1=0,ans=inf;
    For(i,Ls[p],Rs[p])  if (a[i].se>=x&&a[i].se<=y)   q1[++t1]=a[i].fi;
    rep(i,1,t1) ans=min(ans,q1[i+1]-q1[i]);
    return ans;
}
ll calc(ll x,ll y){
    ll l=pos[x],r=pos[y],t1=0,t2=0;
    if (l==r)   return Query(x,y);
    ll ans=min(suc[x],pre[y]);
    For(i,l+1,r-1)  ans=min(ans,min(f[x][i],f[y][i]));
    if (l+1<=r-1)    ans=min(ans,h[l+1][r-1]);
    For(i,Ls[l],Rs[l])if (a[i].se>=x)    q1[++t1]=a[i].fi;
    For(i,Ls[r],Rs[r])if (a[i].se<=y)    q2[++t2]=a[i].fi;
    ll pos1=1;
    For(pos2,1,t2){
        while(pos1<t1&&abs(q1[pos1]-q2[pos2])>abs(q1[pos1+1]-q2[pos2]))++pos1;
        ans=min(ans,abs(q1[pos1]-q2[pos2]));
    }return ans;
}
int main(){
//  freopen("cf.out","w",stdout);
    n=read();
    For(i,1,n)a[i]=mk(b[i]=read(),i);cnt=(n-1)/bx+1;
    For(i,1,cnt)Ls[i]=(i-1)*bx+1,Rs[i]=min(i*bx,n),sz[i]=Rs[i]-Ls[i]+1,sort(a+Ls[i],a+Rs[i]+1);
    For(i,1,n)pos[i]=(i-1)/bx+1;
    For(i,1,cnt)For(j,i+1,cnt)work(i,j);
    For(i,1,cnt)WORK(i);
    For(len,1,cnt)For(i,1,cnt-len)h[i][i+len]=min(h[i][i+len],min(h[i][i+len-1],h[i+1][i+len]));
    Q=read();
    while(Q--){ ll l=read(),r=read();   writeln(calc(l,r)); }
}