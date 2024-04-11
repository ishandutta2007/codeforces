#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int a[3] = {-1, -1, -1};
	for(int i = 0; i < N; i++) {
		int b;
		cin >> b;
		for(int j = 0; j <= 3; j++) {
			if(j == 3) {
				cout << "NO\n";
				return 0;
			}
			if(a[j] != -1 && a[j] != b) continue;
			a[j] = b;
			break;
		}
	}
	if(a[2] == -1) {
		cout << "YES\n";
		return 0;
	}
	if(a[1]-a[0] == a[0]-a[2] || a[1]-a[0] == 2*(a[2]-a[0]) || a[2]-a[0] == 2*(a[1]-a[0])) cout << "YES\n";
	else cout << "NO\n";
}