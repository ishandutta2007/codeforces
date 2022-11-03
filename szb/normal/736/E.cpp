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
#define ll long long
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
#define F first
#define S i
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
const ll N=3010;
struct data{	ll x,y;	}a[N];
ll win[N][N],n,m;
bool operator < (data a,data b){	return a.x>b.x;	}
char get(ll x){	return x==2?'W':(x==1?'D':'L');	}
void solve(ll x){
	sort(a+x,a+n+1);
	ll ned=a[x].x;
	FOr(i,n,x+1){
		if (ned>1)	ned-=2,win[a[x].y][a[i].y]=2,win[a[i].y][a[x].y]=0;
		else	if (ned)	a[i].x--,ned--,win[a[i].y][a[x].y]=win[a[x].y][a[i].y]=1;
		else	a[i].x-=2,win[a[x].y][a[i].y]=0,win[a[i].y][a[x].y]=2;
	}a[x].x=ned;
}
int main(){
	n=read();	m=read();
	For(i,1,m)	a[i].x=read(),a[i].y=i;
	ll tmp=0,mx=0;
	For(i,1,m){
		tmp+=a[i].x;	mx+=2*(n-i);
		if (tmp>mx)	return puts("no"),0;
	}
	For(i,m+1,n){
		mx+=2*(n-i);
		a[i].x=min(a[i-1].x,mx-tmp);
		tmp+=a[i].x;	a[i].y=i;
	}
	if (tmp!=mx)	return puts("no"),0;
	For(i,1,n)	solve(i);
	puts("yes");
	For(i,1,n){
		For(j,1,n)	putchar(i==j?'X':get(win[i][j]));
		puts("");
	}
}