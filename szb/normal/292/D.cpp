#include<algorithm> 
#include<cmath> 
#include<bitset> 
#include<set>
#include<cstdio> 
#include<map> 
#define ll int
#define maxn 20010 
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
using namespace std; 
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; } 
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  } 
inline void writeln(ll x){  write(x);   puts("");   }
ll fa[maxn][510],f[maxn][510],F[maxn],ans,L[maxn],R[maxn],n,m;
ll find(ll fa[],ll x){	return x==fa[x]?x:fa[x]=find(fa,fa[x]);}
void init(){
	For(i,1,n)	fa[0][i]=f[m+1][i]=i;
	For(i,1,m){
		For(j,1,n)	fa[i][j]=fa[i-1][j];
		ll x=find(fa[i],fa[i][L[i]]),y=find(fa[i],fa[i][R[i]]);
		fa[i][x]=fa[i][y];
		For(j,1,n)	fa[i][j]=find(fa[i],fa[i][j]);
	}
	FOr(i,m,1){
		For(j,1,n)	f[i][j]=f[i+1][j];
		ll x=find(f[i],f[i][L[i]]),y=find(f[i],f[i][R[i]]);
		f[i][x]=f[i][y];
		For(j,1,n)	f[i][j]=find(f[i],f[i][j]);
	}
}
void solve(ll x,ll y){
	ll ans=0;
	For(i,1,n)	F[i]=fa[x][i];
	For(i,1,n)
		F[find(F,i)]=find(F,f[y][i]);
	For(i,1,n)	ans+=i==find(F,i);
	writeln(ans);
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		For(i,1,m)	L[i]=read(),R[i]=read();
		init();
		ll Q=read();
		while(Q--){
			ll l=read(),r=read();
			solve(l-1,r+1);
		}
	}
}
/*
6 5
1 2
5 4
2 3
3 1
3 6
6
1 3
2 5
1 5
5 5
2 4
3 3
*/