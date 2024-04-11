#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6;
int n, x, a[mxN], b[mxN], c[mxN];
vector<int> v[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> x;
	for(int i=0; i<n; ++i)
		cin >> a[i], --a[i], v[a[i]].push_back(i);
	int j=0, r=-1;
	while(j<x) {
		c[j]=r;
		if(v[j].size()) {
			if(v[j][0]>r)
				r=v[j].back();
			else
				r=n;
		}
		++j;
	}
	int k=x-1, l=n;
	while(~k) {
		b[k]=l;
		if(v[k].size()) {
			if(v[k].back()<l)
				l=v[k][0];
			else
				l=-1;
		}
		--k;
	}
	ll ans=0;
	for(int i=0, j=0; i<x; ++i) {
		//cout << c[i] << endl;
		//cout << b[i] << endl;
		while(j<x&&(i>j||c[i]>=b[j]))
			++j;
		ans+=x-j;
		//cout << ans << endl;
	}
	cout << ans;
}