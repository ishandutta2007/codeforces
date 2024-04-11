#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, a, b;
	cin >> n >> a >> b;
	for(int x=min(a, b); x>=1; --x) {
		bool ok=a/x+b/x>=n;
		if(ok) {
			cout << x;
			break;
		}
	}
}