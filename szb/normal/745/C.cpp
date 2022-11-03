#include<algorithm> 
#include<cmath> 
#include<bitset> 
#include<set>
#include<cstdio> 
#include<map> 
#define ll int
#define maxn 400010 
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
using namespace std; 
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; } 
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  } 
inline void writeln(ll x){  write(x);   puts("");   }
ll q[maxn],c[maxn],fa[maxn],vis[maxn],size[maxn],n,m,k,mx,tot,ans;
ll find(ll x){	return x==fa[x]?x:fa[x]=find(fa[x]);}
int main(){
	while(scanf("%d%d%d",&n,&m,&k)!=EOF){
		For(i,1,n)	vis[i]=0,fa[i]=i,size[i]=1;	mx=tot=ans=0;
		For(i,1,k)	c[i]=read();
		For(i,1,m){
			ll x=find(read()),y=find(read());
			if (x!=y){
				fa[y]=x;
				size[x]+=size[y];
			}
		}
		For(i,1,k)	vis[find(c[i])]=1;
		For(i,1,n)	if (find(i)==i){
			vis[i]?mx=max(mx,size[i]):q[++tot]=size[i];
			ans+=size[i]*(size[i]-1)>>1;
		}
		q[++tot]=mx;
		For(i,1,tot-1)	For(j,i+1,tot)	ans+=q[i]*q[j];
		writeln(ans-m);
	}
}