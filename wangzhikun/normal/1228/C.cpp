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

int x;
ll n;
int mod = 1e9+7;
inline int mul(int x,int y){return 1ll*x*y%mod;}
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int sq(int x){return 1ll*x*x%mod;}
int qpow(int a,int b){return b == 0 ? 1 : ( b&1 ? mul(a,sq(qpow(a,b/2))) : sq(qpow(a,b/2)));}


int main() {
	read(x);read(n);
	int ans = 1;
	for(int i=2;i*i<=x;i++){
		if(x%i == 0){
			while(x%i == 0){
				x/=i;
			}
			ll cc = i;ll cv = 0;
			while(cc<=n){
				cv+=n/cc;
				if(1.0*cc*i>2*n)break;
				cc*=i;
			}
			cv%=(mod-1);
			ans = mul(ans,qpow(i,cv));
		}
	}
	if(x!=1){
		ll cc = x;ll cv = 0;
		while(cc<=n){
			cv+=n/cc;
			if(1.0*cc*x>2*n)break;
			cc*=x;
		}
		cv%=(mod-1);
		ans = mul(ans,qpow(x,cv));
	}
	cout<<ans<<endl;
	return 0;
}