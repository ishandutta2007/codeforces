#include <bits/stdc++.h>
using namespace std;

#define maxn 500010

int Max[1<<20], Min[1<<20], setv[1<<20];
long long cnt[1<<20];
int ql, qr, val;
vector< pair<int, int> > v[maxn];

void maintain(int o) {
	Max[o] = max(Max[o * 2], Max[o * 2 + 1]);
	Min[o] = min(Min[o * 2], Min[o * 2 + 1]);
	cnt[o] = cnt[o * 2] + cnt[o * 2 + 1];
}

void pushdown(int l, int r, int o) {
	int lc = o * 2, rc = o * 2 + 1;
	int mid = l + (r - l) / 2;
	if(setv[o]) {
		Max[lc] = Min[lc] = setv[o];
		Max[rc] = Min[rc] = setv[o];
		setv[lc] = setv[rc] = setv[o];
		cnt[lc] = (long long)(mid - l + 1) * setv[o];
		cnt[rc] = (long long)(r - mid) * setv[o];
		setv[o] = 0; 
	} 
}

void update(int l, int r, int o) {
	if(ql <= l && qr >= r && Max[o] < val) {
		Max[o] = Min[o] = val;
		setv[o] = val;
		cnt[o] = (long long)(r - l + 1) * val;
		return;
	}
	
	if(Min[o] >= val) return;
	pushdown(l, r, o);
	int mid = l + (r - l) / 2;
	if(ql <= mid) update(l, mid, o * 2);
	if(qr > mid) update(mid + 1, r, o * 2 + 1);
	maintain(o);
}

int main() {
	int n, a, b, c;
	scanf("%d%d%d%d", &n, &a, &b, &c);
	
	
	for(int i = 1; i <= n; i++) {
		int ai, bi, ci;
		scanf("%d%d%d", &ai, &bi, &ci);
		v[a].push_back(make_pair(bi, ci));
		v[ai].push_back(make_pair(bi, c));
		v[ai].push_back(make_pair(b, ci));			
	}
	
	long long ans = (long long)a * b * c;
	for(int i = a; i >= 1; i--) {
		for(int j = 0; j < v[i].size(); j++) {
			ql = 1, qr = v[i][j].first;
			val = v[i][j].second;
			update(1, b, 1);
		}
		
		ans -= cnt[1];
	}
	
	cout << ans << endl;
	return 0;
}