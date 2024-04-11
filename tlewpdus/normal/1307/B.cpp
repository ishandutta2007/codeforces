#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;

int n;
int arr[200100];
char str[200100];

int main() {
	int ttt;

	scanf("%d",&ttt);
	while(ttt--) {
		int d;
		scanf("%d%d",&n,&d);
		int maxi = 0, done = 0;
		for (int i=0;i<n;i++) {
			int a;
			scanf("%d",&a);
			if (d==a) done = 1;
			maxi = max(maxi,a);
		}
		if (done) printf("1\n");
		else printf("%d\n",max(2,(d+maxi-1)/maxi));
	}

	return 0;
}