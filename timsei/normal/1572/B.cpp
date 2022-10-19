#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, A[N];

vector <int> ans;

void out() {
	for(int i = n - 2; i >= 1; i -= 2) {
		if(A[i] == 0 && A[i + 1] == 0) continue;
		if(A[i] == A[i + 1]) {
			ans.push_back(i);
			A[i] = A[i + 1] = 0;
			continue;
		} else {
			int x = (A[i - 1] ^ A[i] ^ A[i + 1]);
			A[i - 1] = x;
			ans.push_back(i - 1);
			ans.push_back(i);
		}
	}
}

bool solve(int n) {
	ans.clear();
	if(A[n] == 0) {
		if(n == 3) {
			if(A[1] == A[2] && A[1] == 1) 
			return 0;
		}
		out();
		return 1;
	}
	
	for(int i = n; i >= 3; i -= 2) {
		if(A[i - 1] == A[i - 2]) continue;
		else {
			for(int j = i; j <= n; j += 2) {
				ans.push_back(j - 2);
				int x = (A[j] ^ A[j - 1] ^ A[j - 2]);
				A[j] = A[j - 1] = A[j - 2] = x;
			}
			out();
			return 1;
		}
	}
	return 0;
}

int main() {
	int t;
	for(cin >> t; t --;) {
		scanf("%d", &n);
		int x = 0;
		for(int i = 1; i<= n; ++ i)
		scanf("%d", &A[i]), x ^= A[i];
		if(x) {
			puts("NO");
			continue;
		}
		if(solve(n)) {
			puts("YES");
			printf("%d\n", (int)ans.size());
			for(int i = 0; i < (int) ans.size(); ++ i) {
				printf("%d ", ans[i]);
			}
			puts("");
			continue;
		} else {
			reverse(A + 1, A + n + 1);
			if(solve(n)) {
				puts("YES");
				printf("%d\n", (int)ans.size());
				for(int i = 0; i < (int) ans.size(); ++ i)
				printf("%d ", n - ans[i] - 1);
				puts("");
				continue;
			}
		}
		puts("NO");
	}
}