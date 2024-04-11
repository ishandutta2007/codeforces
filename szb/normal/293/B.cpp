#include <bits/stdc++.h>
#define ll int
#define inf 2000000001
#define maxn 11000
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
void writeln(ll x){ write(x);   puts("");   }
ll sum[100],bin[100],cost[20010],a[12][12],c[12][12],n,m,k;
const ll mod=1e9+7;
ll dfs(ll x,ll y){
//	printf("%d %d\n",x,y);
	if (y>m)	x++,y=1;
	if (x==n+1)	return 1;
	ll S=a[x-1][y]|a[x][y-1];
	if ((a[x][y]&S)||(cost[S]+max(n-x+1,m-y+1)>k))	return 0;
	ll ans=0,hh=0;	bool fl=0;
	if (a[x][y])	a[x][y]|=S,ans+=dfs(x,y+1),a[x][y]^=S;
	else	For(now,1,k)	if (!(bin[now]&S)){
		if (!sum[now]){
			sum[now]++;
			if (fl)	ans=(ans+hh)%mod;
			else	a[x][y]=bin[now]|S,ans=(ans+(hh=dfs(x,y+1))),a[x][y]=0,fl=1;
			sum[now]--;
		}else	a[x][y]=bin[now]|S,ans+=dfs(x,y+1),a[x][y]=0;
	}
	return ans;
}
int main(){
	n=read();	m=read();	k=read();
	bin[0]=1;	For(i,1,k)	bin[i]=bin[i-1]<<1;
	For(i,1,bin[k]*2)	cost[i]=cost[i-(i&-i)]+1;
	if (max(n,m)>k){	return puts("0"),0;	}
	For(i,1,n)	For(j,1,m){
		a[i][j]=read();	sum[a[i][j]]++;
		if (a[i][j])	a[i][j]=1<<a[i][j];
	}
	writeln(dfs(1,1));
}