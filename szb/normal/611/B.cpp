#include<iostream>
#include<cmath>
#include<queue>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#define ll long long
#define N 100005
#define inf (1ll<<62)
#define rep(i,j,k) for (ll i=j;i<=k;++i)
#define per(i,j,k) for (ll i=j;i>=k;--i)
using namespace std;
inline ll read(){
	char ch=getchar(); ll x=0,f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}
ll x,y,cnt,ans,a[N];
int main(){
	x=read(); y=read();
	rep(i,1,60){
		ll sum=(1ll<<i)-1;
		rep(j,0,i-2) a[++cnt]=sum-(1ll<<j);
	}
	rep(i,1,cnt)  if (a[i]>=x&&a[i]<=y) ++ans;
	printf("%lld",ans);
}