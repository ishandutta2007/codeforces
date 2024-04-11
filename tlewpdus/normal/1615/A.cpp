#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;



int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);
		int s = 0;
		for (int i=0;i<n;i++) {
			int a;
			scanf("%d",&a);
			s+=a;
		}
		if (s%n==0) puts("0");
		else puts("1");
	}

	return 0;
}