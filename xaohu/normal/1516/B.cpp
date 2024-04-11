#include <bits/stdc++.h>
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,a,b) for (int i = b; i >= a; i--)
 
using namespace std;

int t, n, a[2005];
 
int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		rep(i,1,n) cin>>a[i];
		auto check = [&](int x) {
			int cur = 0, cnt = 0;
			rep(i,1,n) {
				cur ^= a[i];
				if(cur==x) 
					cur = 0, cnt++;
			}
			return cur==0 && cnt>1;
		};
		bool ok = 0;
		int x = 0;
		rep(i,1,n) {
			x ^= a[i];
			ok |= check(x);
		}
		cout << (ok ? "YES\n" : "NO\n");
	}		
	
	return 0;
}