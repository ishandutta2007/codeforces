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
const ll N=1010;
ll n,m,k,a[N][N],b[N][N],c[N][N],d[N][N],rt[N][N],e[N][N],RT[N][N],answ,ans,cur,x=k,y=k,rt1[N][N],RT1[N][N],lbc[N][N];
ll calc(){	ll ans=0;	For(i,1,n)	For(j,1,m)	ans+=a[i][j]*max(0LL,k-abs(i-k)-abs(j-k));	return ans;	}
void init(ll rt[][N],ll RT[][N]){
	For(i,1,n)	For(j,1,m){
		b[i][j]=b[i-1][j-1]+a[i][j];
		c[i][j]=c[i-1][j]+a[i][j];
		d[i][j]=d[i-1][j+1]+a[i][j];
		e[i][j]=e[i][j-1]+a[i][j];
	}
	For(i,k,m-k+1){
		ll ls=i-k+1,rs=i+k-1;
		For(j,1,n-k+1){
			if (j>k)rt[j][i]=rt[j-1][i]+e[j][i+k-1]-e[j][i-k]-b[j-1][i+k-1]-d[j-1][i-k+1]+a[j-k][i]+b[j-k-1][i-1]+d[j-k-1][i+1];
			else	rt[j][i]=rt[j-1][i]+e[j][i+j-1]-e[j][i-j];
		}
		FOr(j,n,k){
			if (j<n-k+1)RT[j][i]=RT[j+1][i]+e[j][i+k-1]-e[j][i-k]+b[j][i-k]+d[j][i+k]+a[j+k][i]-b[j+k][i]-d[j+k][i];
			else		RT[j][i]=RT[j+1][i]+e[j][i+(n-j+1)-1]-e[j][i-(n-j+1)];
		}
	}
}
int main(){
//	freopen("s.in","r",stdin);
	n=read();	m=read();	k=read();	x=y=k;
	For(i,1,n)	For(j,1,m)	a[i][j]=read();
	init(rt,RT);
	For(i,1,n)	For(j,1,m)	lbc[j][i]=a[i][j];
	swap(n,m);
	For(i,1,n)	For(j,1,m)	a[i][j]=lbc[i][j];
	init(rt1,RT1);
	For(i,1,n)	For(j,1,m)	lbc[j][i]=a[i][j];
	swap(n,m);
	For(i,1,n)	For(j,1,m)	a[i][j]=lbc[i][j];
	For(j,k,m-k+1)	For(i,k,n-k+1){
		if (i==k&&j==k)	ans=calc(),cur=ans,answ=max(answ,ans);
		else	if (i==k)	ans=cur+RT1[j][i]-rt1[j-1][i],cur=ans,answ<ans?(x=i,y=j,0):0,answ=max(answ,ans);
		else	ans=ans+RT[i][j]-rt[i-1][j],answ<ans?(x=i,y=j,0):0,answ=max(answ,ans);
//		writeln(ans);
	}printf("%I64d %I64d\n",x,y);
}