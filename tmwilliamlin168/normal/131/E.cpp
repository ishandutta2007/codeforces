#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, m, x[mxN], y[mxN], a1[mxN], a2[9];

void s(vector<ar<int, 3>> v) {
	sort(v.begin(), v.end());
	for(int i=0, j=0; i<m; i=j) {
		for(; j<m&&v[j][0]==v[i][0]; ++j);
		for(int k=i; k<j-1; ++k)
			++a1[v[k][2]];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i=0; i<m; ++i)
		cin >> x[i] >> y[i];
	for(int k=0; k<4; ++k) {
		vector<ar<int, 3>> v1, v2;
		for(int i=0; i<m; ++i) {
			v1.push_back({x[i], y[i], i});
			v2.push_back({x[i]+y[i], x[i]-y[i], i});
		}
		s(v1);
		s(v2);
		for(int i=0; i<m; ++i)
			tie(x[i], y[i])=make_pair(-y[i], x[i]);
	}
	for(int i=0; i<m; ++i)
		++a2[a1[i]];
	for(int i=0; i<9; ++i)
		cout << a2[i] << " ";
}