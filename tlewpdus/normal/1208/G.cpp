#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 0x3f3f3f3f;

int n, k;
int phi[1000100];
int chk[1000100];
vector<pii> vec;

int main() {
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) {
		phi[i] = i;
	}
	for (int i=1;i<=n;i++) {
		for (int j=2*i;j<=n;j+=i) phi[j]-=phi[i];
		if (i>=3) {
			vec.push_back({phi[i]+(i%2?0:1),i});
		}
	}
	sort(vec.begin(),vec.end());
	ll ans = 0;
	int c = 0;
	for (int i=0;i<k;i++) {
		//printf("%d!\n",vec[i].second);
		ans += vec[i].first;
		chk[vec[i].second] = 1;
		c++;
		if (vec[i].second%2==0) break;
	}
	if (c!=k) {
		vec.clear();
		for (int i=3;i<=n;i++) {
			if (chk[i]) continue;
			vec.push_back({phi[i],i});
		}
		sort(vec.begin(),vec.end());
		for (int i=0;c<k;i++) {
			//printf("%d!\n",vec[i].second);
			ans += vec[i].first;
			chk[vec[i].second] = 1;
			c++;
		}
	}
	printf("%lld\n",ans+1);

	return 0;
}