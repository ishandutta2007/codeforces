#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int n;
int arr[100100];
int pre[100100], suf[100100];

int main() {
	scanf("%d",&n);

	for (int i=1;i<=n;i++) {
		scanf("%d",&arr[i]);
	}
	for (int i=1;i<=n;i++) pre[i] = (pre[i-1]|arr[i]);
	for (int i=n;i;i--) suf[i] = (suf[i+1]|arr[i]);
	int maxi = -1, t = 0;
	for (int i=1;i<=n;i++) {
		if (maxi<(arr[i]|(pre[i-1]|suf[i+1]))-(pre[i-1]|suf[i+1])) {
			maxi=(arr[i]|(pre[i-1]|suf[i+1]))-(pre[i-1]|suf[i+1]);
			t = i;
		}
	}
	printf("%d ",arr[t]);
	for (int i=1;i<=n;i++) {
		if (i!=t) printf("%d ",arr[i]);
	}
	puts("");

	return 0;
}