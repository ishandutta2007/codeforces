#include<ctime>
#include<algorithm>
#include<cstdio>
#include<set>
#include<memory.h>
#include<queue>
#include<cmath>
using namespace std;
#define ll int
#define maxn 600010
#define M 12000000
#define For(i,x,y)  for(int i=x;i<=y;++i)
#define FOr(i,x,y)  for(int i=x;i>=y;--i)
inline ll read(){  ll x=0,f=0; char ch=getchar();  while(ch<'0'||ch>'9'){ if(ch=='-') f=1; ch=getchar(); }   while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0', ch=getchar(); return f?-x:x;}
void write(ll x){   if (x<0) x=-x,putchar('-');  if (x>=10)   write(x/10);    putchar(x%10+'0');}
inline void writeln(ll x)  {   write(x);   puts("");   }
ll tot=1,head[maxn],nxt[maxn],vet[maxn],dig[maxn],d[maxn],ans[maxn],n,m,vis[maxn],rt,sum;
void insert(ll x,ll y){	nxt[++tot]=head[x];	head[x]=tot;	vet[tot]=y;	}
void dfs(ll x,ll in){
	vis[x]=1;	ll child=0;
	for(ll i=head[x];i;i=nxt[i])
	if (!vis[vet[i]])	dfs(vet[i],i>>1),child^=dig[vet[i]];
	if (child==d[x]||d[x]==-1)	return;
	dig[x]=1;
	if (in)	ans[++ans[0]]=in;
}
int main(){
	n=read();	m=read();
	For(i,1,n)	if ((d[i]=read())==-1)	rt=i;	else	sum^=d[i];
	For(i,1,m){
		ll x=read(),y=read();
		insert(x,y);	insert(y,x);
	}
	if (!rt&&sum)	return puts("-1"),0;
	dfs(max(rt,1),0);
	sort(ans+1,ans+ans[0]+1);
	writeln(ans[0]);
	For(i,1,ans[0])	printf("%d ",ans[i]);
}