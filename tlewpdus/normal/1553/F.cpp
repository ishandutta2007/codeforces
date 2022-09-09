#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int N;
int M = 300010;
struct BIT {
	ll bit[300100];

	void upd(int idx, ll val) {
		idx++;
		while (idx <= M) {
			bit[idx] += val;
			idx += idx & -idx;
		}
	}

	ll getv(int idx) {
		idx++;
		idx = min(idx,M);
		ll ans = 0;
		while (idx) {
			ans += bit[idx];
			idx -= idx & -idx;
		}
		return ans;
	}
} bit1, bit2;

ll A[200100];

int main() {
	scanf("%d",&N);
//	N = 1000;
	for (int i=0;i<N;i++) {
		scanf("%lld",&A[i]);
//		A[i] = (rand()*RAND_MAX+rand())%M+1;
//		A[i] = i+1;
	}
//	sort(A,A+N);
//	N = unique(A,A+N)-A;
	ll S = 0;
	ll T = 0;
//	ll R = 0;
	for (int i=0;i<N;i++) {
		S += A[i];
		T += bit1.getv(A[i]);
//		printf("%d : %lld!\n",i,bit1.getv(A[i]));
		for (ll j=A[i];j<=M;j+=A[i]) {
			bit1.upd(j,A[i]);
		}
		ll pst = bit2.getv(A[i]-1);
		int p = 1;
		for (ll j=2*A[i]-1;j-A[i]<=M;j+=A[i]) {
			ll cur = bit2.getv(j);
			T += (cur-pst)*p*A[i];
//			if (j<=10) printf("%d : %lld!\n",i,(cur-pst)*p*A[i]);
			pst = cur;
			p++;
		}
		bit2.upd(A[i],1);
		printf("%lld ",S*i-T);
//		for (int j=0;j<i;j++) {
//			R += A[i]%A[j]+A[j]%A[i];
//		}
//		assert(S*i-T==R);
	}
	puts("");

	return 0;
}