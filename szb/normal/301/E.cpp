#include<vector>
#include<cstdio> 
#include<cstring> 
#include<map>
#include<cmath> 
#include<algorithm>
#include<bitset>
#include<ctime> 
using namespace std; 
#define ll long long
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
ll read(){  ll x=0,f=1; char ch=getchar();  for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-')    f=-1;   for(;ch>='0'&&ch<='9';ch=getchar())   x=x*10+ch-'0';  return x*f; } 
void write(ll x){   if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  } 
void writeln(ll x){ write(x);   puts("");   }
const ll N=110,mod=1e9+7;
ll n,m,K,c[N][N],f[55][55][55][N];
void add(ll &x,ll y){	x=(x+y)%mod;	}
int main(){
	n=read()>>1;	m=read();	K=read();
	For(i,0,100){c[i][0]=c[i][i]=1;For(j,1,i-1)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;}ll ans=0;
	For(i,1,n)f[i][1][i][1]=1;
	For(i,1,n)For(j,1,min(m-1,n))For(k,1,i)For(l,1,K)if (f[i][j][k][l]){
		add(ans,f[i][j][k][l]*(m-j));
		For(now,1,n-i)	if (l*c[now+k-1][k-1]<=K)	add(f[i+now][j+1][now][l*c[now+k-1][k-1]],f[i][j][k][l]);
	}writeln(ans);
}