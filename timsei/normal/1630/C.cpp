#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int t, n, k, A[N], L[N], R[N], l[N], r[N];

struct Seg {
	int l, r;
	friend bool operator < (Seg a, Seg b) {
		return a.l < b.l;
	}
};

vector < Seg > All;

int main() {
	for(t = 1; t --;) {
		scanf("%d", &n);
		for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]), l[i] = L[i] = n + 1, r[i] = R[i] = 0;
		All.clear();
		for(int i = 1; i <= n; ++ i) {
			L[A[i]] = min(L[A[i]], i);
			R[A[i]] = max(R[A[i]], i);
		}
		for(int i = 1; i <= n; ++ i) {
			if(L[i] < R[i]) {
				r[L[i]] = R[i];
				l[R[i]] = L[i];
			}
		}
		
		int mx = 0, curR = 0, ans = 0;
		
		for(int i = 1; i <= n; ++ i) {
			if(r[i] == 0 && l[i] == n + 1) {
				if(curR >= i) {
					++ ans;
				}
				continue;
			}
			if(l[i] != n + 1) continue;
			if(r[i] < mx) {
				l[r[i]] = n + 1;
				if(curR >= i) {
					++ ans;
				}
				continue;
			} else {
				All.push_back((Seg){i, r[i]});
				curR = mx = r[i];
			}
		}
		
		for(int i = 0; i < (int)All.size(); ++ i) {
			int nxt = i + 1;
			
			while(nxt < (int)All.size()) {
				if(nxt == (int)All.size() - 1) {
					if(All[i].r >= All[nxt].l) {
						++ ans; i = nxt; break;
					}
				}
				if(All[i].r >= All[nxt].l && All[i].r >= All[nxt + 1].l) {
					ans += 2;
					++ nxt;
				} else {
					if(All[i].r < All[nxt].l) {
						i = nxt - 1; break;
					} else {
						++ ans; i = nxt - 1; break;
					}
				}
			}
		}
		cout << ans << endl;
	}
}