#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

char s[N];
int n, x;

void rmain() {
	int n;
	scanf("%d%d", &n, &x);
	vector <int> A(n);
	for(int i = 0; i < n; ++ i) scanf("%d", &A[i]);
	sort(A.begin(), A.end());
	long long S = 0, day = 0, all = 0;
	for(auto x : A) S += x;
	for(int i = A.size() - 1; i >= 0; -- i) {
		if(S + day * (i + 1) > x) {
			S -= A[i]; continue;
		}
		int c = (x - S - day * (i + 1)) / (i + 1) + 1;
		day += c;
		all += c * (i + 1);
		S -= A[i];
	}
	cout << all << endl;
}


int main() {
	int t;
	for(cin >> t; t --;) {
		rmain();
	}
}