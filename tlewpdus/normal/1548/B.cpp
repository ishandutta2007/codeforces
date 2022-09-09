#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N;
ll A[200100];

ll gcd(ll a, ll b) {
	if (!a) return b;
	return gcd(b%a,a);
}

ll tree[530000];
int key;
void init() {
	key = 1;
	while(key<N) key*=2;
	for (int i=0;i<key*2;i++) tree[i] = 0;
}
void upd(int idx, ll val) {
	idx += key;
	while(idx) {
		tree[idx] = gcd(tree[idx],val);
		idx/=2;
	}
}
ll getv(int s, int e) {
	s+=key;
	e+=key;
	ll res = 0;
	while(s<=e) {
		if (s%2==1) res = gcd(res,tree[s]);
		if (e%2==0) res = gcd(res,tree[e]);
		s = (s+1)/2;
		e = (e-1)/2;
	}
	return res;
}

int main() {
	int t;

	scanf("%d",&t);
	while(t--) {
		scanf("%d",&N);
		init();
		for (int i=0;i<N;i++) scanf("%lld",&A[i]);
		for (int i=0;i+1<N;i++) A[i] = abs(A[i+1]-A[i]);
		N--;
		for (int i=0;i<N;i++) upd(i,A[i]);
		int s = 0, e = -1, ans = 0;
		ll cur = 0;
		while(e+1<N) {
			ll g = gcd(cur, A[e+1]);
			if (g>1) {
				cur = g;
				e++;
			}
			else if (s>e) {
				s++;
				e++;
			}
			else {
				s++;
				cur = getv(s,e);
			}
			ans = max(ans,e-s+1);
		}
		printf("%d\n",ans+1);
	}

	return 0;
}