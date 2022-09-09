#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1000000007; //998244353

int N;
char str[500100];
ll A[500100], B[500100], C[500100];
ll rm[500100];
vector<ll> lis[500100];

int main() {
	scanf("%d",&N);
	scanf(" %s",str+1);
	for (int i=N;i>0;i--) {
		if (str[i]=='0') rm[i] = 0;
		else rm[i] = rm[i+1]+1;
		if (rm[i]) lis[rm[i]].push_back(i);
	}
	set<ll> se;
	se.insert(0);
	ll ans = 0;
	for (int i=N;i>0;i--) {
		A[i] = A[i+1];
		B[i] = B[i+1];
		for (ll &v : lis[i]) {
			se.insert(v);
			auto it = se.find(v);
			if (next(it)==se.end()) {
				ll p = *prev(it);
				A[i] = v;
				B[i] += (v-p)*v;
			}
			else {
				ll p = *prev(it);
				ll n = *next(it);
				B[i] += (v-p)*v+(n-v)*n-(n-p)*n;
			}
		}
		C[i] = (N+2-i)*A[i]-B[i];
		ans += i*(C[i]-C[i+1]);
	}
	printf("%lld\n",ans);

	return 0;
}