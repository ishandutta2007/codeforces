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

int mod = 1000000007;

inline int mul(int x,int y){return 1ll*x*y%mod;}
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int sq(int x){return 1ll*x*x%mod;}
int pow(int a,int b){return b <= 0 ? 1 : ( b&1 ? mul(a,sq(pow(a,b/2))) : sq(pow(a,b/2)));}

int n,m,a,b;
const int N = 1000010;
int fac[N],invfac[N],pown[N],powm[N];

int C(int n,int m){
	return 1ll*fac[n]*(1ll*invfac[m]*invfac[n-m]%mod)%mod;
}
int F(int n,int m){
	if(n == m)return 1;
	return 1ll*pown[n-m-1]*m%mod;
}
int main() {
	cin>>n>>m>>a>>b;
	fac[0] = pown[0] = powm[0] = 1;
	for(int i=1;i<N;i++){
		fac[i] = 1ll*fac[i-1]*i%mod;
		pown[i] = 1ll*pown[i-1]*n%mod;
		powm[i] = 1ll*powm[i-1]*m%mod;
	}
	invfac[N-1] = pow(fac[N-1],mod-2);
	for(int i=N-2;i>=0;i--){
		invfac[i] = 1ll*invfac[i+1]*(i+1)%mod;
	}
	int ans = 0;
	for(int i=1;i<=m;i++){
		if(i+1>n)break;
		int bsel = mul(C(m-1,i-1),powm[n-1-i]);
		int tsel = mul(fac[i-1],mul(C(n-2,i-1),F(n,i+1)));
		//cout<<i<<' '<<bsel<<' '<<tsel<<' '<<mul(bsel,tsel)<<endl;
		ans = add(ans,mul( bsel, tsel));
	}
	cout<<ans<<endl;
	return 0;
}