#include <bits/stdc++.h>
using namespace std;

const int mxN=100;
int a[mxN], b[mxN];
bool h[mxN][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int x;
	cin >> x;
	for(int i=0; i<x; ++i)
		cin >> a[i], h[a[i]][0]=true;
	int y;
	cin >> y;
	for(int i=0; i<y; ++i)
		cin >> b[i], h[b[i]][1]=true;
	for(int i=0; i<1e5; ++i)
		if(h[i%n][0]||h[i%m][1])
			h[i%n][0]=h[i%m][1]=true;
	bool ok=true;
	for(int i=0; i<n; ++i)
		ok&=h[i][0];
	for(int i=0; i<m; ++i)
		ok&=h[i][1];
	cout << (ok?"Yes":"No");
	return 0;		
}