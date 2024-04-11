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
const ll N=1e6+7;
char s[N];	bool vis[N];
ll n,len[N],tot,ans;
int main(){
	scanf("%s",s);	n=strlen(s);
	bool fl=1;
	For(i,0,n-1)	fl&=s[i%n+1]==s[i];
	if (fl)	return puts("1"),0;
	For(i,0,n-1)if (!vis[i]){
		vis[i]=1;	ll pp=1;
		ll x=i,y=i;	while(!vis[y%n+1]&&s[y%n+1]==s[i])		y=y%n+1,vis[y]=1,++pp;
					while(!vis[(x+n-1)%n]&&s[(x+n-1)%n]==s[i])	x=(x+n-1)%n,vis[x]=1,++pp;
		len[tot++]=pp;
	}
	fl=1;
	For(i,0,tot-1)	fl&=len[i]==len[i%tot+1];
	if (fl)	return writeln(tot/2),0;
	memset(vis,0,sizeof vis);
	For(i,0,tot-1)
	if (!vis[i])
	if (len[i]==1){
		vis[i]=1;	ll pp=1;
		ll x=i,y=i;	while(!vis[y%n+1]&&len[y%n+1]==1)		y=y%n+1,vis[y]=1,++pp;
					while(!vis[(x+n-1)%n]&&len[(x+n-1)%n]==1)	x=(x+n-1)%n,vis[x]=1,++pp;
		ans+=pp/2;
	}else	ans++;
	writeln(ans);
}
/*
0111001010101110001100000010011000100101110010001100111110101110001110101010111000010010011000000110


*/