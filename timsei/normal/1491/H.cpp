#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int BL = (int) sqrt(N + 1000);

int A[N], n, m, id[N], q, ty, fa[N], L[BL], R[BL], sz, C[BL], Tag[BL], l, r, x, Zhi[BL];

int getf(int x) {
	return (fa[x] == x) ? x : fa[x] = getf(fa[x]);
}

void rebuild(int x) {
	if(C[x]) {
		if(!x) {
			for(int i = L[x]; i <= R[x]; ++ i) fa[i] = 1;
			return;
		}
		for(int i = L[x]; i <= R[x]; ++ i)
		fa[i] = i;
		return;
	}
	for(int i = L[x]; i <= R[x]; ++ i) {
		fa[i] = i;
		if(A[i] >= L[x]) fa[i] = A[i], getf(fa[i]);
	}
	
}

int get(int x) {
	return max(A[x] - C[id[x]], 1);
}

int main() {
	cin >> n >> q;
	int Bl = (int)sqrt(n);
	A[1] = 1;
	for(int i = 2; i <= n; ++ i)
	scanf("%d", &A[i]);
	
	for(int i = 1; i <= n; ++ i) {
		id[i] = i / Bl;
		if(i == 1 || id[i] != id[i - 1]) {
			L[id[i]] = i;
		}
		R[id[i]] = i;
		fa[i] = i;
		if(A[i] >= L[id[i]]) 
		fa[i] = A[i];
		getf(i);
	}
	
	for(; q --;) {
		scanf("%d", &ty);
		if(ty == 1) {
			scanf("%d%d%d", &l, &r, &x);
			
			if(id[l] == id[r]) {
				for(int i = l; i <= r; ++ i)
				A[i] = max(A[i] - x, 1);
				rebuild(id[l]);
				continue;
			}
			
			for(int i = l; i <= R[id[l]]; ++ i) {
				A[i] = max(A[i] - x, 1);
			}
			rebuild(id[l]);
			
			for(int i = L[id[r]]; i <= r; ++ i)
			A[i] = max(A[i] - x, 1);
			rebuild(id[r]);
			
			for(int i = id[l] + 1; i < id[r]; ++ i) {
				if(Zhi[i] < R[i] - L[i]) {
					Zhi[i] += x;
					for(int j = L[i]; j <= R[i]; ++ j)
					A[j] = max(A[j] - x, 1);
					rebuild(i);
				}
				else C[i] = min(C[i] + x, n);
			}
		} else {
			scanf("%d%d", &l, &r);
			while(l != r) {
				if(l < r) swap(l, r);
				if(id[l] == id[r]) {
					if(getf(l) == getf(r)) {
						while(l != r) {
							if(l < r) r = get(r);
							else l = get(l);
						}
						break;
					}
					else {
						l = get(getf(l));
						r = get(getf(r));
					}
				} else {
					l = get(getf(l));
				}
			}
			printf("%d\n", l);
		}
	}
}