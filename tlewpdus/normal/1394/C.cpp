#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int n;
pll arr[300100];

pll tmp;
bool ok(ll T) {
	ll xmin = 0, xmax = LINF, ymin = 0, ymax = LINF, yxmin = -LINF, yxmax = LINF;
	for (int i=0;i<n;i++) {
		xmin = max(xmin,arr[i].first-T);
		xmax = min(xmax,arr[i].first+T);
		ymin = max(ymin,arr[i].second-T);
		ymax = min(ymax,arr[i].second+T);
		yxmin = max(yxmin,arr[i].second-arr[i].first-T);
		yxmax = min(yxmax,arr[i].second-arr[i].first+T);
	}
	if (xmin>xmax || ymin>ymax || yxmin > yxmax) return false;
	if (ymax-xmin < yxmin) return false;
	if (ymin-xmax > yxmax) return false;
	auto good = [&](ll x, ll y) {
		return xmin<=x&&x<=xmax&&ymin<=y&&y<=ymax&&yxmin<=y-x&&y-x<=yxmax;
	};
	if (good(0,0) && !good(0,1) && !good(1,0) && !good(1,1)) return false;
	if (ymin-xmax >= yxmin) tmp = {xmax,ymin};
	else {
		ll tx = ymin-yxmin;
		if (xmin<=tx&&tx<=xmax) tmp = {tx,ymin};
		else tmp = {xmin,yxmin+xmin};
	}
	if (tmp.first==0&&tmp.second==0) {
		if (good(0,1)) tmp = {0,1};
		else if (good(1,1)) tmp = {1,1};
		else if (good(1,0)) tmp = {1,0};
	}
	return true;
}

char buf[500100];
int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%s",buf);
		ll a = 0, b = 0;
		for (int j=0;buf[j];j++) {
			if (buf[j]=='B') a++;
			else b++;
		}
		arr[i] = {a,b};
	}
	ll s = 0, e = 3e6;
	while(s<=e) {
		ll m = (s+e)/2;
		if (ok(m)) e = m-1;
		else s = m+1;
	}
	printf("%lld\n",s);
	ok(s);
	for (int i=0;i<tmp.first;i++) printf("B");
	for (int i=0;i<tmp.second;i++) printf("N");
	puts("");

	return 0;
}