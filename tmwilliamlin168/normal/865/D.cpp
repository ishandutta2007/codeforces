#include <bits/stdc++.h>
using namespace std;

int p[300000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> p[i];
	long long t=0;
	priority_queue<int, vector<int>, greater<int>> matched, unmatched;
	matched.push(69696969);
	unmatched.push(69696969);
	unmatched.push(p[0]);
	for(int i=1; i<n; ++i) {
		if(matched.top()<p[i]&&matched.top()<=unmatched.top()) {
			t+=p[i]-matched.top();
			unmatched.push(matched.top());
			matched.pop();
			matched.push(p[i]);
		} else if(unmatched.top()<p[i]) {
			t+=p[i]-unmatched.top();
			unmatched.pop();
			matched.push(p[i]);
		} else
			unmatched.push(p[i]);
	}
	cout << t;
}