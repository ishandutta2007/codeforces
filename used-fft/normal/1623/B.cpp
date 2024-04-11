#include <bits/stdc++.h>
using namespace std;
#define int long long

const int LIM = 1000;

int n;
vector<array<int, 3>> res;

void solve(int l, int r, vector<array<int, 2>> a){
	if(empty(a)) return;
	if(size(a) == 1){
		res.push_back({l, l, l});
		return;
	}

	int i1;
	int x, y, z;
	int oh = -1;
	map<int, int> cnt;
	for(int i=0; i<(int)size(a); ++i){
		int len = a[i][1] - a[i][0] + 1;

		if(len == r - l + 1) i1 = i;

		if(len == r - l){
			oh = i;
		}

		if(a[i][0] == l) cnt[len] = i+1;
	}
	for(int i=0; i<(int)size(a); ++i){
		int len = a[i][1] - a[i][0] + 1;

		if(a[i][1] == r && cnt[r - l + 1 - len - 1]){
			x = cnt[r - l + 1 - len - 1]-1;
			y = i;
		}
	}


	if(oh >= 0){
		z = l == a[oh][0] ? r : l;
	}else
		z = max(a[x][0] - 1, a[y][0] - 1);

	res.push_back({a[i1][0], a[i1][1], z});

	// cout << l << ' ' << r << ' ' << z << ' ' << oh << endl;

	vector<array<int, 2>> L, R;
	for(auto &[p, q] : a){
		if(q < z) L.push_back({p, q});
		if(p > z) R.push_back({p, q});
	}

	solve(l, z-1, L);
	solve(z+1, r, R);
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while(T--){
		cin >> n;

		vector<array<int, 2>> a(n);
		res.clear();
		for(int i=0; i<n; ++i){
			cin >> a[i][0] >> a[i][1];
		}

		solve(1, n, a);
		for(auto &i : res)
			cout << i[0] << ' ' << i[1] << ' ' << i[2] << '\n';
		cout << '\n';
	}
}