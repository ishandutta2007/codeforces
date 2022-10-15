#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool adj[1000][1000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, a, b;
	cin >> n >> a >> b;
	if(a!=1&&b!=1||(n==2||n==3)&&a==1&&b==1) {
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	bool flp=0;
	if(a==1) {
		swap(a, b);
		flp=1;
	}
	for(int i=0; i<n-a; ++i)
		adj[i][i+1]=adj[i+1][i]=1;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j)
			cout << (adj[i][j]^(flp&&i!=j));
		cout << "\n";
	}
}