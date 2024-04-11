#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2500;
int n, x[mxN], y[mxN];

long double val(ar<int, 2> a) {
	long double p=(long double)a[0]/(abs(a[0])+abs(a[1]));
	if(a[1]<0)
		return p-1;
	return 1-p;
}

int q(ar<int, 2> a) {
	if(a[1]>=0&&a[0]>0)
		return 1;
	if(a[1]>0)
		return 2;
	if(a[0]<0)
		return 3;
	return 4;
}

bool cmp(ar<int, 2> a, ar<int, 2> b) {
	//if(atan2(a[1], a[0])<atan
	//return val(a)<val(b);
	//return atan2(a[1], a[0])<atan2(b[1], b[0]);
	if(q(a)<q(b))
		return 1;
	if(q(b)<q(a))
		return 0;
	return (ll)a[1]*b[0]<(ll)b[1]*a[0];
}

ll solve(int a) {
	int cx=x[a], cy=y[a];
	vector<ar<int, 2>> v;
	for(int i=0; i<n; ++i) {
		if(i^a) {
			v.push_back({x[i]-x[a], y[i]-y[a]});
		}
	}
	sort(v.begin(), v.end(), cmp);
	int vs=v.size();
	for(int i=0; i<vs; ++i)
		v.push_back(v[i]);
	ll ans=0;
	//cout << "a " << a << endl;
	for(int i=0, j=0; i<vs; ++i) {
		j=max(j, i);
		while(j+1<i+vs&&(ll)v[i][1]*(v[j+1][0]-v[i][0])<(ll)(v[j+1][1]-v[i][1])*v[i][0])
			++j;
		ans+=(ll)(j-i)*(j-i-1);
		//cout << v[i][0] << " " << v[i][1] << " " << ans << endl;
	}
	ans=(ll)(n-1)*(n-2)*(n-3)/3-ans;
	//cout << (ll)(n-1)*(n-2)*(n-3)/3 << endl;
	//cout << a << " " << ans << endl;
	//cout << a << " " << ans/2 << endl;
	//assert(ans%2==0);
	return ans/2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> x[i] >> y[i];
	}
	ll ans=0;
	//solve(0);
	//return 0;
	for(int i=0; i<n; ++i) {
		ans+=solve(i);
		//break;
	}
	cout << ans*(n-4)/2;
}