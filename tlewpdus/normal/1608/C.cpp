#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N;
int A[100100], B[100100], mina[100100], minb[100100];
int ord[100100];
int vis[100100];

int main() {
	int t;

	scanf("%d",&t);
	while(t--) {
		scanf("%d",&N);
		for (int i=0;i<N;i++) scanf("%d",&A[i]);
		for (int i=0;i<N;i++) scanf("%d",&B[i]);
		iota(ord,ord+N,0);
		sort(ord,ord+N,[](int a, int b){return A[a]<A[b];});
		int mini = -1;
		for (int id=N-1;id>=0;id--) {
			int i = ord[id];
			if (mini==-1 || B[mini]>B[i]) mini=i;
			minb[i] = mini;
		}
		sort(ord,ord+N,[](int a, int b){return B[a]<B[b];});
		mini = -1;
		for (int id=N-1;id>=0;id--) {
			int i = ord[id];
			if (mini==-1 || A[mini]>A[i]) mini=i;
			mina[i] = mini;
		}
		for (int i=0;i<N;i++) vis[i] = 0;
		int cur = ord[N-1];
		int s = 1;
		while(!vis[cur]) {
			vis[cur] = 1;
			if (s==1) cur = minb[cur];
			else cur = mina[cur];
			s = 1-s;
		}
		for (int i=0;i<N;i++) {
			if (A[cur]<=A[i]||B[cur]<=B[i]) printf("1");
			else printf("0");
		}
		puts("");
	}

	return 0;
}