#include<stdio.h>
#include<string.h>
#include<string>
#include<math.h>
#include<iostream>
#include<bitset>
#include<map>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<limits.h>
#include<stdlib.h>
#include<time.h>
#define ll long long
#define pa pair<ll,int>
#define For(i,x,y) for(int i=x;i<=y;i++)
#define FOr(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
inline int read(){int x=0,f=0;char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;return f?-x:x;}
inline void write(ll x){if(x<10) putchar(x+48);else write(x/10),putchar(x%10+48);}
inline void writeln(ll x){if(x<0) x=-x,putchar('-');write(x);putchar('\n');}
const ll maxn=100010;
ll mp[maxn],f[maxn],g[maxn],a[maxn],_l,_r,ans,n,k,l,r;
void solve(ll l,ll r,ll L,ll R){
	if (l>r)	return;
	ll mid=(l+r)>>1,p=min(R,mid),mx=1LL<<60;
	while(_r<mid)	ans+=mp[a[++_r]]++;
	while(_l>p+1)	ans+=mp[a[--_l]]++;
	while(_r>mid)	ans-=--mp[a[_r--]];
	while(_l<p+1)	ans-=--mp[a[_l++]];
	FOr(i,p,L){
		ll x=a[i];
		ans+=mp[a[--_l]]++;
		if (ans+f[i-1]<mx)	mx=ans+f[i-1],p=i;
	}g[mid]=mx;
	solve(l,mid-1,L,p);
	solve(mid+1,r,p,R);
}
int main(){
	memset(f,60,sizeof f);	f[0]=0;
	n=read();	k=read();
	For(i,1,n)	a[i]=read();
	For(i,1,k){
		_l=1;	_r=ans=0;
		memset(mp,0,sizeof mp);
		solve(i,n,i,n);
		memcpy(f,g,sizeof g);
	}writeln(f[n]);
}