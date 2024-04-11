#include <set>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <numeric>
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

const int N = 1000010;
int n,k,phi[N];

int main() {
	read(n);read(k);
	for(int i=1;i<=n;i++)phi[i] = i;
	for(int i=2;i<=n;i++){
		if(phi[i] == i){
			for(int j = i;j<=n;j+=i){
				phi[j] = (phi[j]/i)*(i-1);
			}
		}
	}
	if(k == 1){
		cout<<3<<endl;
		return 0;
	}
	sort(phi+3,phi+n+1);
	ll ans = 1;
	for(int i=2;i<=3+k-1;i++){
		ans+=phi[i];
	}
	cout<<ans<<endl;
	return 0;
}