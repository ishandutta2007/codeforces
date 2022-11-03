#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<ctime>
#include<map>
using namespace std;
#define ll int
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
ll read(){  ll x=0,f=0; char ch=getchar();  while(ch<'0'||ch>'9'){ if(ch=='-') f=1; ch=getchar(); }   while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0', ch=getchar(); return f?-x:x;}
void write(ll x){   if (x<0) x=-x,putchar('-');  if (x>=10)   write(x/10);    putchar(x%10+'0');}
void writeln(ll x)  {   write(x);   puts("");   }
const ll mod=1e9+7,N=5050;
char s[N];
ll sum[N][N],f[N][N],ans,n;
int lcp[N][N];
bool cmp(ll S,ll T,ll len){	return (lcp[S][T]<len)&&(s[S+lcp[S][T]]<s[T+lcp[S][T]]);	}
void add(ll &x,ll y){	x=(x+y)%mod;	}
int main(){
//	freopen("applese.in","r",stdin);
	n=read();
	if (n==1)	return puts("1"),0;
	scanf("%s",s+1);
	FOr(i,n,1)	FOr(j,n,1)	lcp[i][j]=s[i]==s[j]?(lcp[i+1][j+1]+1):0;
	For(i,1,n)	f[i][i]=1;
	For(i,1,n){
		For(j,1,n)	f[i][j]=(sum[i][j]+f[i][j])%mod,sum[i+1][j+1]=(sum[i+1][j+1]+sum[i][j])%mod;
		if (i==n){
			For(j,1,n)	ans=(ans+f[n][j])%mod;
			break;
		}
		if (s[i+1]!='0'){
			For(j,1,i)if ((i+j<=n)){
				if ((s[i-j+1]!='0')&&cmp(i-j+1,i+1,j))	add(sum[i+j][j],f[i][j]);
				else	if (i+j<n)	add(sum[i+j+1][j+1],f[i][j]);
			}
		}
	}
	writeln(ans);
}
/*
i----(j-1)	
f[i]
*/