#include<queue>
#include<ctime>
#include<vector>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<memory.h>
#include<map>
#include<ctime>
#include<algorithm>
#include<ctime>
#define ll int
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
#define ld double
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
const ll N=200010;
char s1[N],s2[N];	bool mark[N];
ll n,m,a[N],ans;
bool calc(ll x){
	memset(mark,0,sizeof mark);
	For(i,1,x)	mark[a[i]]=1;
	ll pos=0;
	For(i,1,n)	if (!mark[i]){
		if (s1[i]==s2[pos+1])	pos++;
		if (pos==m)	return 1;	
	}return 0;
}
int main(){
	scanf("%s%s",s1+1,s2+1);
	n=strlen(s1+1);	m=strlen(s2+1);
	For(i,1,n)	a[i]=read();
	ll l=0,r=n-m;
	while(l<=r){
		ll mid=(l+r)>>1;
		if (calc(mid))	l=mid+1,ans=mid;
		else	r=mid-1;
	}writeln(ans);
}