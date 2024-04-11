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
		string s;
		cin >> s;
		vector<int> a;
		int l=0;
		for(char c : s) {
			if(c&1) {
				++l;
			} else {
				a.push_back(l);
				l=0;
			}
		}
		a.push_back(l);
		sort(a.begin(), a.end());
		int t=0;
		for(int i=a.size()-1; i>=0; i-=2)
			t+=a[i];
		cout << t << "\n";
	}
}