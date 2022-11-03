#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<ctime>
#include<map>
using namespace std;
#define ll long long
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
ll read(){  ll x=0,f=0; char ch=getchar();  while(ch<'0'||ch>'9'){ if(ch=='-') f=1; ch=getchar(); }   while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0', ch=getchar(); return f?-x:x;}
void write(ll x){   if (x<0) x=-x,putchar('-');  if (x>=10)   write(x/10);    putchar(x%10+'0');}
void writeln(ll x)  {   write(x);   puts("");   }
const ll mod=1e9+7,N=200010;
ll n,head[N],nxt[N],vet[N],fa[N],bin[N],p[N],q[N],sz[N],x[N],y[N],tot,point,sum,cnt,ans;
bool vis[N];
void insert(ll x,ll y){	nxt[++tot]=head[x];	head[x]=tot;	vet[tot]=y;	}
void dfs(ll x){
	if (x<=n)	point+=sz[x];	sum++;
	vis[x]=1;	++cnt;
	for(ll i=head[x];i;i=nxt[i])
	if (!vis[vet[i]])	dfs(vet[i]);
}
int main(){
	bin[0]=1;	For(i,1,200000)	bin[i]=bin[i-1]*2%mod;
	n=read();	ans=1;
	For(i,1,n){
		x[i]=read(),y[i]=read();
		p[i]=x[i];	q[i]=y[i];
	}
	sort(p+1,p+n+1);	sort(q+1,q+n+1);
	For(i,1,n)	x[i]=lower_bound(p+1,p+n+1,x[i])-p,sz[x[i]]++,
				y[i]=lower_bound(q+1,q+n+1,y[i])-q,sz[y[i]+n]++;
	For(i,1,n)	insert(x[i],y[i]+n),insert(y[i]+n,x[i]);
	For(i,1,n)	if (!vis[i]){
		point=0;	sum=0;
		dfs(i);
		if (point+1==sum)	ans=ans*(bin[sum]-1)%mod;
		else	ans=ans*bin[sum]%mod;
	}
	writeln((ans%mod+mod)%mod);
}