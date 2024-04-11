#include <bits/stdc++.h>

#define ar array
#define ll long long
#define pb push_back

using namespace std;
constexpr int mxN=1e4;
int n, m;
int a[mxN], b[mxN];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];
	if(count(a,a+n,1) != 0 || count(b,b+n,1)!=0) {
		cout << -1 << '\n';
		return 0;
	}
	double lb = 1, rb = 1e9;
	double eps = 1e-6;
	while(rb - lb > eps) {
		double mb = (lb + rb) / 2;
		double o = (lb + rb) / 2;
		double used=0;
		bool good=1;
		for(int i =0 ; i < n; i++) {
			mb -= (mb+m)/a[i];
			if(mb<0)
				good=0;
			mb -= (mb+m)/b[(i+1)%n];
			if(mb<0)
				good=0;
		}
		if(good)
			rb=o;
		else
			lb=o;
	}
	cout << fixed << setprecision(15) << lb;
	
}