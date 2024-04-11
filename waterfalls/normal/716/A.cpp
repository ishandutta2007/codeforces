#include <iostream>
using namespace std;

int main() {
	int n,lifetime;
	cin >> n >> lifetime;
	int ans = 0;
	int prev = 0;
	for (int i=0;i<n;i++) {
		int t;
		cin >> t;
		if (t-prev>lifetime) ans = 0;
		ans+=1;
		prev = t;
	}
	cout << ans << endl;

	return 0;
}