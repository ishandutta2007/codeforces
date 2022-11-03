#include<cstdio>
#include<vector>
#include<cstring>
#include<memory.h>
#include<algorithm>
#include<ctime>
#define ll long long
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
using namespace std;
inline ll read(){ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);putchar(x%10+'0');  }
inline void writeln(ll x){ write(x);   puts("");   }
const ll N=200010,bas=37;
int las[N][27]; 
ll h[N][27],q[1000],vis[1000],g[1000],change[1000],bin[N],bin1[N],answ[N],n,m,inv_bas,L,R,child,all,all1;
char s[N],t[N];
inline bool cmp(ll a,ll b){	return las[L][a]<las[L][b];	}
inline ll get(ll typ,ll L,ll R){		return (h[R][typ]-h[L-1][typ]*bin[R-L+1]);		}
int main(){
//	freopen("technology.in","r",stdin);
//	freopen("technology.out","w",stdout);
	n=read();	m=read();
	bin[0]=bin1[0]=1;	For(i,1,n+1)	bin[i]=bin[i-1]*bas;
	gets(s+1);	gets(t+1);
	For(i,1,m){
		if (!vis[t[i]])	vis[t[i]]=++child,g[child-1]=t[i]-'a';
		all=all*bas+vis[t[i]];
	}
	For(i,1,n){
		ll now=s[i]-'a';
		h[i][now]=1LL*h[i-1][now]*bas+1;
		For(j,0,25)		h[i][j]=1LL*h[i-1][j]*bas;
		h[i][now]=(1LL*h[i-1][now]*bas+1);
	}
	For(i,0,25)	las[n+1][i]=n+1;
	FOr(i,n,1){
		memcpy(las[i],las[i+1],sizeof las[i+1]);
		ll now=s[i]-'a';
		las[i][now]=i;
	}
	For(i,1,n-m+1){
		For(j,0,25)	q[j]=j;	bool fl=0;
		L=i;	R=i+m-1;		sort(q,q+26,cmp);
		ll ans=0;
		fl=1;
		For(j,0,25)	change[j]=-1;
		For(j,0,25)	if (las[L][q[j]]<=R){
			ll to=g[j],now=q[j];
			if ((change[to]>=0&&change[to]!=now)||(change[now]>=0&&change[now]!=to))	fl=0;
			change[now]=to;	change[to]=now;
		}else	break;
		if (!fl)	continue;
		For(j,0,25)	ans=(ans+get(q[j],L,R)*(j+1));
		ans=ans;
		if (ans==all)	answ[++answ[0]]=i;
	}
	writeln(answ[0]);
	For(i,1,answ[0])	write(answ[i]),putchar(' ');
}
/*
5 5
ababa
bcbcb
*/