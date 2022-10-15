#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int q, n;
ar<int, 2> c[mxN];

void solve() {
	cin >> n;
	for(int i=0; i<n; ++i) {
		int a, f;
		cin >> a >> f;
		++c[a-1][0];
		c[a-1][1]+=f;
	}
	sort(c, c+n);
	int ans1=0, ans2=0, nxt=n, j=n-1;
	priority_queue<int> pq;
	while(nxt) {
		while(~j&&c[j][0]>=nxt) {
			pq.push(c[j][1]);
			--j;
		}
		if(pq.size()) {
			ans1+=nxt;
			ans2+=min(nxt, pq.top());
			pq.pop();
		}
		--nxt;
	}
	cout << ans1 << " " << ans2 << "\n";
	memset(c, 0, sizeof(c[0])*n);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> q;
	while(q--)
		solve();
}