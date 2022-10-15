#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int mxN=3e5;
int n, a[mxN], b[mxN];
 
struct segtree {
	int a[2*mxN];
	void upd(int i, int x) {
		for(a[i+=n]=x; i/=2; )
			a[i]=min(a[2*i], a[2*i+1]);
	}
	int qry(int l, int r) {
		int b=1e9;
		for(l+=n, r+=n; l<r; ++l/=2, r/=2) {
			if(l&1)
				b=min(a[l], b);
			if(r&1)
				b=min(a[r-1], b);
		}
		return b;
	}
} st;
 
void solve() {
	cin >> n;
	set<ar<int, 2>> s;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		s.insert({a[i], i});
		st.upd(i, a[i]);
	}
	for(int i=0; i<n; ++i)
		cin >> b[i];
	for(int i=0; i<n; ++i) {
		auto it=s.lower_bound({b[i], 0});
		if(it==s.end()||(*it)[0]!=b[i]||st.qry(0, (*it)[1]+1)<b[i]) {
			cout << "NO\n";
			return;
		}
		st.upd((*it)[1], 1e9);
		s.erase(it);
	}
	cout << "YES\n";
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--)
		solve();
}