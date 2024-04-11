#include <iostream>
using namespace std;

int main() {
	int N, B, D;
	cin >> N >> B >> D;
	int ans = 0;
	for(int i = 0, w = 0; i < N; i++) {
		int a;
		cin >> a;
		if(a > B) continue;
		w += a;
		if(w > D) ans++, w = 0;
	}
	cout << ans << "\n";
}