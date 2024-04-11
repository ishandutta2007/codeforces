#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<ctime>
#include<map>
using namespace std;
#define ll long long
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
ll read(){  ll x=0,f=0; char ch=getchar();  while(ch<'0'||ch>'9'){ if(ch=='-') f=1; ch=getchar(); }   while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0', ch=getchar(); return f?-x:x;}
void write(ll x){   if (x<0) x=-x,putchar('-');  if (x>=10)   write(x/10);    putchar(x%10+'0');}
void writeln(ll x)  {   write(x);   puts("");   }
ll a[510][510],h,w,Q,left[510][510],up[510][510];
char s[510];
ll le1(ll x1,ll y1,ll x2,ll y2){	return left[x2][y2]+left[x1-1][y1-1]-left[x1-1][y2]-left[x2][y1-1];	}
ll up1(ll x1,ll y1,ll x2,ll y2){	return up[x2][y2]+up[x1-1][y1-1]-up[x1-1][y2]-up[x2][y1-1];	}
int main(){
	h=read();	w=read();
	For(i,1,h){
		scanf("%s",s+1);
		For(j,1,w)	a[i][j]=s[j]=='.'?1:0;
	}	Q=read();
	For(i,1,h)	For(j,2,w)	left[i][j]=(a[i][j]&&a[i][j-1])+left[i-1][j]+left[i][j-1]-left[i-1][j-1];
	For(i,2,h)	For(j,1,w)	up[i][j]=(a[i][j]&&a[i-1][j])+up[i-1][j]+up[i][j-1]-up[i-1][j-1];
	while(Q--){
		ll x1=read(),y1=read(),x2=read(),y2=read(),ans=0;
		if (y1<y2)	ans+=le1(x1,y1+1,x2,y2);
		if (x1<x2)	ans+=up1(x1+1,y1,x2,y2);
		writeln(ans);
	}
}