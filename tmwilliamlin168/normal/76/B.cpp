#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

#define F_OR(i, a, b, s) for (int i = (a); ((s) > 0 ? i < (b) : i > (b)); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, y0, y1;
	cin >> n >> m >> y0 >> y1;
	vector<int> a(n);
	vector<int> b(m);
	FOR(n)
		cin >> a[i];
	FOR(m)
		cin >> b[i];
	b.insert(b.begin(), (int)-1e9);
	b.push_back(1e9);
	vector<int> c(m+2, -1);
	int ans=0;
	/*
	for(int i=0, j=0; i<n; ++i) {
		while(j+1<m&&abs(b[j+1]-a[i])<abs(b[j]-a[i]))
			++j;
		if(j>=m)
			break;
		if(!c[j]) {
		++ans;
		c[j]=1;
		}
		else if(!c[j+1]&&j+1<m&&abs(b[j+1]-a[i])==abs(b[j]-a[i])) {
			++ans;
			c[j+1]=1;
		}
		cout << ans << endl;
	}
	*/
	for(int i=1; i<=m; ++i) {
		int p=lower_bound(a.begin(), a.end(), b[i])-a.begin();
		if(p<sz(a)&&a[p]==b[i]) {
			++ans;
			c[i]=0;
		}
	}
	int l=0;
	FOR(m+1) {
		while(l<n&&a[l]<=b[i])
			++l;
		int r=l;
		while(r<n&&a[r]<b[i+1])
			++r;
		//cout << l << " " << r << endl;
		if(l<r) {
			//if(2*a[l]==b[i]+b[i+1]&&(c[i]<0||c[i]==b[i]-a[l])) {
				//c[i]=b[i]-a[l];
				//++ans;
			//}
			if(l+1==r) {
				if(2*a[l]==b[i]+b[i+1]) {
					if(c[i]<0||c[i]==a[l]-b[i]) {
						c[i]=a[l]-b[i];
						++ans;
					} else if(c[i+1]<0) {
						c[i+1]=b[i+1]-a[l];
						++ans;
					}
				} else if(2*a[l]<b[i]+b[i+1]) {
					if(c[i]<0||c[i]==a[l]-b[i]) {
						c[i]=a[l]-b[i];
						++ans;
					}
				} else {
					if(c[i+1]<0) {
						c[i+1]=b[i+1]-a[l];
						++ans;
					}
				}
			} else {
				if(2*a[l]<=b[i]+b[i+1]&&(c[i]<0||c[i]==a[l]-b[i])) {
					c[i]=a[l]-b[i];
					++ans;
				}
				//cout << c[i+1] << endl;
				if(2*a[r-1]>=b[i]+b[i+1]&&(c[i+1]<0)) {
					c[i+1]=b[i+1]-a[r-1];
					++ans;
				}
			}
		}
		//cout << ans << endl;
	}
	cout << n-ans;
}