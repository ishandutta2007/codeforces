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

int n, k;
pii a[mxN];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		cin >> n >> k;
		for(int i=0;i<n;i++) {
			cin >> a[i].first;
		}
		for(int i=0;i<n;i++) {
			cin >> a[i].second;
		}
		sort(a,a+n);
		for(int i=0;i<n;i++) {
			if(a[i].first<=k) {
				k+=a[i].second;
			}
		}
		cout << k << "\n";
	}
}