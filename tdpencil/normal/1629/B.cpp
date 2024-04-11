#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define rep(i,x,V) for(int i=x;i<V;i++)
#define all(A) begin(A), end(A)
#define sz(X) int(X.size())
#define pii pair<int, int>
const int mxN=2e5;
int l, r, x;
int cnt2(int x) {
	return x / 2;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		cin >> l >> r >> x;
		if(l==r) {
			cout << (l==1?"NO":"YES") << "\n";
		} else {
			int a=cnt2(r)-cnt2(l-1);
			if((r-l+1)-a>x) 
				cout << "NO\n";
			else
				cout << "YES\n";
		}
	}
}