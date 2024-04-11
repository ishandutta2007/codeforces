#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

vector<int> adj[100000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	while(m--) {
		int a, b;
		cin >> a >> b, --a, --b;
		adj[a].push_back((b-a+n)%n);
		adj[b].push_back((a-b+n)%n);
	}
	for(int i=0; i<n; ++i)
		sort(adj[i].begin(), adj[i].end());
	int n2=n;
	for(int p=2; p<=min(n2, n); ++p) {
		if(n2%p)
			continue;
		int b=n/p;
		bool ok=1;
		for(int i=0; i<b; ++i) {
			for(int j=i+b; j<n&&ok; j+=b) {
				ok=adj[i]==adj[j];
			}
		}
		if(ok) {
			cout << "Yes";
			return 0;
		}
		while(n2%p==0)
			n2/=p;
	}
	cout << "No";
}