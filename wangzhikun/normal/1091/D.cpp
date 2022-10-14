#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
ll jc[1000010],jcinv[1000010],n,mod = 998244353,ans;
ll exgcd(ll a,ll b,ll &x,ll &y){
	if(b == 0){
		x = 1;y=0;return a;
	}
	ll d = exgcd(b, a%b, y, x);
	y-=a/b*x;
	return d;
}
ll inv(ll a){
	ll x,y;
	exgcd(a,mod,x,y);
	return (x+mod)%mod;
}
ll mul(ll a,ll b){
	return a*b%mod;
}
int main() {
	read(n);
	jc[0] = 1;
	jcinv[0] = jcinv[1] = 1;
	for(int i=1;i<=n;i++){
		jc[i] = jc[i-1]*i%mod;
	}
	for(int i=2;i<=n;i++){
		jcinv[i] = (jcinv[i-1]*inv(i))%mod;
	}
	ans = jc[n];
	for(int i=1;i<n;i++){
		ans = ans+mul(mul(jc[i],jc[n-i]-1),mul(mul(jc[n],jcinv[i]),jcinv[n-i]));
		ans = ans%mod;
	}
	cout<<(ans+mod)%mod<<endl;
	return 0;
}