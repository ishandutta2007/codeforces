#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353; // 1000000007

int n;
int arr[300100];

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&arr[i]);
	int ans = 0;
	ll inv = 0;
	for (int b=29;b>=0;b--) {
		int p = 0;
		ll inv1 = 0, inv0 = 0;
//		for (int i=0;i<n;i++) printf("%d ",arr[i]);puts("");
		for (int i=0;i<n;i++) {
			if (i==n-1 || (arr[i]>>(b+1)) != (arr[i+1]>>(b+1))) {
				ll cnt1 = 0, cnt0 = 0;
				for (int j=p;j<=i;j++) {
					if (arr[j]>>b&1) {
						cnt1++;
						inv1 += cnt0;
					}
					else {
						cnt0++;
						inv0 += cnt1;
					}
				}
				vector<int> i0, i1;
				for (int j=p;j<=i;j++) {
					if (arr[j]>>b&1) {
						i1.push_back(arr[j]);
					}
					else {
						i0.push_back(arr[j]);
					}
				}
				for (int j=p;j<p+i0.size();j++) arr[j] = i0[j-p];
				for (int j=p+i0.size();j<=i;j++) arr[j] = i1[j-p-i0.size()];
				p = i+1;
			}
		}
//		printf("%d : %lld, %lld\n",b,inv0,inv1);
		if (inv0 > inv1) {
			ans |= (1<<b);
		}
		inv += min(inv0,inv1);
	}
	printf("%lld %d\n",inv,ans);

	return 0;
}