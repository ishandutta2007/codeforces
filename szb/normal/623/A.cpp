#include<queue>
#include<ctime>
#include<vector>
#include<cstdio>
#include<cstring>
#include<memory.h>
#include<map>
#include<algorithm>
#define ll long long
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
#define F first
#define S second
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
const ll mod=1e9+7;
map<ll,ll>value;
ll mp[510][510],v[510],M[10][10],n,m,cnt;
char s[510];
bool pd(char a,char b){
	if (a>b)	swap(a,b);
	if (a==b)	return 1;
	if (a=='a'&&b=='b')	return 1;
	if (a=='b'&&b=='c')	return 1;
	return 0;
}
int main(){
	n=read();	m=read();
	For(i,1,n)	mp[i][i]=1;
	For(i,1,m){
		ll x=read(),y=read();
		mp[x][y]=mp[y][x]=1;
	}
	For(i,1,n)	For(j,1,n)	if (!mp[i][j]){
		For(x,1,n)	s[x]='b';
		s[i]='a';	s[j]='c';
		For(x,1,n)	if (!mp[i][x])	s[x]='c';
		For(x,1,n)	if (!mp[j][x])	s[x]='a';
		For(x,1,n)	For(y,1,n)
		if (pd(s[x],s[y])!=mp[x][y])	return puts("No"),0;
		puts("Yes");
		For(x,1,n)	putchar(s[x]);
		return 0;
	}
	puts("Yes");
	For(i,1,n)	putchar('a');
}