#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7; //998244353;

int N;
ll A[100100], B[100100];

int main() {
	int tt;

	scanf("%d",&tt);
	while(tt--) {
		scanf("%d",&N);
		int p1 = 0, p2 = 0;
		for (int i=0;i<N*2;i++) {
			ll a, b;
			scanf("%lld%lld",&a,&b);
			if (a==0) A[p1++] = abs(b);
			else B[p2++] = abs(a);
		}
		sort(A,A+N);
		sort(B,B+N);
		double ans = 0.;
		for (int i=0;i<N;i++) {
			ans += sqrt(A[i]*A[i]+B[i]*B[i]);
		}
		printf("%.30f\n",ans);
	}

	return 0;
}