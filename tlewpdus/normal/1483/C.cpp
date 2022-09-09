#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N;
int H[300100];
ll B[300100];
ll D[300100];
multiset<ll> ms;

int main() {
	scanf("%d",&N);
	for (int i=1;i<=N;i++) scanf("%d",&H[i]);
	for (int i=1;i<=N;i++) scanf("%lld",&B[i]);
	vector<pll> st;
	for (int i=1;i<=N;i++) {
		ll v = D[i-1];
		while(!st.empty()&&H[st.back().first]>H[i]) {
			pll t = st.back(); st.pop_back();
			v = max(v,t.second);
			ms.erase(ms.find(t.second+B[t.first]));
		}
		st.emplace_back(i,v);
		ms.insert(v+B[i]);
		D[i] = *prev(ms.end());
	}
	printf("%lld\n",D[N]);

	return 0;
}