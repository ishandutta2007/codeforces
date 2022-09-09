#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N;
char S[200100];
ll po2[400100];
ll po3[400100];

int main() {
	scanf(" %s",S);
	N = strlen(S);
	reverse(S,S+N);
	po2[0] = 1;
	for (int i=1;i<=2*N;i++) po2[i] = po2[i-1]*2%MOD;
	po3[0] = 1;
	for (int i=1;i<=2*N;i++) po3[i] = po3[i-1]*3%MOD;
	ll ans = 0;
	ll M = 0, T = 1, P = 1;
	for (int i=0;i<N;i++) {
		if (S[i]=='1') {
			ll L = i;
			ans += po2[L]*po3[L]%MOD + (T+(M+1)*po3[L])*2%MOD;
			T = (T*2+(M+1)*po3[L]%MOD+2*po2[L]%MOD*po3[L]%MOD+P)%MOD;
			M = (M+po2[L])%MOD;
			P = (P*3+po3[L]*po2[L]%MOD*3)%MOD;
		}
		else {
			T = T*2%MOD;
			P = P*3%MOD;
		}
	}
	ans++;
//	printf("%lld!\n",ans);
	ans = ans*3%MOD;
	ans -= 3*(M+1)%MOD*(M+1)%MOD;
	ans += (M+1);
//	printf("%lld!", ans);
	ans = (M+1)*(M+1)%MOD*(M+1)%MOD-ans;
	printf("%lld\n",(ans%MOD+MOD)%MOD);

	return 0;
}