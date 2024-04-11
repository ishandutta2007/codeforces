#include <set>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

ll n;
ll gcd(ll a,ll b){
	if(b == 0)return a;
	return gcd(b,a%b);
}
int main() {
	cin>>n;
	ll ans = 0;
	for(ll i=1;i*i<=n;i++){
		if(n%i == 0){
			if(i!=1) ans = gcd(ans,i);
			ans = gcd(ans,n/i);
		}
	}
	cout<<ans<<endl;
	return 0;
}