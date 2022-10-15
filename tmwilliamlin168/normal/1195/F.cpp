#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5, mxM=3e5;
int n, s[mxN+1], q, l[mxN], r[mxN], ans[mxN], ft[mxM+1];
vector<int> ta[mxM];
ar<int, 2> a[mxM];
map<ar<int, 2>, int> mp;

void upd(int i, int x) {
	for(++i; i<=s[n]; i+=i&-i)
		ft[i]+=x;
}

int qry(int i) {
	int r=0;
	for(; i; i-=i&-i)
		r+=ft[i];
	return r;
}

ar<int, 2> no(ar<int, 2> a) {
	//cout << a[0] << " " << a[1] << endl;
	int g=abs(__gcd(a[0], a[1]));
	return {a[0]/g, a[1]/g};
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0, k; i<n; ++i) {
		cin >> k;
		s[i+1]=s[i]+k;
		vector<int> x(k), y(k);
		for(int j=0; j<k; ++j) {
			cin >> x[j] >> y[j];
		}
		for(int j=0; j<k; ++j)
			a[s[i]+j]=no({x[(j+1)%k]-x[j], y[(j+1)%k]-y[j]});
	}
	cin >> q;
	for(int i=0, li, ri; i<q; ++i) {
		cin >> li >> ri;
		l[i]=s[li-1];
		r[i]=s[ri]-1;
		//cout << l[i] << " " << r[i] << endl;
		ta[r[i]].push_back(i);
	}
	for(int i=0; i<s[n]; ++i) {
		//cout << i << " " << a[i][0] << " " << a[i][1] << endl;
		int p=mp.find(a[i])==mp.end()?-1:mp[a[i]];
		mp[a[i]]=i;
		upd(i, 1);
		if(~p)
			upd(p, -1);
		//cout << p << endl;
		for(int j : ta[i]) {
			//cout << j << " " << l[j] << " " << r[j] << endl;
			ans[j]=qry(s[n])-qry(l[j]);
		}
	}
	for(int i=0; i<q; ++i)
		cout << ans[i] << "\n";
}