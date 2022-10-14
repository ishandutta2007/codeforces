#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false),cin.tie(nullptr);

	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		int k = 1;
		while(n > 0) {
			n-=k;
			k++;
		}

		if(n==-1) {
			cout << k << '\n';
		} else {
			cout << k-1 << '\n';
		}
	}
}