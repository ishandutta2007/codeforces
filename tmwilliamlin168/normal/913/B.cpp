#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	int *c1 = new int[n](), *c2 = new int[n](), *p = new int[n];
	for(int i=1; i<n; ++i) {
		cin >> p[i];
		--p[i];
		++c1[p[i]];
	}
	for(int i=0; i<n; ++i)
		if(!c1[i])
			++c2[p[i]];
	for(int i=0; i<n; ++i) {
		if(c1[i]&&c2[i]<3) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
}