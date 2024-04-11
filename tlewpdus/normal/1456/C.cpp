#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7; // 998244353

int N, K;
ll C[500100], S;
int negnum, pos;

ll calc(int T) {
	int lg = (negnum-T+K-1)/K;
	ll sco = 0;
	for (int i=pos;i<pos+T-lg;i++) {
		sco += C[i]*(T-i+pos-1);
	}
	int rem = (N-pos-T+lg);
	for (int i=pos+T-lg;i<N;i++) {
		sco += C[i]*((rem+K)/(K+1)-1);
		rem--;
	}
	return sco+S*T;
}

int main() {
	scanf("%d%d",&N,&K);
	for (int i=0;i<N;i++) scanf("%lld",&C[i]);
	sort(C,C+N);
	reverse(C,C+N);
	if (K==0) {
		ll t = 0;
		for (int i=0;i<N;i++) t += C[i]*(N-i-1);
		printf("%lld\n",t);
		return 0;
	}
	pos = 0;
	while(pos<N&&C[pos]>=0) pos++;
	ll sco = 0;
	S = 0;
	for (int i=0;i<pos;i++) {
		sco += C[i]*(pos-1-i);
		S += C[i];
	}
	negnum = N-pos;
	int sm = (negnum+K)/(K+1);
	ll add = max(calc(sm),calc(negnum));
	int s = sm, e= negnum-1;
	while(s<=e) {
		int m = (s+e)/2;
		if (calc(m)<calc(m+1)) s = m+1;
		else e = m-1;
	}
	if (sm<=s&&s<=negnum) add = max(add,calc(s));
	printf("%lld\n",sco+add);

	return 0;
}