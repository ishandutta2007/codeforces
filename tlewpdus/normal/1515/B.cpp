#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int N;

bool issq(int K) {
	int t = sqrt(K);
	return t*t==K || (t-1)*(t-1)==K || (t+1)*(t+1)==K;
}

int main () {
	int tt, ttt;

	scanf("%d",&ttt);
	for (tt=1;tt<=ttt;tt++) {
		scanf("%d",&N);
		if ((N%2==0&&issq(N/2))||(N%4==0&&issq(N/4))) puts("YES");
		else puts("NO");
	}

	return 0;
}