#include<queue>
#include<ctime>
#include<vector>
#include<cstdio>
#include<cstring>
#include<string>
#include<memory.h>
#include<map>
#include<ctime>
#include<algorithm>
#define ll int
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
#define F first
#define S i
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
const ll N=600100;
ll a[N];
vector<ll>g[N];	bool ff[N],vis[N];
ll head[N],vet[N],nxt[N],mn[N],L[N],las[N],tot,n,m,q[N],dis[N];
void insert(ll x,ll y){	nxt[++tot]=head[x];	head[x]=tot;	vet[tot]=y;}
int main(){
	n=read();	m=read();
	For(i,1,n){
		L[i]=read();
		For(j,1,L[i])
		g[i].push_back(read());
	}
	For(i,1,n-1){
		bool fl=0;
		For(j,0,min(L[i],L[i+1])-1)
		if (g[i][j]!=g[i+1][j]){
			fl=1;
			insert(g[i][j],g[i+1][j]);
			ff[g[i][j]]=1;
			ff[g[i+1][j]]=1;
			break;
		}
		if (!fl&&(L[i]>L[i+1]))	return puts("No"),0;
	}
	ll he=0,ta=0;
	For(i,1,m)	q[++ta]=i,vis[i]=1;
	while(he!=ta){
		ll x=q[he=he%m+1];	if (dis[x]>1){
			puts("No");
			return 0;
		}
		for(ll i=head[x];i;i=nxt[i])
		if (dis[vet[i]]<dis[x]+(x>vet[i])){
			dis[vet[i]]=dis[x]+(x>vet[i]);
			if (!vis[vet[i]])	q[ta=ta%m+1]=vet[i],vis[vet[i]]=1;
		}vis[x]=0;
	}
	For(i,1,m)	if (ff[i]&&!dis[i])	q[++q[0]]=i;
	puts("Yes");
	writeln(q[0]);
	For(i,1,q[0])	printf("%d ",q[i]);
}