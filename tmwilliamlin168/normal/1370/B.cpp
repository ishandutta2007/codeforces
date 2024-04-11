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
		int n;
		cin >> n;
		vector<int> v[2];
		for(int i=0; i<2*n; ++i) {
			int a;
			cin >> a;
			v[a&1].push_back(i);
		}
		int k=0;
		for(int i=0; i+1<v[0].size()&&k<n-1; i+=2, ++k)
			cout << v[0][i]+1 << " " << v[0][i+1]+1 << "\n";
		for(int i=0; i+1<v[1].size()&&k<n-1; i+=2, ++k)
			cout << v[1][i]+1 << " " << v[1][i+1]+1 << "\n";
	}
}