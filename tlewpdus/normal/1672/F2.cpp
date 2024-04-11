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
int B[200100];
int C[200100];
vector<int> lis[200100];
int deg[200100];

int main() {
	int T;

	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		for (int i=0;i<N;i++) {
			scanf("%d",&A[i]);
			C[A[i]]++;
		}
		int maxi = 0, maxt = 1;
		for (int i=1;i<=N;i++) {
			if (maxi<C[i]) {
				maxi=C[i];
				maxt = i;
			}
		}
		for (int i=0;i<N;i++) {
			scanf("%d",&B[i]);
			if (A[i]!=maxt && B[i]!=maxt) {
				lis[A[i]].push_back(B[i]);
				deg[B[i]]++;
			}
		}
		queue<int> q;
		for (int i=1;i<=N;i++) {
			if (deg[i]==0) q.push(i);
		}
		while(!q.empty()) {
			int here = q.front(); q.pop();
			for (int &there : lis[here]) {
				deg[there]--;
				if (deg[there]==0) q.push(there);
			}
		}
		bool good = true;
		for (int i=1;i<=N;i++) {
			if (deg[i]>0) {
				good = false;
			}
		}
		puts(good?"AC":"WA");
		for (int i=1;i<=N;i++) {
			lis[i].clear();
			C[i] = 0;
			deg[i] = 0;
		}
	}

	return 0;
}