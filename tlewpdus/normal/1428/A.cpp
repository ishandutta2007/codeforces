#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1000000007; //998244353



int main() {
	int t;

	scanf("%d",&t);
	while(t--){
		int a, b, c, d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if (a==c&&b==d) {
			puts("0");
		}
		else if (a==c || b==d) {
			printf("%d\n",abs(a-c)+abs(b-d));
		}
		else {
			printf("%d\n",abs(a-c)+abs(b-d)+2);
		}
	}

	return 0;
}