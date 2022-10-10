#include <iostream>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		int sum = 0, nz = 0, nm = 0;
		for(int i = 0, a; i < N; i++) {
			cin >> a;
			if(a == 0) nz++;
			if(a != -1) nm++;
			sum += a;
		}
		if(sum != 0 && nz == 0) cout << "0\n";
		if(sum == 0 && nz == 0) {
			if(nm != 0) cout << "1\n";
			else cout << "2\n";
		}
		if(nz != 0) {
			if(sum != -nz) cout << nz << "\n";
			else cout << nz+1 << "\n";
		}
	}
}