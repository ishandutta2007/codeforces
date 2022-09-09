#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n, m;
int arr[100100];
int ans[100100];

int main() {
	scanf("%d%d",&n,&m);
	ll s = 0;
	for (int i=0;i<m;i++) {
		scanf("%d",&arr[i]);
		if (i+arr[i]>n) {
			puts("-1");
			return 0;
		}
		s += arr[i];
	}
	if (s<n) {
		puts("-1");
		return 0;
	}
	s = n;
	for (int i=m-1;i>=0;i--) {
		ans[i] = max(i,(int)s-arr[i]);
		s = ans[i];
	}

	for (int i=0;i<m;i++) {
		printf("%d ",ans[i]+1);
	}puts("");

	return 0;
}