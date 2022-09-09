#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n;
ll bit[200100], srr[200100], arr[200100];
void upd(int idx, ll val) {
	while(idx<=n) {
		bit[idx]+=val;
		idx+=idx&-idx;
	}
}
ll getv(int idx) {
	ll ans = 0;
	while(idx) {
		ans += bit[idx];
		idx&=idx-1;
	}
	return ans;
}

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%lld",&srr[i]);
	for (int i=1;i<=n;i++) upd(i,i);
	for (int i=n-1;i>=0;i--) {
		int s = 0, e = n-1;
		while(s<=e) {
			int m = (s+e)/2;
			if(getv(m)<=srr[i]) s = m+1;
			else e = m-1;
		}
		arr[i] = s;
		upd(s,-s);
	}
	for (int i=0;i<n;i++) printf("%lld ",arr[i]);
	printf("\n");

	return 0;
}