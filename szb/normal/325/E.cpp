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
const ll N=100010;
ll vis[N],n;
void dfs(ll x){
	vis[x]=1;
	if (x==1)	printf("0 1");
	else	dfs(vis[(x+n)/2]?x/2:(x+n)/2),printf(" %d",x);
}
int main(){
	n=read();
	if (n&1)	puts("-1");
	else	dfs(0);
}
/*
0 0 1
1 2 3
2 4 5
3 6 7
4 0 1
5 2 3
6 4 5
7 6 7
*/