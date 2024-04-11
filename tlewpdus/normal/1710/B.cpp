#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N, M;
pll P[200100];
vector<pll> slope;

int main() {
	int T;

	scanf("%d",&T);
	while(T--) {
		slope.clear();
		scanf("%d%d",&N,&M);
		for (int i=0;i<N;i++) {
			ll a, b;
			scanf("%lld%lld",&a,&b);
			P[i] = {a,b};
			slope.emplace_back(a-b,1);
			slope.emplace_back(a,-2);
			slope.emplace_back(a+b,1);
		}
		sort(slope.begin(),slope.end());
		ll v = 0, s = 0;
		ll xmax = -LINF, ymax = -LINF;
		for (int i=1;i<slope.size();i++) {
			s += slope[i-1].second;
			v += s*(slope[i].first-slope[i-1].first);
			if (v>M) {
				ll a = slope[i].first;
				ll b = v-M;
				xmax = max(xmax,b-a);
				ymax = max(ymax,b+a);
			}
		}
		for (int i=0;i<N;i++) {
			if (P[i].second-P[i].first>=xmax && P[i].second+P[i].first>=ymax) {
				printf("1");
			}
			else printf("0");
		}
		puts("");
	}

	return 0;
}