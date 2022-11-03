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
map<ll,ll>mp;
ll fa[maxn],n,A,B,a[maxn];
ll find(ll x){	return x==fa[x]?x:fa[x]=find(fa[x]);	}
int main(){
	while(scanf("%d%d%d",&n,&A,&B)!=EOF){
		mp.clear();
		For(i,1,n)	mp[a[i]=read()]=i;
		For(i,1,n+2)	fa[i]=i;
		For(i,1,n){
			ll x=find(i);
			if (mp[A-a[i]])	fa[x]=find(mp[A-a[i]]);
			else	fa[x]=find(n+2);
			x=find(i);
			if (mp[B-a[i]])	fa[x]=find(mp[B-a[i]]);
			else	fa[x]=find(n+1);
		}
		if (find(n+1)==find(n+2))	puts("NO");
		else{
			puts("YES");
			For(i,1,n-1)	printf("%d ",find(i)==find(n+2));
			writeln(find(n)==find(n+2));
		}
	}
}