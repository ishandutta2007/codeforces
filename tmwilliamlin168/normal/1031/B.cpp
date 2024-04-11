#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5;
int n, a[mxN-1], b[mxN-1], ans[mxN];
bool cn[mxN][4];

void rec(int i, int j) {
	ans[i]=j;
	if(!i)
		return;
	for(int k=0; k<4; ++k) {
		if(cn[i-1][k]&&(k|j)==a[i-1]&&(k&j)==b[i-1]) {
			rec(i-1, k);
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n-1; ++i)
		cin >> a[i];
	for(int i=0; i<n-1; ++i)
		cin >> b[i];
	for(int i=0; i<4; ++i)
		cn[0][i]=1;
	for(int i=1; i<n; ++i)
		for(int j=0; j<4; ++j)
			for(int k=0; k<4; ++k)
				cn[i][j]|=cn[i-1][k]&&(k|j)==a[i-1]&&(k&j)==b[i-1];
	for(int i=0; i<4; ++i) {
		if(!cn[n-1][i])
			continue;
		cout << "YES\n";
		rec(n-1, i);
		for(int i=0; i<n; ++i)
			cout << ans[i] << " ";
		return 0;
	}
	cout << "NO";
}