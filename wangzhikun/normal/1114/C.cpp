#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define debug(x) //cerr<<#x<<'='<<x<<endl
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
ll n,b;
ll calc(ll n,ll a){
	if(a == 1)return 2e18;
	debug(a);
	ll sum = 0;
	ll c = a;
	while(c<=n){
		sum+=n/c;
		if((double)c*a>2e18)break;
		c = c*a;
	}
	debug(sum);
	return sum;
}
int main() {
	read(n);read(b);
	ll ans = 2e18;
	for(ll i=2;i*i<=b;i++){
		if(b%i == 0){
			ll cc = 0;
			while(b%i == 0)b/=i,cc++;
			ans = min(ans,calc(n,i)/cc);
			
		}
	}
	ans = min(ans,calc(n,b));
	cout<<ans<<endl;
	return 0;
}