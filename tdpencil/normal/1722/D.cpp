#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vt vector
#define pb push_back
#define ar array

const int mxN=2e5;
int t, c;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<int> changes(n);
		ll score=0;
		for (int i=0;i<n;i++) {
			int cur=0;
			if(s[i]=='L')
				cur=i;
			else if(s[i]=='R')
				cur=(n-i-1);
			int op=0;
			if(s[i]=='L')
				op=(n-i-1);
			else
				op=i;
			changes[i]=op-cur;
			score+=cur;
		}
		sort(changes.rbegin(),changes.rend());
		for(int i=0;i<n;i++) {
			score=max(score,changes[i]+score);
			cout << score << " ";
		}
		cout << "\n";
	}
}