#include<algorithm>
#include<memory.h>
#include<cmath>
#include<cstdio>
#define ll long long
#define maxn 4000010
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){  write(x);   puts("");   }
struct data{
	ll v,id;
}a[maxn];
ll v[maxn],fa[maxn],nxt[maxn],head[maxn],vet[maxn],size[maxn];
bool vis[maxn];
ll tot,n,ans,ans1,ans2;
bool cmp1(data a,data b){	return a.v<b.v;	}
bool cmp2(data a,data b){	return a.v>b.v;}
void insert(ll x,ll y){
	nxt[++tot]=head[x];	head[x]=tot;	vet[tot]=y;
}
ll find(ll x){	return x==fa[x]?x:fa[x]=find(fa[x]);	}
void work1(ll x){
	ll sum=0,sum2=0;	size[x]=1;
	for(ll i=head[x];i;i=nxt[i]){
		if (vis[vet[i]]){
			size[x]+=size[find(vet[i])];
			sum=(sum+size[fa[vet[i]]]);
			sum2=(sum2+size[fa[vet[i]]]*size[fa[vet[i]]]);
			fa[fa[vet[i]]]=x;
		}
	}
	ans=((sum*2+sum*sum-sum2)*v[x]+ans);
	vis[x]=1;
}
void work(){
	ans=0;
	memset(vis,0,sizeof vis);
	For(i,1,n)	fa[i]=i;
	For(i,1,n)	work1(a[i].id);
}
int main(){
	n=read();
	For(i,1,n)	v[i]=a[i].v=read(),a[i].id=i;
	For(i,1,n-1){
		ll x=read(),y=read();
		insert(x,y);	insert(y,x);
	}
	sort(a+1,a+n+1,cmp1);
	work();	ans1=ans;
	For(i,1,n)	a[i].v=a[i].v;
	sort(a+1,a+n+1,cmp2);
	work();	ans2=ans;
	writeln((ans1-ans2)/2);
}