#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,pii> piii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

int n;


int main(){
	int t;

	scanf("%d",&t);
	while(t--) {
		ll a, b, n;
		scanf("%lld%lld%lld",&a,&b,&n);
		int c = 0;
		while(a<=n&&b<=n) {
			if (a>b) swap(a,b);
			a += b;
			c++;
		}
		printf("%d\n",c);
	}

	return 0;
}