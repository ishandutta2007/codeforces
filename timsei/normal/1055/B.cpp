#include <bits/stdc++.h>
using namespace std;

const int N = 1111111;

int n, m, l, A[N], ty ,a, b, fa[N];

int getf(int x) {
	return (fa[x] == x) ? x : fa[x] = getf(fa[x]);
}

int tot = 0;

void add(int x) {
	fa[x] = x;
	++ tot;
	if(fa[x - 1] != 0) fa[x] = getf(x - 1), -- tot;
	if(fa[x + 1] != 0) fa[getf(x)] = getf(x + 1), -- tot;
}

int main() {
	cin >> n >> m >>l;
	++ l;
	for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]);
	for(int i = 1; i <= n; ++ i) {
		if(A[i] >= l) {
			add(i);
		}
	}
	for(; m --;) {
		scanf("%d", &ty);
		if(!ty) printf("%d\n", tot);
		else {
			scanf("%d%d", &a, &b);
			if(fa[a] != 0) continue;
			else {
				A[a] += b;
				if(A[a] >= l) {
					add(a);
				}
			}
		}
	}
}