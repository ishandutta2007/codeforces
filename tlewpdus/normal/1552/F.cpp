#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N;
pii A[200100];
pii C[200100];
int S[200100];

ll bit[400100];
void upd(int idx, ll val) {
	idx++;
	while(idx<=2*N) {
		bit[idx] = (bit[idx]+val)%MOD;
		idx += idx&-idx;
	}
}
ll getv(int idx) {
	idx++;
	ll ans = 0;
	while(idx) {
		ans = (ans+bit[idx])%MOD;
		idx &= idx-1;
	}
	return ans;
}

int main() {
	scanf("%d",&N);
	vector<int> comp;
	for (int i=0;i<N;i++) {
		scanf("%d%d",&A[i].first,&A[i].second);
		scanf("%d",&S[i]);
		C[i] = A[i];
		comp.push_back(C[i].first);
		comp.push_back(C[i].second);
	}
	sort(comp.begin(),comp.end());
	for (int i=0;i<N;i++) {
		C[i].first = lower_bound(comp.begin(),comp.end(),C[i].first)-comp.begin();
		C[i].second = lower_bound(comp.begin(),comp.end(),C[i].second)-comp.begin();
	}
	vector<int> ord(N,0);
	iota(ord.begin(),ord.end(),0);
	sort(ord.begin(),ord.end(),[](int a, int b) {
		return C[a].first<C[b].first;
	});
	ll ans = A[N-1].first+1;
	for (int id=N-1;id>=0;id--) {
		int i = ord[id];
		ll p = (getv(C[i].first)+S[i])%MOD;
		ans = (ans+p*(A[i].first-A[i].second))%MOD;
		upd(C[i].second,p);
	}
	printf("%lld\n",(ans%MOD+MOD)%MOD);

	return 0;
}