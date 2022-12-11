#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#define int long long

using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

/*int lcd(int a, int b) {
	int g = gcd(a, b);
	return a * b / g;
}*/

const int MAX_N = 1e18;
int n, k;

int get_dist(int x, int y) {
	if (y < x) y += n * k;
	return y - x;
}

signed main() {
	//freopen("Desktop/input.txt", "r", stdin);
	int a, b;
	cin >> n >> k >> a >> b;
	int s1 = a + 1, s2 = n * k - a + 1;
	vector <int> ll;
	for (int i = 0; i < n; i++) {
		int t1 = i * k + 1 + b, t2 = i * k + 1 - b;
		if (i == 0) t2 = n * k - b + 1;
		ll.push_back(get_dist(s1, t1));
		ll.push_back(get_dist(s1, t2));
		ll.push_back(get_dist(s2, t1));
		ll.push_back(get_dist(s2, t2));
	}
	int maxi = -1, mini = MAX_N;
	for (int elem : ll) {
		//cout << elem << endl;
		if (elem == 0) {
			maxi = max(maxi, 1ll);
			mini = min(mini, 1ll);
			continue;
		}
		int now = n * k / gcd(n * k, elem);		
		maxi = max(maxi, now);
		mini = min(mini, now);
	}
	cout << mini << ' ' << maxi << endl;
	return 0;
}