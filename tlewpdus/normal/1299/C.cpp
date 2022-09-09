#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int n;
vector<pll> st;

void push(pll v) {
	while(!st.empty()) {
		pll p = st.back();
		if (p.first*v.second<p.second*v.first) break;
		st.pop_back();
		v = pll(p.first+v.first,p.second+v.second);
	}
	st.push_back(v);
}

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		ll a;
		scanf("%lld",&a);
		push({a,1});
	}
	for (pll &v : st) {
		for (int i=0;i<v.second;i++) {
			printf("%.20f\n",1.0*v.first/v.second);
		}
	}

	return 0;
}