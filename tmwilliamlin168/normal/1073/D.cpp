#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=2e5;
int n, a[mxN];
ll t, s, ans;
bool r[mxN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> t;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		s+=a[i];
	}
	int nl=n;
	while(nl) {
		ans+=t/s*nl;
		t%=s;
		for(int i=0; i<n; ++i) {
			if(r[i])
				continue;
			if(a[i]>t) {
				r[i]=1;
				s-=a[i];
				--nl;
			} else {
				t-=a[i];
				++ans;
			}
		}
	}
	cout << ans;
}