#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, k, a[200000];
	cin >> n >> m >> k;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	int lb=1, rb=n;
	while(lb<=rb) {
		int mb=(lb+rb)/2, u=1;
		for(int i=n-mb, s=0; i<n; ++i) {
			if(s+a[i]>k) {
				++u;
				s=0;
			}
			s+=a[i];
		}
		if(u<=m)
			lb=mb+1;
		else
			rb=mb-1;
	}
	cout << rb;
}