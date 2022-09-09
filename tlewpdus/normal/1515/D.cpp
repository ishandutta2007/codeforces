#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int N, L, R;
int C[200100];

int main () {
	int tt, ttt;

	scanf("%d",&ttt);
	for (tt=1;tt<=ttt;tt++) {
		scanf("%d%d%d",&N,&L,&R);
		for (int i=0;i<L;i++) {
			int c;
			scanf("%d",&c);
			C[c-1]++;
		}
		for (int i=0;i<R;i++) {
			int c;
			scanf("%d",&c);
			C[c-1]--;
		}
		int SP = 0, SM = 0, CP = 0, CM = 0;
		for (int i=0;i<N;i++) {
			if (C[i]>0) {
				SP+=C[i];
				if (C[i]%2==1) CP++;
			}
			else {
				SM-=C[i];
				if ((-C[i])%2==1) CM++;
			}
		}
		int ans = (SP+SM)/2;
		if (SP>SM) ans += max((CP-SM)/2,0);
		else ans += max((CM-SP)/2,0);
		printf("%d\n",ans);
		for (int i=0;i<N;i++) C[i] = 0;
	}

	return 0;
}