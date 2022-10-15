#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define ull unsigned long long

int solve(vector<int> a, int b) {
	if(b==0) {
		bool same=1;
		for(int i=0; i+1<a.size(); ++i)
			same&=a[i]==a[i+1];
		return !same;
	}
	vector<int> c[2];
	for(int i=0; i<a.size(); ++i)
		c[a[i]>>b&1].push_back(a[i]);
	if(c[0].empty())
		return solve(c[1], b-1);
	if(c[1].empty())
		return solve(c[0], b-1);
	int d1=solve(c[0], b-1), d2=solve(c[1], b-1);
	return 1<<b|min(d1, d2);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> a;
	for(int i=0, b; i<n; ++i) {
		cin >> b;
		a.push_back(b);
	}
	cout << solve(a, 29);
}