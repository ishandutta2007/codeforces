#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+7;
#define pb push_back
const int MAXN = 2e3 + 1;
const int M = 1e9+7;


void go() {
	int N; scanf("%d", &N);
	vector<int> A(N);
	for(auto &i : A)
		scanf("%d", &i);
	sort(A.begin(), A.end());

	if(A[0] < 0) {
		puts("NO");
	} else {
		puts("YES");
		puts("101");
		for(int i = 0; i <= 100; i++)
			printf("%d ", i);
		printf("\n");
	}
}

int main() {
	int t = 1;  scanf("%d", &t);
	while(t--) go();
}