#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	for(int i = 0, x = 0; i < N; i++) {
		int a;
		cin >> a;
		if(a%2 == 0) cout << a/2 << "\n";
		else {
			int r = (a > 0) ? (a/2) : (a/2-1);
			if(x) cout << r << "\n";
			else cout << r+1 << "\n";
			x = 1-x;
		}
	}
}