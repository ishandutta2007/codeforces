#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		if(N < 4) cout << 4-N << "\n";
		else cout << N%2 << "\n";
	}
}