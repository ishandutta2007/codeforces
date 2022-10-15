#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, p[mxN], x, a, y, b, c[mxN];
ll k;

ll chk(int m) {
	ll r=0;
	memset(c, 0, 4*m);
	for(int i=a-1; i<m; i+=a)
		c[i]+=x;
	for(int i=b-1; i<m; i+=b)
		c[i]+=y;
	sort(c, c+m, greater<int>());
	for(int i=0; i<m; ++i)
		r+=p[i]/100*c[i];
	return r;
}

void solve() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> p[i];
	cin >> x >> a >> y >> b;
	cin >> k;
	sort(p, p+n, greater<int>());
	int lb=1, rb=n+1;
	while(lb<rb) {
		int mb=(lb+rb)/2;
		if(chk(mb)<k)
			lb=mb+1;
		else
			rb=mb;
	}
	//cout << chk(1) << endl;
	if(rb>n)
		cout << -1;
	else
		cout << lb;
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int q;
	cin >> q;
	while(q--)
		solve();
}