#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vt vector
#define pb push_back
#define ar array

const int mxN=2e5;
void solve() {
	map<string, int> o;
	int n;
	cin >> n;
	vector<string> s(n);
	for (auto &u: s)
		cin >> u, o[u]++;
	for(int i=0;i<n;i++) {
		bool w=0;
		for (int j=0;j<s[i].size();j++) {
			string a=s[i].substr(0,j+1),b=s[i].substr(j+1);
			if(o[a]&&o[b]) {
				w=1;
			}
		}
		cout << (w?"1":"0");
	}
	cout << "\n";
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
  	
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}