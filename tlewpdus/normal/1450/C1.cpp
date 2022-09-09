#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7; // 998244353

int t;
int N;
char str[310][310];

int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&N);
		int cnt[3] = {0,0,0};
		for (int i=0;i<N;i++) {
			scanf(" %s",str[i]);
			for (int j=0;j<N;j++) {
				if (str[i][j]=='X') cnt[(i+j)%3]++;
			}
		}
		int t = 0;
		for (int i=1;i<3;i++) {
			if (cnt[t]>cnt[i]) t=i;
		}
		for (int i=0;i<N;i++) {
			for (int j=0;j<N;j++) {
				if (str[i][j]=='X' && (i+j)%3==t) str[i][j]='O';
			}
			str[i][N] = 0;
			printf("%s\n",str[i]);
		}
	}

	return 0;
}