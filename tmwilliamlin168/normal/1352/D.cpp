#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, a[mxN];

void solve() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	int m=0, s1=0, s2=0, le=0;
	for(int l=0, r=n-1; l<=r; ) {
		if(m&1^1) {
			int cs=0;
			while(l<=r&&cs<=le) {
				cs+=a[l++];
			}
			s1+=cs;
			le=cs;
		} else {
			int cs=0;
			while(l<=r&&cs<=le) {
				cs+=a[r--];
			}
			s2+=cs;
			le=cs;
		}
		++m;
	}
	cout << m << " " << s1 << " " << s2 << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}