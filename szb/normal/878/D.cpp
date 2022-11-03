#include<set>
#include<cstdio> 
#include<cstring> 
#include<cmath> 
#include<windows.h>
#include<algorithm> 
#include<ctime> 
#include<bits/stdc++.h>
using namespace std; 
#define ll int
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
#define rep(i,x,y)	for(ll i=x;i<y;++i)
ll read(){  ll x=0,f=1; char ch=getchar();  for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-')    f=-1;   for(;ch>='0'&&ch<='9';ch=getchar())   x=x*10+ch-'0';  return x*f; } 
void write(ll x){   if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  } 
void writeln(ll x){ write(x);   puts("");   }
ll a[13][100010];
bitset<4096>f[100010];
ll n,k,Q,all,tot;
int main(){
	n=read();	k=read();	Q=read();
	For(i,1,k)	For(j,1,n)	a[i][j]=read();
	all=(1<<k)-1;
	For(i,1,k)	For(j,0,all)	if (j>>i-1&1)	f[i].set(j);	tot=k;
	while(Q--){
		ll opt=read(),x=read(),y=read();
		if (opt==1)	f[++tot]=f[x]|f[y];
		if (opt==2)	f[++tot]=f[x]&f[y];
		if (opt==3){
			ll ans=0;
			For(i,1,k){
				ll ss=0;
				For(j,1,k)	ss|=(a[j][y]>=a[i][y])<<j-1;
				if (f[x][ss])	ans=max(ans,a[i][y]);
			}
			writeln(ans);
		}
	}
}
/*
2 2 4 
1 2 
2 1 
1 1 2 
2 1 2 
3 3 1 
3 4 2
*/