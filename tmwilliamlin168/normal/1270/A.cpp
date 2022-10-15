#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--) {
		int n, k1, k2;
		cin >> n >> k1 >> k2;
		int mxa=0, mxb=0;
		for(int i=0; i<k1; ++i) {
			int a;
			cin >> a;
			mxa=max(a, mxa);
		}
		for(int i=0; i<k2; ++i) {
			int a;
			cin >> a;
			mxb=max(a, mxb);
		}
		cout << (mxa>mxb?"YES":"NO") << "\n";
	}
}