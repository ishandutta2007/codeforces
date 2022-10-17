#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second
 
const int N = 2e5 + 10;
int ans[N], ans2[N], d[N];
void add(int l, int r, int delta) {
	d[l] += delta;
	d[r + 1] -= delta;
} 

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
 	int m, n;
 	cin >> m >> n;	
 	vector<pair<int, int>> a(n), b(n);
 	for (int i = 0; i < n; i++) {
 		cin >> a[i].F;
 		a[i].S = i + 1;
 	}
 	for (int i = 0; i < n; i++) {
 		cin >> b[i].F;
 		b[i].S = i + 1;
 	}
 	sort(all(a));
 	sort(all(b));
 	vector<int> ans(n), ans2(n);
 	/*for (int i = 0; i < n; i++) {
 		for (int j = 0; j < n; j++) {
 			ans2[i] += min(abs(b[j].F - a[(j + i) % n].F), m - abs(b[j].F - a[(j + i) % n].F));
 		}
 	}*/
 	for (int i = 0; i < n; i++) {
 		int mx = -1;
 		if (b[i].F - a[0].F > m / 2) {
 			int to = lower_bound(all(a), make_pair(b[i].F - m / 2, 0ll)) - a.begin() - 1;
 			int cl = n - i, cr = to - i;
 			if (cr < 0) {
 				cr += n;
 			}
 			if (cl <= cr) {
 				add(cl, cr, m - b[i].F);
 			}
 			else {
 				add(cl, n - 1, m - b[i].F);
 				add(0, cr, m - b[i].F);
 			}
 			mx = to;
 		}
 		if (mx + 1 < n && b[i].F >= a[mx + 1].F) {
 			int to = upper_bound(all(a), make_pair(b[i].F + 1, -1ll)) - a.begin() - 1;
 			if (mx + 1 <= to) {
 				int cl = (mx + 1) - i, cr = to - i;
	 			if (cl < 0) {
	 				cl += n;
	 			}
	 			if (cr < 0) {
	 				cr += n;
	 			}
	 			if (cl <= cr) {
	 				add(cl, cr, b[i].F);
	 			}
	 			else {
	 				add(cl, n - 1, b[i].F);
	 				add(0, cr, b[i].F);
	 			}
	 			mx = to;
	 		}	
		}
		if (mx + 1 < n && a[mx + 1].F - b[i].F <= m / 2) {
			int to = lower_bound(all(a), make_pair(b[i].F + m / 2 + 1, 0ll)) - a.begin() - 1;
			if (mx + 1 <= to) {
				int cl = (mx + 1) - i, cr = to - i;
	 			if (cl < 0) {
	 				cl += n;
	 			}
	 			if (cr < 0) {
	 				cr += n;
	 			}
	 			if (cl <= cr) {
	 				add(cl, cr, -b[i].F);
	 			}
	 			else {
	 				add(cl, n - 1, -b[i].F);
	 				add(0, cr, -b[i].F);
	 			}
	 			mx = to;
			}
		}
		if (mx + 1 < n) {
			int to = n - 1;
			if (mx + 1 <= to) {
				int cl = (mx + 1) - i, cr = to - i;
	 			if (cl < 0) {
	 				cl += n;
	 			}
	 			if (cr < 0) {
	 				cr += n;
	 			}
	 			if (cl <= cr) {
	 				add(cl, cr, m + b[i].F);
	 			}
	 			else {
	 				add(cl, n - 1, m + b[i].F);
	 				add(0, cr, m + b[i].F);
	 			}
	 			mx = to;
			}	
		} 		
 	}

 	/*for (int i = 0; i < n; i++) {
 		for (int j = 0; j < n; j++) {
 			int cur_shift = i - j;
 			if (cur_shift < 0) {
 				cur_shift += n;
 			}
 			if (b[j].F - a[i].F > m / 2) {
 				ans[cur_shift] += a[i].F;
 			}
 			else if (b[j].F >= a[i].F) {
 				if (i > 0) ans[cur_shift] -= a[i].F;
 			}
 			else if (a[i].F - b[j].F > m / 2) {
 				//ans[cur_shift] -= a[i].F;
 			}
 			else {
 				//ans[cur_shift] += a[i].F;
 			}
 		}
 	}*/
 	swap(a, b);
 	for (int i = 0; i < n; i++) {
 		int mx = -1;
 		if (b[i].F - a[0].F > m / 2) {
 			int to = lower_bound(all(a), make_pair(b[i].F - m / 2, 0ll)) - a.begin() - 1;
 			int cl = n - i, cr = to - i;
 			cl *= -1, cr *= -1;
 			if (cl < 0) {
 				cl += n;
 			}
 			if (cr < 0) {
 				cr += n;
 			}
 			swap(cl, cr);
 			if (cl <= cr) {
 				add(cl, cr, -b[i].F);
 			}
 			else {
 				add(cl, n - 1, -b[i].F);
 				add(0, cr, -b[i].F);
 			}
 			mx = to;
 		}
 		if (mx + 1 < n && b[i].F > a[mx + 1].F) {
 			int to = upper_bound(all(a), make_pair(b[i].F, -1ll)) - a.begin() - 1;
 			if (mx + 1 <= to) {
 				int cl = (mx + 1) - i, cr = to - i;
	 			cl *= -1, cr *= -1;
	 			if (cl < 0) {
	 				cl += n;
	 			}
	 			if (cr < 0) {
	 				cr += n;
	 			}
	 			swap(cl, cr);
	 			if (cl <= cr) {
	 				add(cl, cr, b[i].F);
	 			}
	 			else {
	 				add(cl, n - 1, b[i].F);
	 				add(0, cr, b[i].F);
	 			}
	 			mx = to;
	 		}	
		}
		if (mx + 1 < n && a[mx + 1].F - b[i].F <= m / 2) {
			int to = lower_bound(all(a), make_pair(b[i].F + m / 2 + 1, 0ll)) - a.begin() - 1;
			//cout << mx + 1 << ' ' << to << '\n';
			if (mx + 1 <= to) {
				int cl = (mx + 1) - i, cr = to - i;
	 			//cout << cl << ' ' << cr << '\n';
	 			cl *= -1, cr *= -1;
	 			if (cl < 0) {
	 				cl += n;
	 			}
	 			if (cr < 0) {
	 				cr += n;
	 			}
	 			swap(cl, cr);
	 			//cout << cl << ' ' << cr << '\n';
	 			if (cl <= cr) {
	 				add(cl, cr, -b[i].F);
	 			}
	 			else {
	 				add(cl, n - 1, -b[i].F);
	 				add(0, cr, -b[i].F);
	 			}
	 			mx = to;
			}
		}
		if (mx + 1 < n) {
			int to = n - 1;
			if (mx + 1 <= to) {
				int cl = (mx + 1) - i, cr = to - i;
	 			cl *= -1, cr *= -1;
	 			if (cl < 0) {
	 				cl += n;
	 			}
	 			if (cr < 0) {
	 				cr += n;
	 			}
	 			swap(cl, cr);
	 			if (cl <= cr) {
	 				add(cl, cr, b[i].F);
	 			}
	 			else {
	 				add(cl, n - 1, b[i].F);
	 				add(0, cr, b[i].F);
	 			}
	 			mx = to;
			}	
		}
 	}
 	swap(a, b);
 	int cur = 0;
 	for (int i = 0; i < n; i++) {
 		cur += d[i];
 		ans[i] += cur;
 	}
 	pair<int, int> best = {1e18, -1};
 	for (int i = 0; i < n; i++) {
 		best = min(best, make_pair(ans[i], i));
 	}
 	cout << best.F << '\n';
 	vector<int> id(n);
 	for (int i = 0; i < n; i++) {
 		id[a[(i + best.S) % n].S - 1] = b[i].S; 
 	}
 	for (auto it : id) {
 		cout << it << ' ';
 	}
 	cout << '\n';
}