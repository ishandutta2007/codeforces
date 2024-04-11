#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int T=512;
int n, m, b[T];
array<int, 2> c1[T];
array<int, 3> c2[T];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i=0, f; i<n; ++i) {
		cin >> f;
		int ms=0;
		for(int j=0, bi; j<f; ++j)
			cin >> bi, ms|=1<<bi-1;
		for(int j=0; j<T; ++j)
			if((j&ms)==ms)
				++b[j];
	}
	memset(c1, 0x3f, sizeof(c1));
	memset(c2, 0x7f, sizeof(c2));
	for(int i=0, r, c; i<m; ++i) {
		cin >> c >> r;
		int ms=0;
		for(int j=0, ai; j<r; ++j)
			cin >> ai, ms|=1<<ai-1;
		if(c1[ms][0]<=1e9)
			c2[ms]=min(array<int, 3>{c1[ms][0]+c, c1[ms][1], i}, c2[ms]);
		c1[ms]=min(array<int, 2>{c, i}, c1[ms]);
	}
	for(int i=0; i<T; ++i)
		for(int j=0; j<T; ++j)
			if(i^j&&c1[i][0]<=1e9&&c1[j][0]<=1e9)
				c2[i|j]=min(array<int, 3>{c1[i][0]+c1[j][0], c1[i][1], c1[j][1]}, c2[i|j]);
	int mxb=0;
	for(int i=0; i<T; ++i)
		if(c2[i][0]<=2e9)
			mxb=max(b[i], mxb);
	array<int, 3> ans{(int)2e9+1};
	for(int i=0; i<T; ++i)
		if(b[i]==mxb)
			ans=min(c2[i], ans);//, cout << i << endl;
	cout << ans[1]+1 << " " << ans[2]+1 << "\n";
}