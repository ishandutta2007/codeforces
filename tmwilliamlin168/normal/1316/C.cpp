#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6;
int n, m, p, a[mxN], b[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> p;
	int ai=0, bi=0;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	for(int i=0; i<m; ++i)
		cin >> b[i];
	while(a[ai]%p==0)
		++ai;
	while(b[bi]%p==0)
		++bi;
	cout << ai+bi;
}