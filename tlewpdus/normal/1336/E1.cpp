#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int n, m;
ll arr[200100];

vector<ll> xorbasis() {
	ll bas[64];
	for (int i=0;i<64;i++) bas[i] = -1;
	unordered_map<ll,int> lo;
	for (int i=0;i<55;i++) {
		lo[1LL<<i] = i;
	}
	for (int i=0;i<n;i++) {
		ll v = arr[i];
		while(v) {
			int dig = lo[v&-v];
			if (~bas[dig]) {
				v ^= bas[dig];
			}
			else {
				bas[dig] = v;
				break;
			}
		}
	}
	vector<ll> b;
	for (int i=0;i<55;i++) {
		if (bas[i]>=0) {
			b.push_back(bas[i]);
		}
	}
	return b;
}

ll pcnt(ll v) {
	int c = 0;
	while(v) {
		if (v%2) c++;
		v/=2;
	}
	return c;
}

int pc[3010];
ll A[3010][25], B[3010];
ll ans[55];
int main() {
	scanf("%d%d",&n,&m);
	//m = 35;
	//n = 200000;
	for (int i=0;i<n;i++) {
		scanf("%lld",&arr[i]);
		//arr[i] <<= 23;
		//if (i<m) arr[i] = (1LL<<i);
		//else arr[i] = rand();
	}
	vector<ll> bas = xorbasis();
	vector<ll> bl, bh;
	for (ll &v : bas) {
		if ((v&-v)>=(1LL<<24)) bh.push_back(v);
		else bl.push_back(v);
	}
	for (int i=0;i<(1<<bl.size());i++) {
		ll x = 0;
		for (int j=0;j<bl.size();j++) {
			if (i>>j&1) x^=bl[j];
		}
		ll v = pcnt(x&((1LL<<24)-1));
		A[x>>24][v]++;
	}
	for (int i=0;i<(1<<bh.size());i++) {
		ll x = 0;
		for (int j=0;j<bh.size();j++) {
			if (i>>j&1) x^=bh[j];
		}
		B[x>>24]++;
	}
	for (int i=1;i<(1<<11);i++) pc[i] = pc[i&(i-1)]+1;
	for (int i=0;i<(1<<11);i++) {
		for (int v=0;v<=24;v++) {
			for (int j=0;j<(1<<11);j++) {
				ans[pc[i^j]+v] += A[i][v]*B[j];
			}
		}
	}
	ll pp = 1;
	for (int i=0;i<n-(int)bas.size();i++) {
		pp = pp*2%MOD;
	}
	for (int i=0;i<=m;i++) {
		ans[i] = ans[i]%MOD*pp%MOD;
	}
	for (int i=0;i<=m;i++) printf("%lld ",ans[i]%MOD); puts("");

	return 0;
}