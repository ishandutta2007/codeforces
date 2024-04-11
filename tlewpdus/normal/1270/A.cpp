#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MOD = 1e9+7;
const int INT = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n;

int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int n, a, b;
		scanf("%d%d%d",&n,&a,&b);
		int maxi = 0;
		for (int i=0;i<a;i++) {
			int p;
			scanf("%d",&p);
			maxi = max(maxi,p);
		}
		int maxi2=0;
		for (int i=0;i<b;i++) {
			int p;
			scanf("%d",&p);
			maxi2 = max(maxi2,p);
		}
		puts(maxi>maxi2?"YES":"NO");
	}

	return 0;
}