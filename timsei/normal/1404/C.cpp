#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

int n, A[N], lst[N], Max[N], mx, ans[N];

struct Qu {
	int l, r, id;
	void input() {
		scanf("%d%d", &l, &r);
	}
	
	friend bool operator < (Qu a, Qu b) {
		return a.r > b.r;
	}
	
}Q[N];


struct NODE {
	int val, l;
};
vector < NODE > Vec[N];

#define lowbit(x) (x & (-x))

int S[N];

void add(int x, int v) {
	++ x;
	for(int i = x; i < N;  i += lowbit(i))
	++ S[i];
}

int Sum(int x) {
	++ x;
	int res = 0;
	for(int i = x; i; i -= lowbit(i))
	res += S[i];
	return res;
}

int q;

int main() {
	cin >> n >> q;
	for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]);
	for(int i = 1; i <= q; ++ i) 
	Q[i].input(), Q[i].id = i;
	sort(Q + 1, Q + q + 1);
	memset(Max, -1, sizeof(Max));
	mx = -1;
	for(int i = 1; i <= n; ++ i) {
		int d = i - A[i];
		if(d < 0) continue;
		if(!d) {
			lst[i] = i;
			add(lst[i], 1);
			continue;
		}
		else {
			int l = 1, r = i, res = -1, now = Sum(n);	
			while(l <= r) {
				int mid = (l + r) >> 1;
				if(now - Sum(mid - 1) >= d) {
					res = mid; l = mid + 1;
				}
				else r = mid - 1;
			}
			if(res == -1) continue;
			lst[i] = res;
			add(lst[i], 1);
		}
	}
	memset(S, 0, sizeof(S));
	
	for(int i = 1; i <= n; ++ i) {
		if(lst[i]) {
			int l = lst[i] - 1, r = n - i;
			Vec[r].push_back((NODE){A[i] - i, l});
		}
	}
	
	int cur = n + 1;
	
	for(int i = 1; i <= q; ++ i) {
		if(Q[i].r != cur) {
			while(cur > Q[i].r) {
				-- cur;
				for(int j = 0; j < (int)Vec[cur].size(); ++ j)
				add(n + 1 - Vec[cur][j].l, Vec[cur][j].val);
			}
		}
		ans[Q[i].id] = Sum(n + 1 - Q[i].l);
	}
	for(int i = 1; i <= q; ++ i) {
		printf("%d\n", ans[i]);
	}
}