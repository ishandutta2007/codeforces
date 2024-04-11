#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n;
array<int, 2> b[mxN];

void test(int x) {
	vector<int> v;
	for(int i=0; i<n; ++i)
		if(i^x)
			v.push_back(b[i][0]);
	if(v.size()<2) {
		cout << b[x][1]+1;
		exit(0);
	}
	ll d=v[1]-v[0], s=v[1]+d;
	for(int i=2; i<v.size(); ++i, s+=d) {
		if(v[i]^s) {
			return;
		}
	}
	cout << b[x][1]+1;
	exit(0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> b[i][0];
		b[i][1]=i;
	}
	sort(b, b+n);
	test(0);
	test(1);
	ll cs=2*b[1][0]-b[0][0];
	int i=2;
	while(i<n&&b[i][0]==cs) {
		++i;
		cs+=b[1][0]-b[0][0];
	}
	if(i<n)
		test(i);
	cout << -1;
}