#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int N, X;
int W[110];

int main () {
	int tt, ttt;

	scanf("%d",&ttt);
	for (tt=1;tt<=ttt;tt++) {
		scanf("%d%d",&N,&X);
		int S = 0;
		int inter = -1;
		for (int i=0;i<N;i++) {
			scanf("%d",&W[i]);
			S += W[i];
			if (S==X) inter = i;
		}
		if (S==X) {
			puts("NO");
			continue;
		}
		if (inter!=-1) {
			swap(W[inter],W[inter+1]);
		}
		puts("YES");
		for (int i=0;i<N;i++) {
			printf("%d ",W[i]);
		}
		puts("");
	}

	return 0;
}