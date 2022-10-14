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

int mod = 1e9+7;
inline int mul(int x,int y){return 1ll*x*y%mod;}
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int sq(int x){return 1ll*x*x%mod;}
int pow(int a,int b){return b == 0 ? 1 : ( b&1 ? mul(a,sq(pow(a,b/2))) : sq(pow(a,b/2)));}

int p,k,vis[1000010];

int main() {
	read(p);read(k);
	if(k == 0){
		cout<<pow(p,p-1)<<endl;
		return 0;
	}
	if(k == 1){
		cout<<pow(p,p)<<endl;
		return 0;
	}
	int ans = 1;
	for(int i=1;i<p;i++){
		if(vis[i])continue;
		int cp = i;
		while(!vis[cp]){
			vis[cp] = 1;
			cp = 1ll*cp*k%p;
		}
		ans = mul(ans,p);
	}
	cout<<ans<<endl;
	return 0;
}