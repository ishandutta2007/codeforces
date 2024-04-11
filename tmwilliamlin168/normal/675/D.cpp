#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, ai, l, r;
	cin >> n;
	set<int> s;
	map<int, int> t;
	t[-1]=-1;
	for(int i=0; i<n; ++i) {
		cin >> ai;
		if(i) {
			auto it=s.lower_bound(ai);
			r=it==s.end()?-1:*it, l=it==s.begin()?-1:*--it;
			if(t[l]>t[r])
				cout << l << " ";
			else
				cout << r << " ";
		}
		s.insert(ai);
		t[ai]=i;
	}
}