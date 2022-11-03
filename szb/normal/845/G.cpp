#include<algorithm>
#include<memory.h>
#include<cstdio>
#include<cmath>
#define ll long long
#define maxn 200010
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ write(x);    puts("");   }
ll bin[100],v[maxn],next[maxn],head[maxn],vet[maxn],val[maxn],dis[maxn],szb,tot,cnt,n,m;
bool vis[maxn];
void insert(ll x,ll y,ll w){
    next[++tot]=head[x];    head[x]=tot;    vet[tot]=y; val[tot]=w;
}
void dfs(ll x){
    vis[x]=1;
    for(ll i=head[x];i;i=next[i])
    if (!vis[vet[i]]){
        dis[vet[i]]=dis[x]^val[i];
        dfs(vet[i]);
    }else   v[++cnt]=dis[x]^dis[vet[i]]^val[i];
}
void gauss(){
    FOr(i,60,0){
        ll j=szb+1;
        while(j<=cnt&&!(v[j]&bin[i]))    ++j;
        if (j==cnt+1)   continue;
        ++szb;
        swap(v[szb],v[j]);
        For(k,1,cnt)    if (k!=szb&&(v[k]&bin[i]))  v[k]^=v[szb];
    }
}
int main(){
    bin[0]=1;   For(i,1,60) bin[i]=bin[i-1]<<1;
    n=read();   m=read();
    For(i,1,m){
        ll x=read(),y=read(),w=read();
        insert(x,y,w);  insert(y,x,w);
    }
    dfs(1); gauss();
    ll ans=dis[n];
    For(i,1,szb)    ans=min(ans,ans^v[i]);
    writeln(ans);
}