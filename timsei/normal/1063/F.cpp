#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

char s[N];

int n, dp[N];

#define lc (no << 1)
#define rc (no << 1 | 1)
#define gm int mid = (L[no] + R[no]) >> 1

namespace Seg{
	const int Segment_Size = N * 4;
	
	int L[Segment_Size], R[Segment_Size], MX[Segment_Size];
	
	void up(int no) {
		MX[no] = max(MX[lc], MX[rc]);
	}
	
	void build(int no, int l, int r, int *A) {
		L[no] = l, R[no] = r;
		if(L[no] == R[no]) {
			MX[no] = A[l];
			return;
		}
		gm;
		build(lc, l, mid, A);
		build(rc, mid + 1, r, A);
		up(no);
	}
	
	int QMX(int no, int l, int r) {
		if(L[no] == l && R[no] == r) 
		return MX[no];
		gm;
		if(l > mid) return QMX(rc, l, r);
		return (r <= mid) ? QMX(lc, l, r) : max(QMX(lc, l, mid), QMX(rc, mid + 1, r));
	}
	
	void Chg(int no, int x, int y) {
		if(L[no] == R[no]) {
			MX[no] = y;
			return;
		}
		gm;
		if(x > mid) Chg(rc, x, y);
		else Chg(lc, x, y);
		up(no);
	}
}

namespace SA {
	int Sa[N], Rk[N], id[N], h[N], gap[N], st[N][20];
	pair <int, int> who[N];
	vector < int > T[N], T2[N];
	void build() {
		for(int i = 1; i <= n; ++ i) who[i] = make_pair(s[i], i);
		sort(who + 1, who + n + 1);
		for(int i = 1; i <= n; ++ i) Rk[who[i].second] = ((who[i].first == who[i - 1].first) ? Rk[who[i - 1].second] : i), Sa[i] = who[i].second;
		for(int i = 1; i < 20; ++ i) {
			for(int j = 0; j <= n; ++ j) T[j].clear(), T2[j].clear();
			for(int j = 1; j <= n; ++ j) {
				int now = Sa[j];
				T[(now + (1 << i - 1) <= n) ? Rk[now + (1 << i - 1)] : 0].push_back(now);
			}
			
			for(int j = 0; j <= n; ++ j) {
				for(int k = 0; k < (int)T[j].size(); ++ k) 
				T2[Rk[T[j][k]]].push_back(T[j][k]);
			}
			
			int tot = 0;
			for(int j = 0; j <= n; ++ j) {
				for(int k = 0; k < (int) T2[j].size(); ++ k) {
					int V = T2[j][k];
					Sa[++ tot] = V;
					who[tot] = make_pair(Rk[V], (V + (1 << i - 1) <= n) ? Rk[V + (1 << i - 1)] : 0);
				}
			}
			
			for(int j = 1; j <= n; ++ j) {
				Rk[Sa[j]] = (who[j] == who[j - 1]) ? Rk[Sa[j - 1]] : j;
			}
		}
		//Height
		for(int i = 1; i <= n; ++ i) {
			if(Rk[i] == n) h[i] = 0;
			else {
				h[i] = max(0, h[i - 1] - 1);
				int b = Sa[Rk[i] + 1];
				for(;;) {
					if((h[i] + b > n) || (i + h[i] > n) || (s[b + h[i]] != s[i + h[i]])) 
					break;
					++ h[i];
				}
			}
		}
		for(int i = 1; i < n; ++ i) gap[i] = h[Sa[i]];
		for(int i = 1; i < n; ++ i) st[i][0] = gap[i];
		for(int j = 1; j < 20; ++ j) {
			for(int i = 1; i < n; ++ i) {
				if(i + (1 << j) > n) continue;
				st[i][j] = min(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
			}
		}
	}
	
	
	bool get(int l, int r) {
		int cur = Rk[l], len = r - l + 1;
		int L, R; L = cur - 1, R = cur;
		for(int i = 19; i >= 0; -- i) {
			int Llen = L - (1 << i);
			if(Llen < 0 || st[Llen + 1][i] < len) continue;
			else L = Llen;
		}
		for(int i = 19; i >= 0; -- i) {
			int Rlen = R + (1 << i);
			if(Rlen > n || st[R][i] < len) continue;
			else R = Rlen;
		}
		++ L;
		// L - R
		if(L > R) return 0;
		if(Seg :: QMX(1, L, R) >= len) return 1;
		else return 0;
	}
}

int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	SA :: build();
	Seg :: build(1, 1, n, dp);
	SA :: get(26, 26);
	int ans = 0;
	for(int i = n; i >= 1; -- i) {
		for(dp[i] = dp[i + 1] + 1; dp[i]; -- dp[i]) {
			// [i, i + j - 1]
			if(i + dp[i] <= n) Seg :: Chg(1, SA :: Rk[i + dp[i]], dp[i + dp[i]]);
			if(SA :: get(i, i + dp[i] - 2) || SA :: get(i + 1, i + dp[i] - 1)) break;
		}
		ans = max(ans, dp[i]);
		//cerr << i <<" " << dp[i] << endl;
	}
	cout << ans << endl;
}