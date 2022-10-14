#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

#define vt vector
#define all(x) x.begin(), x.end()
#define trav(i, x) for(auto &i : x)
#define lb lower_bound
#define ub upper_bound

template<typename T>
void dbg(vector<T> &a) {
	trav(i, a) printf("%d ", i);
	printf("\n");
}
int main() {

	int T; scanf("%d", &T);
	while(T--) {
		int N, K; scanf("%d%d", &N, &K);
		vector<int> A(N);
		vector<int> peaks;
		
		trav(i, A) scanf("%d", &i);
		
		for(int i = 1; i < N - 1; i++) {
			if(A[i] > A[i+1] && A[i] > A[i-1]) {
				peaks.push_back(i);
			}
		}
		int mx=0,l=1;
		
		for(int i = 0; i < N - K + 1; i++) {
			int p = lb(peaks.begin(), peaks.end(), i+1) - peaks.begin();
			int e = ub(peaks.begin(), peaks.end(), i+K-2) - peaks.begin();
			e--;
			int res = e-p+1;
			if(res>mx) {
				mx=res;
				l=i+1;
			}
		}
		printf("%d %d\n", mx + 1, l);
		
	}
}