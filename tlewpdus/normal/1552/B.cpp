#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1000000007;

int N;
int R[50010][5];

int main() {
	int tt;

	scanf("%d",&tt);
	while(tt--) {
		scanf("%d",&N);
		for (int i=0;i<N;i++) for (int j=0;j<5;j++) scanf("%d",&R[i][j]);
		int idx = 0;
		for (int i=1;i<N;i++) {
			int c = 0;
			for (int j=0;j<5;j++) {
				if (R[idx][j]>R[i][j]) c++;
			}
			if (c>=3) idx = i;
		}
		bool mang = false;
		for (int i=0;i<N;i++) {
			if (idx==i) continue;
			int c = 0;
			for (int j=0;j<5;j++) if (R[idx][j]<R[i][j]) c++;
			if (c<3) {
				puts("-1");
				mang = true;
				break;
			}
		}
		if (!mang) printf("%d\n",idx+1);
	}

	return 0;
}