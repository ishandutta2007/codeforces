#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int n, m;
int cnt[1010];
vector<int> lis[1010];
int arr[200100];

ll ipow(ll a, ll n) {
	if (!n) return 1;
	ll t = ipow(a,n/2);
	return t*t%m*(n%2?a:1)%m;
}

int bit[200100];
void upd(int idx) {
	idx++;
	while(idx<=n) {
		bit[idx]++;
		idx+=idx&-idx;
	}
}
int getv(int idx) {
	idx++;
	int ans = 0;
	while(idx) {
		ans += bit[idx];
		idx&=idx-1;
	}
	return ans;
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) {
		int a;
		scanf("%d",&a);
		arr[i] = a;
		cnt[a%m]++;
	}
	sort(arr,arr+n);
	for (int i=0;i<n;i++) {
		lis[arr[i]%m].push_back(i);
	}
	int bad = 0;
	for (int i=0;i<m;i++) {
		if (lis[i].size()>1) bad = 1;
	}
	if (bad) {
		puts("0");
		return 0;
	}
	ll ans = 1;
	for (int i=0;i<m;i++) {
		for (int j=i+1;j<m;j++) {
			ans = ans*ipow((j-i),1LL*cnt[i]*cnt[j])%m;
		}
	}
	ll sgn = 0;
	for (int i=m-1;i>=0;i--) {
		for (int &v : lis[i]) sgn += getv(v);
		for (int &v : lis[i]) upd(v);
	}
	if (sgn%2) ans = (m-ans)%m;
	printf("%lld\n",(ans%m+m)%m);

	return 0;
}