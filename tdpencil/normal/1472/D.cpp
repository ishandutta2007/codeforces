#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(x) (int(x.size()))
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i=0; i < n; i++) cin >> a[i];
		priority_queue<int> q;
		
		for(int i=0; i < n; i++) q.push(a[i]);
		
		ll fs = 0, sc= 0;
		int turns = 1;
		while(q.size()) {
			int t = q.top();
			q.pop();
			if(turns & 1) {
				if(t % 2 == 0) {
					fs += t;
				} else {
					fs += 0;
				}
			}
			else {
				if(t % 2 == 1) {
					sc += t;
				} else {
					sc += 0;
				}
			}
			turns++;
		}
		
		if(fs > sc) {
			cout << "Alice\n";
		} else if(fs == sc) {
			cout << "Tie\n";
		} else {
			cout << "Bob\n";
		}
	}
	
}