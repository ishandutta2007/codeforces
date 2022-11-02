#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;

int q(int l, int r){
	++l; r = min(r, n);
	cout << "? " << l << " " << r << endl;
	int res; cin >> res;
	return (r - l + 1) - res;
}

vector<int> a;
int sz = 1;

void init(int n){
	while(sz < n) sz += sz;
	a.assign(2*sz, -1);
}

int get(int k, int x, int lx, int rx){
	if(rx-lx==1){
		a[x] = 0;
		return rx;
	}
	int mx = (lx + rx) / 2;
	if(a[2*x+1] < 0) a[2*x+1] = q(lx, mx);
	if(a[2*x+1] >= k){
		int res = get(k, 2*x+1, lx, mx);
		--a[2*x+1];
		return res;
	}
	int res = get(k - a[2*x+1], 2*x+2, mx, rx);
	--a[2*x+2];
	return res;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> n >> t;
	init(n);
	while(t--){
		int k; cin >> k;
		int res = get(k, 0, 0, sz);
		cout << "! " << res << endl;
	}
}