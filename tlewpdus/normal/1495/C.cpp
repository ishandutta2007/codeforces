#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7; //998244353;

int N, M;
char P[510][510];

int main() {
	int tt;
	scanf("%d",&tt);
	while(tt--) {
		scanf("%d%d",&N,&M);
		for (int i=0;i<N;i++) {
			scanf(" %s",P[i]);
		}
		int si = 0;
		if (N%3==0) si = 1;
		for (int i=si;i<N;i+=3) {
			for (int j=0;j<M;j++) P[i][j] = 'X';
		}
		for (int i=si;i+3<N;i+=3) {
			bool done = false;
			for (int j=0;j<M;j++) if (P[i+1][j]=='X') {
					P[i+2][j] = 'X';
					done = true;
					break;
				}
			if (done) continue;
			for (int j=0;j<M;j++) if (P[i+2][j]=='X') {
					P[i+1][j] = 'X';
					done = true;
					break;
				}
			if (done) continue;
			P[i+1][0] = 'X';
			P[i+2][0] = 'X';
		}
		for (int i=0;i<N;i++) printf("%s\n",P[i]);
	}

	return 0;
}