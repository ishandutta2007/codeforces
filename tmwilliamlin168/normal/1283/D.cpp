#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m;
queue<ar<int, 3>> qu;
vector<int> ans;
set<int> s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<n; ++i) {
		int x;
		cin >> x;
		s.insert(x);
		qu.push({x-1, -1});
		qu.push({x+1, 1});
	}
	ll ans1=0;
	while(m) {
		ar<int, 3> u=qu.front();
		qu.pop();
		if(s.find(u[0])!=s.end())
			continue;
		ans.push_back(u[0]);
		s.insert(u[0]);
		qu.push({u[0]+u[1], u[1], u[2]+1});
		ans1+=u[2]+1;
		--m;
	}
	cout << ans1 << "\n";
	for(int ai : ans)
		cout << ai << " ";
}