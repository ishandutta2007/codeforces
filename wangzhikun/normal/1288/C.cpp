#include <bits/stdc++.h>
 
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
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int sq(int x){return 1ll*x*x%mod;}
int mpow(int a,int b){return b == 0 ? 1 : ( b&1 ? mul(a,sq(mpow(a,b/2))) : sq(mpow(a,b/2)));}
const int N = 1000000;
int fac[N+10],invfac[N+10],n,m;
 
int C(int n,int m){
	if(n<0 || m<0 || m>n)return 0;
	return mul(fac[n],mul(invfac[m],invfac[n-m]));
}
 
int main() {
	read(m);read(n);
	fac[0] = 1;
	for(int i=1;i<=N;i++)fac[i] = mul(fac[i-1],i);
	invfac[N] = mpow(fac[N],mod-2);
	for(int i=N-1;i>=0;i--) invfac[i] = mul(invfac[i+1],i+1);
	cout<<C(n*2+m-1,n*2)<<endl;
	return 0;
}