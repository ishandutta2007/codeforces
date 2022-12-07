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
const int N=1000005;
int fl[N],pri[N],ans;
void init(){
	For(i,2,N-1) if (!fl[i])
		For(j,2,(N-1)/i) fl[i*j]=1;
	For(i,2,N-1) if (!fl[i]) pri[++*pri]=i;
}
bool isprime(ll x){
	if (x<=1) return 0;
	for (int i=1;1ll*pri[i]*pri[i]<=x;i++)
		if (x%pri[i]==0) return 0;
	return x;
}
int Sqrt(ll x){
	int v=floor(sqrt(x)-0.1);
	for (;1ll*v*v<x;++v);
	return 1ll*v*v==x?v:1;
}
void dfs(ll x,int p){
	//cout<<x<<' '<<p<<endl;
	if (x==1) return ++ans,void(0);
	if (x<=2||pri[p]+1>x) return;
	if (isprime(x-1)) ++ans;
	for (int i=p;1ll*pri[i]*pri[i]<=x;++i)
		for (ll j=pri[i];j<=x;j*=pri[i])
			if (x%(j+1)==0) dfs(x/(j+1),i+1);
}
int main(){
	ll x;
	scanf("%lld",&x);
	init();
	dfs(x,1);
	printf("%d\n",ans);
}