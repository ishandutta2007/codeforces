#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, p2;
	cin >> n >> m;
	p2=1;
	while(n--) {
		if(p2>m) {
			cout << m;
			return 0;
		}
		p2*=2;
	}
	cout << m%p2;
}