#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

int N;
int A[200100];

void pung() {
	puts("NO");
	exit(0);
}

int main() {
	scanf("%d",&N);
	for (int i=0;i<2*N;i++){
		char c;
		scanf(" %c",&c);
		if (c=='+') {
			A[i] = -1;
		}
		else {
			int a;
			scanf("%d",&a);
			A[i] = a;
		}
	}
	vector<int> ans;
	priority_queue<int,vector<int>,greater<int>> pq;
	for (int i=2*N-1;i>=0;i--) {
		if (A[i]>0) {
			if (!pq.empty() && pq.top() < A[i]) pung();
			pq.push(A[i]);
		}
		else {
			if (pq.empty()) pung();
			ans.push_back(pq.top()); pq.pop();
		}
	}
	puts("YES");
	for (int i=N-1;i>=0;i--) {
		printf("%d ",ans[i]);
	}
	puts("");

	return 0;
}