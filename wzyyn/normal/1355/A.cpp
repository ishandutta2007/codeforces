#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;

int mindig(ll x){
	int v=9;
	for (;x;v=min(1ll*v,x%10),x/=10);
	return v;
}
int maxdig(ll x){
	int v=0;
	for (;x;v=max(1ll*v,x%10),x/=10);
	return v;
}
void solve(){
	ll x,k;
	scanf("%lld%lld",&x,&k);
	for (;mindig(x)!=0&&k>1;k--,x+=mindig(x)*maxdig(x));
	printf("%lld\n",x);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}