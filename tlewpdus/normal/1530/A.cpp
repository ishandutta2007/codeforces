#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;



int main() {
	int tt;

	scanf("%d",&tt);
	while(tt--) {
		int N;
		scanf("%d",&N);
		int dm = 0;
		while(N) {
			dm = max(dm, N%10);
			N/=10;
		}
		printf("%d\n",dm);
	}

	return 0;
}