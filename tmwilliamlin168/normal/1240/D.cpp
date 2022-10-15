#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5, mxSTS=19*mxN+1;
int n, a[mxN], nxt[mxN], d[mxN];
int sts, lc[mxSTS], rc[mxSTS], v[mxSTS], rt[mxN];

void upd(int &i, int l1, int x, int l2=0, int r2=n-1) {
	if(!i) {
		i=sts++;
		lc[i]=0;
		rc[i]=0;
	}
	if(l2==r2) {
		v[i]=x;
		return;
	}
	int m2=(l2+r2)/2;
	if(l1<=m2)
		upd(lc[i], l1, x, l2, m2);
	else
		upd(rc[i], l1, x, m2+1, r2);
}

int qry(int i, int l1, int l2=0, int r2=n-1) {
	if(!i)
		return -1;
	if(l2==r2)
		return v[i];
	int m2=(l2+r2)/2;
	if(l1<=m2)
		return qry(lc[i], l1, l2, m2);
	else
		return qry(rc[i], l1, m2+1, r2);
}

void solve() {
	cin >> n;
	ll ans=0;
	sts=1;
	for(int i=0; i<n; ++i) {
		cin >> a[i], --a[i];
		nxt[i]=-1;
		d[i]=0;
		rt[i]=0;
		if(i) {
			/*
		if(i&&a[i-1]==a[i]) {
			nxt[i]=i-2;
			d[i]=(~nxt[i]?d[nxt[i]]:0)+1;
		}
		*/
		/*
		int j=i-1;
		while(~j&&a[j]^a[i]) {
			j=nxt[j];
		}
		if(~j) {
			nxt[i]=j-1;
			d[i]=(~nxt[i]?d[nxt[i]]:0)+1;
		}
		*/
		int b=qry(rt[i-1], a[i]);
		//cout << i << " " << b << endl;
		if(~b) {
			if(b>0) {
				rt[i]=rt[b-1];
				d[i]=d[b-1];
			}
			++d[i];
		}
		}
		upd(rt[i], a[i], i);
		//cout << d[i] << endl;
		ans+=d[i];
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int q ;
	cin >> q;
	while(q--)
		solve();
}