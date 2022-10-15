#include <bits/stdc++.h>
using namespace std;

const int mxN=2000;
int n, m, a[mxN][mxN], b[mxN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<n; ++i) {
		string s;
		cin >> s;
		for(int j=0; j<m; ++j)
			a[i][j]=s[j]-'0', b[j]+=a[i][j];
	}
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j)
			b[j]-=a[i][j];
		bool ok=1;
		for(int j=0; j<m&&ok; ++j)
			ok=b[j];
		if(ok) {
			cout << "YES";
			return 0;
		}
		for(int j=0; j<m; ++j)
			b[j]+=a[i][j];
	}
	cout << "NO";
}