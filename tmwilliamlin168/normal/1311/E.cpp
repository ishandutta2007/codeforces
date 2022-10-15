#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=5e3;
int n, d, nc[mxN], p[mxN];
vector<int> w[mxN];

void solve() {
	cin >> n >> d;
	if(d>n*(n-1)/2) {
		cout << "NO\n";
		return;
	}
	int s=n*(n-1)/2;
	for(int i=0; i<n; ++i) {
		nc[i]=1;
		p[i]=i-1;
		w[i]={i};
	}
	int u=n-1;
	while(s>d) {
		nc[u]=0;
		int a=0;
		while(a+1<u&&!w[a].size())
			++a;
		if(a+1==u)
			break;
		if(s-d<u-a-1) {
			p[u]=u-1-(s-d);
			s=d;
			break;
		}
		int v=w[a].back();
		p[u]=v;
		++nc[v];
		if(nc[v]>=2)
			w[a].pop_back();
		s-=u-a-1;
		//cout << u << " " << v << endl;
		//cout << s << endl;
		w[a+1].push_back(u);
		--u;
	}
	if(s>d) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for(int i=1; i<n; ++i)
		cout << p[i]+1 << " \n"[i==n-1];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
}