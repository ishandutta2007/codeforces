#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int t;
int N, M;
char str[200100];
ll fac[200100], fnv[200100];

ll ipow(ll a, ll n) {
	if (!n) return 1;
	ll t= ipow(a,n/2);
	return t*t%MOD*(n%2?a:1)%MOD;
}

ll comb(ll n, ll r) {
	return fac[n]*fnv[r]%MOD*fnv[n-r]%MOD;
}

int main() {
	scanf("%d%d",&N,&M);
	fac[0] = 1;
	for (int i=1;i<=N;i++) fac[i] = fac[i-1]*i%MOD;
	fnv[N] = ipow(fac[N],MOD-2);
	for (int i=N-1;i>=0;i--) fnv[i] = fnv[i+1]*(i+1)%MOD;
	scanf(" %s",str);
	for (int i=1;i<N;i+=2) {
		if (str[i]!='?') {
			if (str[i]=='b') str[i]='w';
			else str[i] = 'b';
		}
	}
	int d = 0, c = 0;
	for (int i=0;i<N;i++) {
		if (str[i]!='?') {
			if (str[i]=='b') d++;
			else d--;
		}
		else c++;
	}
	int ta = 0;
	if ((c-d)%4!=0) ta = 1;
//	printf("%d, %d, %d\n",ta,c,d);
	ll ans = 0;
	for (int a=ta;a<=c;a+=2) {
		ans += comb(c,a)*abs((2*a-c+d)/4)%MOD;
	}
	ans = ans%MOD*ipow(ipow(2,c-1),MOD-2)%MOD;
	printf("%lld\n",(ans+MOD)%MOD);

	return 0;
}