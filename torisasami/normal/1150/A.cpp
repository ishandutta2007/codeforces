#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, m, i, ans, p, min = 100000, max = -1;
	cin >> n >> m >> ans;
	for (i = 0; i < n; i++) {
		cin >> p;
		if (p < min)
			min = p;
	}
	for (i = 0; i < m; i++) {
		cin >> p;
		if (p >max)
			max = p;
	}
	if (max > min) 
		ans += (max - min)*(ans / min);
	cout << ans << endl;
}