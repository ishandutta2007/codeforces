#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, m, t[mxN], ans, q[mxN];
array<int, 2> p[mxN], ft[mxN+1];

array<int, 2> operator+(const array<int, 2> &a, const array<int, 2> &b) {
	return {a[0]+b[0], a[1]+b[1]};
}

void upd(int i, array<int, 2> x) {
	for(++i; i<=n; i+=i&-i)
		ft[i]=ft[i]+x;
}

int qry(int mx) {
	int x=0;
	array<int, 2> r{};
	for(int i=17; ~i; --i) {
		if(x+(1<<i)<=n&&(r+ft[x+(1<<i)])[0]<=mx) {
			x+=1<<i;
			r=r+ft[x];
		}
	}
	return r[1];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i=0; i<n; ++i) {
		cin >> t[i];
		p[i]={t[i], i};
	}
	sort(p, p+n);
	for(int i=0; i<n; ++i)
		q[p[i][1]]=i;
	for(int i=0; i<n; ++i) {
		cout << i-qry(m-t[i]) << "\n";
		upd(q[i], {t[i], 1});
	}
}