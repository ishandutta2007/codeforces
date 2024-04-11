#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N;
int A[200100];
vector<int> lis[200100];
vector<int> nxts[200100];

int main() {
	int T;

	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		vector<int> vec;
		for (int i=0;i<N;i++) {
			scanf("%d",&A[i]);
			if (lis[A[i]].empty()) vec.push_back(A[i]);
			lis[A[i]].push_back(i);
		}
		while(!vec.empty()) {
			vector<int> nvec;
			for (int i=0;i<vec.size();i++) {
				nxts[vec[i]].push_back(vec[(i+1)%vec.size()]);
				lis[vec[i]].pop_back();
				if (!lis[vec[i]].empty()) nvec.push_back(vec[i]);
			}
			vec = nvec;
		}
		for (int i=0;i<N;i++) {
			printf("%d ",nxts[A[i]].back());
			nxts[A[i]].pop_back();
		}
		puts("");
		for (int i=1;i<=N;i++) lis[i].clear(), nxts[i].clear();
	}

	return 0;
}