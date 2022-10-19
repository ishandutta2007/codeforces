#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;

#define lb(x) (x & (-x))

int t, n, m, A[N], B[N], C[N];
int S[N];

void add(int x, int v) {
	for(int i = x; i <= n + m; i += lb(i))
		S[i] += v;
}

int Sum(int x) {
	int res = 0;
	for(int i = x; i; i -= lb(i))
	res += S[i];
	return res;
}

vector <int> All;
vector <int> F[N];

int get(int x) {
	return lower_bound(All.begin(), All.end(), x) - All.begin() + 1;
}

void solve(int l, int r, int L, int R) {
	if(L > R) return;
	if(l == r) {
		for(int i = L; i <= R; ++ i)
		F[l].push_back(B[i]);
		return;
	}
	int mid = (L + R) >> 1;
	int x = B[mid];
	
	int ans = 0, Min = l, cur = 0;
	
	for(int i = l + 1; i <= r; ++ i) {
		ans += (A[i] < x);
	}
	
	cur = ans;
	
	for(int i = l + 1; i <= r; ++ i) {
		cur -= (A[i] < x);
		cur += (A[i] > x);
		if(cur < ans) Min = i, ans = cur;
	}
	
	F[Min].push_back(x);
	solve(l, Min, L, mid - 1);
	solve(Min, r, mid + 1, R);
} 

void rmain() {
	cin >> n >> m;
	All.clear();
	for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]), All.push_back(A[i]);
	for(int i = 1; i <= m; ++ i) scanf("%d", &B[i]), All.push_back(B[i]);
	for(int i = 0; i <= n + m; ++ i) S[i] = 0, F[i].clear();
	sort(B + 1, B + m + 1);
	sort(All.begin(), All.end());
	All.erase(unique(All.begin(), All.end()), All.end());
	for(int i = 1; i <= n; ++ i) A[i] = get(A[i]);
	for(int i = 1; i <= m; ++ i) B[i] = get(B[i]);
	solve(0, n, 1, m);
	long long ans = 0, cnt = 0;
	for(int i = 0; i <= n; ++ i) {
		sort(F[i].begin(), F[i].end()); 
		for(auto v : F[i]) {
			++ cnt;
			add(v, 1);
			ans += cnt - Sum(v);
		}
		if(i != n) {
			++ cnt;
			add(A[i + 1], 1);
			ans += cnt - Sum(A[i + 1]);
		}
	}
	cout << ans << endl;
}

int main() {
	int T;
	for(cin >> T; T --;) {
		rmain();
	}
}