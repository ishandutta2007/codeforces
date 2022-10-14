#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ar array
const int mxN=2e5;
int a[mxN];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i=0;i<n;++i)
			cin >>a[i];
		sort(a,a+n,greater<>());
		if((n!=1||a[0]==1)&&a[0]-a[1]<=1){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}