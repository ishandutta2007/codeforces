#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N, M;
int C[100100];
vector<int> lis[100100];

int main() {
	int tt;
	scanf("%d",&tt);
	while(tt--) {
		scanf("%d%d",&N,&M);
		for (int i=0;i<M;i++) {
			int k;
			scanf("%d",&k);
			for (int j=0;j<k;j++) {
				int a;
				scanf("%d",&a);
				lis[i].push_back(a-1);
			}
			if (k==1) {
				C[lis[i][0]]++;
			}
		}
		int UB = (M+1)/2;
		int mang = 0;
		for (int i=0;i<N;i++) {
			if (C[i]>UB) mang = 1;
		}
		if (mang) {
			puts("NO");
		}
		else {
			puts("YES");
			for (int i=0;i<M;i++) {
				if (lis[i].size()==1) {
					printf("%d ",lis[i][0]+1);
					continue;
				}
				for (int &v : lis[i]) {
					if (C[v]<UB) {
						printf("%d ",v+1);
						C[v]++;
						break;
					}
				}
			}
			puts("");
		}
		for (int i=0;i<M;i++) lis[i].clear();
		for (int i=0;i<N;i++) C[i] = 0;
	}

	return 0;
}