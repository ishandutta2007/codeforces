#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int n, d, m;
vector<ll> lis[2];

int main() {
	scanf("%d%d%d",&n,&d,&m);
	lis[0].push_back(0);
	lis[1].push_back(0);
	for (int i=0;i<n;i++) {
		ll a;
		scanf("%lld",&a);
		if (a>m) lis[1].push_back(a);
		else lis[0].push_back(a);
	}
	sort(lis[0].begin()+1,lis[0].end()); reverse(lis[0].begin()+1,lis[0].end());
	sort(lis[1].begin()+1,lis[1].end()); reverse(lis[1].begin()+1,lis[1].end());
	for (int i=1;i<lis[0].size();i++) lis[0][i]+=lis[0][i-1];
	for (int i=1;i<lis[1].size();i++) lis[1][i]+=lis[1][i-1];
	ll maxi = 0;
	for (int a=0;a<lis[1].size();a++) {
		ll cnt = n - 1LL*(d+1)*(a-1)-1;
		if (cnt<0) continue;
		cnt = min(cnt,(ll)lis[0].size()-1);
		maxi = max(maxi,lis[1][a]+lis[0][cnt]);
	}
	printf("%lld\n",maxi);

	return 0;
}