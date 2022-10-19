#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, t, ans, m, A[N];

char s[N];

int id(int x, int y) {
	return (x - 1) * m + y;
}

void rmain() {
	scanf("%d%d", &n, &m);
	swap(n, m);
	bool ok = 1;
	for(int i = 1; i <= m; ++ i) {
		for(int j = 1; j <= n; ++ j) {
			scanf("%d", &A[id(j, i)]);
		}
	}
	
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			if(i >= 2) {
				ok &= (A[id(i - 1, j)] <= A[id(i, j)]);
			}
		}
	}	
	if(ok) {
		puts("1 1");
		return;
	}
	
	int x = -1, y = -1;
	
	for(int j = 1; j <= m; ++ j) {
		vector <int> vec;
		for(int i = 1; i <= n; ++ i) vec.push_back(A[id(i, j)]);
		sort(vec.begin(), vec.end());
		vector <int> Nt;
		for(int i = 1; i <= n; ++ i) {
			if(vec[i - 1] != A[id(i, j)]) Nt.push_back(i);
		}
		if(Nt.size() > 2) {
			puts("-1");
			return;
		} else if(Nt.size() == 2) {
			x = Nt[0], y = Nt[1];
			break;
		}
	}
	
	if(x == -1) {
		puts("-1");
		return;
	}
	
	ok = 1;
	
	for(int j = 1; j <= m; ++ j) {
		swap(A[id(x, j)], A[id(y, j)]);
		for(int i = 2; i <= n; ++ i) ok &= (A[id(i - 1, j)] <= A[id(i, j)]);
	}
	if(!ok) {
		puts("-1");return;
	} else printf("%d %d\n", x, y);
}

int main() {
	for(cin >> t; t --;) {
		rmain();
	}
}