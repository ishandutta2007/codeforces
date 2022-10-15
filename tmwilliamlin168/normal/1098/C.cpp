#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=1e5;
int n, d[mxN], p[mxN], nc[mxN];
ll s;

bool chk(int x) {
	ll t=(ll)n*(n+1)/2;
	priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
	for(int i=0; i<n; ++i) {
		p[i]=i-1;
		d[i]=i+1;
		nc[i]=i<n-1;
		pq.push({d[i], i});
	}
	int nn=n-1;
	while(t>s) {
		array<int, 2> u=pq.top();
		if(nc[u[1]]>=x) {
			pq.pop();
			continue;
		}
		int cs=d[nn]-u[0]-1;
		if(cs<=0)
			return 0;
		if(t-cs>=s) {
			t-=cs;
			--nc[p[nn]];
			p[nn]=u[1];
			++nc[p[nn]];
			d[nn]=u[0]+1;
			pq.push({d[nn], nn});
			--nn;
			continue;
		}
		while(t>s) {
			p[nn]=p[p[nn]];
			--t;
		}
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> s;
	if(s>(ll)n*(n+1)/2||s<2*n-1) {
		cout << "No";
		return 0;
	}
	cout << "Yes\n";
	if(s==(ll)n*(n+1)/2) {
		for(int i=1; i<n; ++i)
			cout << i << " ";
		return 0;
	}
	int lb=2, rb=n-1;
	while(lb<rb) {
		int mb=(lb+rb)/2;
		if(chk(mb))
			rb=mb;
		else
			lb=mb+1;
	}
	chk(lb);
	for(int i=1; i<n; ++i)
		cout << p[i]+1 << " ";
}