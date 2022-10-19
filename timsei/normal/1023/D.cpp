#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int L[N], R[N], n, q, A[N];

set <int> S;

vector <int> pos[N];

bool pd(int i) {
	if(L[i] > R[i] || L[i - 1] > R[i - 1]) return 1;
	if(R[i] < L[i - 1] || R[i - 1] < L[i]) return 1;
	return (L[i] >= L[i - 1] && R[i] <= R[i - 1]);
}

void doit(int l, int r, int x) {
	if(l > r || !S.size()) return;
	set <int> :: iterator L = S.lower_bound(l);
	set <int> :: iterator R = S.upper_bound(r);
	if(R == S.begin()) return;
	-- R;
	if(L == S.end() || R == S.end()) return;
	if((*L) > (*R)) return;
	vector <int> cxt;
	cxt.clear();
	for(; L != R; ++ L) {
		A[*L] = x;
		cxt.push_back(*L);
	}
	A[*R] = x;
	cxt.push_back(*R);
	for(int i = 0; i < (int) cxt.size(); ++ i) S.erase(cxt[i]);
}

#define lowbit(x) (x & (-x))

int SS[N];

void add(int x, int v) {
	for(int i = x; i < N; i += lowbit(i)) SS[i] += v;
}

int sum(int x) {
	int res = 0;
	for(int i = x; i; i -= lowbit(i)) {
		res += SS[i];
	}
	return res;
}

bool pd(void) {
	for(int i = 0; i < (int) pos[0].size(); ++ i) add(pos[0][i], 1);
	for(int i = q; i >= 1; -- i) {
		for(int j = 0; j < (int) pos[i].size(); ++ j) add(pos[i][j], 1);
		if(R[i] < L[i]) continue;
		if(sum(R[i]) - sum(L[i] - 1) == R[i] - L[i] + 1) {
			continue;
		}
		return 1;
	}
	return 0;
}

queue <int> Q;

void BFS(void) {
	while(!Q.empty()) {
		int ind = Q.front();
		Q.pop();
		if(!A[ind - 1] && ind > 1) {
			A[ind - 1] = A[ind];
			Q.push(ind - 1);
		}
		if(ind < n && !A[ind + 1]) {
			Q.push(ind + 1);
			A[ind + 1] = A[ind];
		}
	}
}

main(void) {
	cin >> n >> q;
	memset(L, 127, sizeof(L));
	for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]), 
	L[A[i]] = min(L[A[i]], i), R[A[i]] = max(R[A[i]], i), pos[A[i]].push_back(i);
	if(pd()) {
		puts("NO");
		return 0;
	}
	for(int i = 1; i <= n; ++ i) {
		if(!A[i]) S.insert(i);
	}
	if(!S.size() && L[q] > R[q]) {
		puts("NO");
		return 0;
	}
	if(L[q] > R[q]) {
		bool ok = 0;
		for(int i = 1; i <= n; ++ i) if(!A[i]) {
			A[i] = q;
			S.erase(i);
			ok = 1;
			break;
		}
		if(!ok) {
			puts("NO");
			return 0;
		}
	}
	for(int i = q; i >= 1; -- i) {
		doit(L[i], R[i], i);
	}
	for(int i = 1; i <= n; ++ i) {
		if(A[i])Q.push(i);
	}
	BFS();
	for(int i = 0; i <= q; ++ i) pos[i].clear();
	memset(SS, 0, sizeof(SS));
	memset(L, 127, sizeof(L));
	memset(R, 0, sizeof(R));
	for(int i = 1; i <= n; ++ i) pos[A[i]].push_back(i), L[A[i]] = min(L[A[i]], i), R[A[i]] = max(R[A[i]], i);
	if(pd()) {
		assert(0);
	}
	for(int i = 1; i <= n; ++ i) if(!A[i]) assert(0);
	puts("YES");
	for(int i = 1; i <= n; ++ i) printf("%d ", A[i]);
	puts("");
}