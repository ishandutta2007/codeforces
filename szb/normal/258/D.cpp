#include<bits/stdc++.h>
#include<complex>
using namespace std; 
#define ll long long
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
#define pi acos(-1)
typedef complex<double> E;
ll read(){  ll x=0,f=1; char ch=getchar();  for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-')    f=-1;   for(;ch>='0'&&ch<='9';ch=getchar())   x=x*10+ch-'0';  return x*f; } 
void write(ll x){   if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  } 
void writeln(ll x){ write(x);   puts("");   }
const ll N=2010;
double big[N][N],ans;
ll n,Q,a[N];
int main(){
	n=read();	Q=read();
	For(i,1,n)	a[i]=read();
	For(i,1,n)	For(j,1,n)	if (i^j)	big[i][j]=a[i]>a[j];
	while(Q--){
		ll x=read(),y=read();	big[x][y]=big[y][x]=0.5;
		For(i,1,n)	if ((x^i)&&(y^i))
			big[x][i]=big[y][i]=(big[x][i]+big[y][i])/2,
			big[i][x]=big[i][y]=(big[i][x]+big[i][y])/2;
	}
	For(i,1,n)	For(j,i+1,n)
		ans+=big[i][j];
	printf("%lf",ans);
}