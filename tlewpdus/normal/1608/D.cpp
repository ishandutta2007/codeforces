#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N;
char S[100100][3];
ll D[100100][4];

ll ipow(ll a, ll n) {
	if (!n) return 1;
	ll t = ipow(a,n/2);
	return t*t%MOD*(n%2?a:1)%MOD;
}

ll comb(ll n, ll r) {
	if (r<0||r>n) return 0;
	ll t = 1;
	for (int i=1;i<=n;i++) t=t*i%MOD;
	for (int i=1;i<=r;i++) t=t*ipow(i,MOD-2)%MOD;
	for (int i=1;i<=n-r;i++) t=t*ipow(i,MOD-2)%MOD;
	return t;
}

int main() {
	scanf("%d",&N);
	for (int i=1;i<=N;i++) scanf(" %s",S[i]);

	int t = 0, b = 0, w = 0, c = 0, bw = 0, wb = 0;
	for (int i=1;i<=N;i++) {
		if (S[i][0]=='?' && S[i][1]=='?') t++;
		if (S[i][0]=='B') b++;
		if (S[i][1]=='B') b++;
		if (S[i][0]=='W') w++;
		if (S[i][1]=='W') w++;
		if (S[i][0]=='B' && S[i][1]=='B') c++;
		if (S[i][0]=='W' && S[i][1]=='W') c++;
		if (S[i][0]=='B' && S[i][1]=='W') bw++;
		if (S[i][0]=='W' && S[i][1]=='B') wb++;
		if ((int)(S[i][0]=='?')+(int)(S[i][1]=='?')==1) {
			if (S[i][0]=='B' || S[i][1]=='W') bw++;
			else wb++;
		}
	}
	ll ans = comb(2*N-b-w, N-w);
	if (c==0) {
		ll x = 1;
		for (int i=0;i<t;i++) x = x*2%MOD;
		x = max((x-(bw==0)-(wb==0)),0LL);
		ans = (ans-x+MOD)%MOD;
	}

	printf("%lld\n",ans);

	return 0;
}