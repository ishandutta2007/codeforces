#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=5e5;
int n, ans[mxN+1], c[mxN+1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int c2=0;
	fill(ans+1, ans+n+1, n);
	for(int i=n; i; --i) {
		++c2;
		c[i]=1;
		for(int j=i; (j+=i)<=n; ) {
			if(c[j]) {
				c[j]=0;
				--c2;
			}
		}
		//cout << c2 << " ";
		ans[c2+i-1]=min(i-1, ans[c2+i-1]);
	}
	for(int i=n; i; --i)
		//cout << ans[i] << endl, 
		ans[i-1]=min(ans[i], ans[i-1]);
	for(int i=2; i<=n; ++i) {
		cout << ans[i] << " ";
	}
}