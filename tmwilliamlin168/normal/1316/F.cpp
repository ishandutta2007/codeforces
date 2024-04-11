#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5, M=1e9+7, I2=5e8+4;
int n, p[mxN], q, qi[mxN], qx[mxN];
vector<ar<int, 2>> v;
ll pI2[mxN+1];
ar<int, 2> b[mxN];

struct node {
	int c;
	ll ans, sl, sr;
} st[1<<21];

void upd(int l1, int x, int i=1, int l2=0, int r2=v.size()-1) {
	if(l2==r2) {
		st[i].c=x;
		st[i].ans=0;
		st[i].sl=st[i].sr=x?(ll)v[l2][0]*I2%M:0;
		return;
	}
	int m2=(l2+r2)/2;
	if(l1<=m2)
		upd(l1, x, 2*i, l2, m2);
	else
		upd(l1, x, 2*i+1, m2+1, r2);
	st[i].c=st[2*i].c+st[2*i+1].c;
	st[i].ans=(st[2*i].ans+st[2*i+1].ans+st[2*i].sl*st[2*i+1].sr)%M;
	st[i].sl=(st[2*i+1].sl+st[2*i].sl*pI2[st[2*i+1].c])%M;
	st[i].sr=(st[2*i].sr+st[2*i+1].sr*pI2[st[2*i].c])%M;
}

int pv(ar<int, 2> a) {
	return lower_bound(v.begin(), v.end(), a)-v.begin();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	pI2[0]=1;
	for(int i=0; i<n; ++i) {
		pI2[i+1]=pI2[i]*I2%M;
		cin >> p[i];
		v.push_back({p[i], i});
	}
	cin >> q;
	for(int i=0; i<q; ++i) {
		cin >> qi[i] >> qx[i], --qi[i];
		v.push_back({qx[i], -(i+1)});
	}
	sort(v.begin(), v.end());

	for(int i=0; i<n; ++i) {
		b[i]={p[i], i};
		upd(pv(b[i]), 1);
	}
	cout << st[1].ans << "\n";
	for(int i=0; i<q; ++i) {
		upd(pv(b[qi[i]]), 0);
		b[qi[i]]={qx[i], -(i+1)};
		upd(pv(b[qi[i]]), 1);
		cout << st[1].ans << "\n";
	}
}