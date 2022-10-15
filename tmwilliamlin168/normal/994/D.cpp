#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define fi first
#define se second

pii a[12], b[12];

inline int s1(int i, int j) {
	if(a[i].fi==b[j].fi||a[i].fi==b[j].se)
		return a[i].fi;
	if(a[i].se==b[j].fi||a[i].se==b[j].se)
		return a[i].se;
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; ++i) {
		cin >> a[i].fi >> a[i].se;
		if(a[i].fi>a[i].se)
			swap(a[i].fi, a[i].se);
	}
	for(int i=0; i<m; ++i) {
		cin >> b[i].fi >> b[i].se;
		if(b[i].fi>b[i].se)
			swap(b[i].fi, b[i].se);
	}
	set<int> ps;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			int shd=s1(i, j);
			if(a[i]==b[j]||shd==-1)
				continue;
//			cout << i << " " << j << endl;
			for(int k=0; k<m; ++k) {
				if(a[i]!=b[k]&&k!=j) {
					int shd2=s1(i, k);
					if(shd2!=-1&&shd2!=shd) {
						cout << -1;
						return 0;
					}
				}
			}
			for(int k=0; k<n; ++k) {
				if(b[j]!=a[k]&&k!=i) {
					int shd2=s1(k, j);
					if(shd2!=-1&&shd2!=shd) {
						cout << -1;
						return 0;
					}
				}
			}
			ps.insert(shd);
		}
	}
	if(ps.size()==1)
		cout << *ps.begin();
	else
		cout << 0;
}