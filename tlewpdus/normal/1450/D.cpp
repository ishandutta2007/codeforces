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
int A[300100];
int C[300100];

bool ok(int T) {
	deque<int> dq;
	vector<int> MC(N+1,0);
	for (int i=0;i<N;i++) {
		if (!dq.empty()&&dq.front()<=i-T) dq.pop_front();
		while(!dq.empty()&&A[dq.back()]>=A[i]) dq.pop_back();
		dq.push_back(i);
		if (i>=T-1) MC[A[dq.front()]]++;
	}
	for (int i=1;i<=N-T+1;i++) {
		if (MC[i]!=1) return false;
	}
	return true;
}

int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&N);
		for (int i=1;i<=N;i++) C[i] = 0;
		for (int i=0;i<N;i++) {
			scanf("%d",&A[i]);
			C[A[i]]++;
		}
		if (N==1) {
			if (A[0]==1) puts("1");
			else puts("0");
			continue;
		}
		int c1 = 1;
		for (int i=1;i<=N;i++) {
			if (C[i]!=1) c1=0;
		}
		int cN = (C[1]>0);
		int l = 2, r = N-1;
		while(l<=r) {
			int m = (l+r)/2;
			if (ok(m)) r = m-1;
			else l = m+1;
		}
		printf("%d",c1);
		for (int i=2;i<=N-1;i++) printf("%d",i>=l);
		printf("%d\n",cN);
	}

	return 0;
}