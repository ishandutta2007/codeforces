#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N;

int query(int w) {
	printf("? %d\n",w);
	fflush(stdout);
	int h;
	scanf("%d",&h);
	return h;
}
void answer(int s) {
	printf("! %d\n",s);
	fflush(stdout);
}

int main() {
	scanf("%d",&N);
	int s = 1, e = 4000100;
	while(s<=e) {
		int m = (s+e)/2;
		if (query(m)==1) e = m-1;
		else s = m+1;
	}
	int ans = s;
	for (int k=2;k<=N;k++) {
		int w = (s-1)/k;
		int h = query(w);
		if (h) {
			ans = min(ans, h * w);
		}
	}
	answer(ans);

	return 0;
}