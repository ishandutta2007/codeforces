#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
 
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, q, a[200005];

struct segt
{
	int mx[1600005];
	int mn[1600005];
	LL sum[1600005];
	int lzy[1600005];
	int len[1600005];
	void upd(int cv, int v) {
		mx[cv] = mn[cv] = v; sum[cv] = v * 1LL * len[cv]; lzy[cv] = v;
	}
	void push(int cv) {
		if(!lzy[cv]) return;
		upd(cv << 1, lzy[cv]);
		upd(cv << 1 | 1, lzy[cv]);
		lzy[cv] = 0;
	}
	void pull(int cv) {
		mx[cv] = mx[cv << 1]; mn[cv] = mn[cv << 1 | 1]; sum[cv] = sum[cv << 1] + sum[cv << 1 | 1];
	}
	void build(int cv = 1, int cl = 1, int cr = n) {
		len[cv] = cr - cl + 1; lzy[cv] = 0;
		if(cl == cr) {
			mx[cv] = mn[cv] = sum[cv] = a[cl]; return;
		}
		int mid = cl + cr >> 1;
		build(cv << 1, cl, mid);
		build(cv << 1 | 1, mid + 1, cr);
		pull(cv);
	}
	void modify(int v, int l, int r, int cv = 1, int cl = 1, int cr = n) {
		if(l > r || cl > cr || cl > r || cr < l) return;
		if(l <= cl && cr <= r) {
			upd(cv, v); push(cv); return;
		}
		int mid = cl + cr >> 1;
		push(cv);
		modify(v, l, r, cv << 1, cl, mid);
		modify(v, l, r, cv << 1 | 1, mid + 1, cr);
		pull(cv);
	}
	LL get(int l, int r, int cv = 1, int cl = 1, int cr = n) {
		if(cl > r || cr < l) return 0LL;
		if(l <= cl && cr <= r) return sum[cv];
		int mid = cl + cr >> 1;
		push(cv);
		return get(l, r, cv << 1, cl, mid) + get(l, r, cv << 1 | 1, mid + 1, cr);
	}
	int walk_ind(int y, int cv = 1, int cl = 1, int cr = n) {
		if(cl == cr) return mn[cv] <= y ? cl : cl + 1;
		int mid = cl + cr >> 1;
		push(cv);
		if(mn[cv << 1] <= y) return walk_ind(y, cv << 1, cl, mid);
		else return walk_ind(y, cv << 1 | 1, mid + 1, cr);
	}
	int walk(LL y, int cv = 1, int cl = 1, int cr = n) {
		if(cl == cr) return y < sum[cv] ? cl : cl + 1;
		int mid = cl + cr >> 1;
		push(cv);
		if(sum[cv << 1] <= y) return walk(y - sum[cv << 1], cv << 1 | 1, mid + 1, cr);
		else return walk(y, cv << 1, cl, mid);
	}
}tre;

int main()
{
	scanf("%d%d", &n, &q);
	rep1(i, n) scanf("%d", &a[i]);
	tre.build();
	while(q--) {
		int t, x, y;
		scanf("%d%d%d", &t, &x, &y);
		if(t == 1) {
			int ptr = tre.walk_ind(y);
			if(ptr > x) continue;
			tre.modify(y, ptr, x);
		} else {
			int ans = 0;
			while(x <= n && tre.get(n, n) <= y) {
				x = max(x, tre.walk_ind(y));
				if(x == -1 || x > n) break;
				int ptr = tre.walk(y + tre.get(1, x - 1)) - 1;
				y -= tre.get(x, ptr);
				ans += ptr - x + 1;
				x = ptr + 1;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}