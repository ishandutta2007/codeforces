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
int pow(int a,int b){return b == 0 ? 1 : ( b&1 ? mul(a,sq(pow(a,b/2))) : sq(pow(a,b/2)));}

int n,t[1000020],fac[1000020],invfac[1000020];

int C(int n,int m){return mul(fac[n],mul(invfac[n-m],invfac[m]));}
int cv = 1;
ll T,lwb = 0,upb = 0,mb = 0;

int main() {
	read(n);read(T);
	fac[0] = 1;
	for(int i=1;i<=1000010;i++)fac[i] = mul(i,fac[i-1]);
	invfac[1000010] = pow(fac[1000010],mod-2);
	for(int i=1000010-1;i>=0;i--)invfac[i] = mul(i+1,invfac[i+1]);
	int inv2 = (mod+1)/2,accu = 1,ans = 0;
	for(int i=0;i<n;i++){
		read(t[i]);
		lwb+=t[i];upb+=t[i]+1;
		mb+=t[i];
		if(lwb>T)break;
		cv = sub(mul(cv,2),C(upb-lwb-1,mb-lwb));
		//cout<<i<<' '<<cv<<' '<<mb<<' '<<lwb<<' '<<upb<<endl;
		while(mb<T && mb<upb){
			cv = add(cv,C(upb-lwb,mb-lwb+1));
			mb+=1;
		}
		while(mb>T){
			cv = sub(cv,C(upb-lwb,mb-lwb));
			mb-=1;
		}
		//cout<<i<<' '<<cv<<' '<<mb<<' '<<lwb<<' '<<upb<<endl;
		accu = mul(accu,inv2);
		ans = add(ans,mul(cv,accu));
	}
	cout<<ans<<endl;
	return 0;
}