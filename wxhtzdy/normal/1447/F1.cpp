#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5, M=105;
int n, a[mxN], cnt[M];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i], ++cnt[a[i]];
	int mx=0;
	for(int i=1; i<M; ++i)
		if(cnt[i]>cnt[mx])
			mx=i;
	bool was=false;
	for(int i=1; i<M; ++i) {
		if(cnt[i]==cnt[mx]) {
			if(was) {
				cout << n << "\n";
				return 0;
			}
			was=true;
		}
	}
	int ans=0;
	for(int i=1; i<M; ++i) {
		if(i==mx)
			continue;
		int bal=mxN+1;
		vector<int> fir(2*mxN+5, mxN+1);
		fir[mxN+1]=-1;
		for(int j=0; j<n; ++j) {
			if(a[j]==mx)
				++bal;
			if(a[j]==i)
				--bal;
			ans=max(ans, j-fir[bal]);
			if(fir[bal]==mxN+1)
				fir[bal]=j;
		}
	}
	cout << ans << "\n";
	return 0;
}